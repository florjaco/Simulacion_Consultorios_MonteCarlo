//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Main.h"

#include "Math.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

//random number generator
#define IA 16807
#define IM 2147483647
#define AM (1.0/IM)
#define IQ 127773
#define IR 2836
#define MASK 123459876




TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
        randomize();//para que cuando llame a rand no use siempre la misma semilla
        ListaPac= new TList;  //me creo una TList en la que guardo nodos de tipo paciente
        t_acum=0;
        t_acum_tot=0;
        NPACxhora=0;
        NATENDIDOS=0;

        for(int i=0;i<24;i++)
        {
                tiempos[i]=0;
        }


}
//---------------------------------------------------------------------------
void __fastcall TForm1::SimularClick(TObject *Sender)
{
        parar=true;  //habilito que se pueda parar la simulacion
        
        NumConsultorios=Edit1->Text.ToDouble(); //numero de consultorios
        //t=(23-8)*60;
        t=0;  //tiempo parametrico (en minutos)
        tp=t; //tp es el tiempo anterior
        NOCUP=0;//cero consultorios ocupados
        NPAC=0;//todavia no atendi a ningun paciente
        NPACxhora=0;//nro de pac atendidos en esa hora
        NATENDIDOS=0;
        NTOT=0;
        t_acum=0;//todavia no acumule ningun tiempo de espera
        t_acum_tot=0;

        if(ListaPac->Count!=0)    //si quiero simular nuevamente vacio la lista
        {
                ListaPac->Clear(); //vacio la lista
        }

        for(int i=0;i<24;i++)tiempos[i]=0;

        //genero t1, tiempo que tarda en llegar el primer paciente a la guardia
        t1=gausseana(2.0,1.0);// el primero entra a las 8:00 hs

        Display->Clear(); //vacio el display

        Chart1->Series[0]->Clear();  //borro el grafico
        
        Timer1->Enabled=true;//

}
//---------------------------------------------------------------------------
float TForm1::ran0(long * idum)
{
        /*"Minimal "random num er generator of Park and Miller.Returns a uniform random deviate
etween 0.0 and 1.0.Set or reset idum to any integer value (except the unlikely value MASK
to initialize the sequence;idum must not be altered between calls for successive deviates in
a sequence.*/
  	long k;
	float ans;
	*idum ^= MASK;
	k=(*idum)/IQ	;
	*idum=IA*(*idum-k*IQ)-IR*k;
	if(*idum<0) *idum += IM;
	ans=AM*(*idum);
	*idum ^= MASK;
	return ans;
}
//---------------------------------------------------------------------------
double TForm1::gausseana(float media, float SD /*desvio stantard*/)
{//Llena el array con una gausseana de media 0.0 y desvio 1.0

	long seed=rand();
        float aux=-(1.0)*log( 1-ran0(&seed) ) *cos(2*M_PI*ran0(&seed));  //valor gaussiano con media 0 y desvio estandar 1
        aux=aux*SD+media; //desnormalizo el valor gaussiano para que tenga valor medio "media" y desvio estandar SD  //wiki distribucion normal
        if(aux<0) aux=0;
        return aux;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
        //aca tengo que llamar a actualizar cada 1 segundo
        actualizar();
        t++;
        Edit2->Text=AnsiString(t);
        Edit3->Text=AnsiString((int)(t/60));

        if(t>24*60)
        {
                Timer1->Enabled=false; //Si pasaron 24 horas, desactivo el timer
                for(int i=0;i<24;i++)
                {
                        Chart1->Series[0]->AddXY(i,tiempos[i]);
                }
        }
        int c=(int)t%60; //si es un multiplo de 60
        int i=(int)((t+8*60)/60); //calculo la cant de horas que pasaron
        if(i>24){i=i%24;} //si me paso de 24
        if(c==0)//para cada hora
        {
                tiempos[i-1]=t_acum/NPACxhora; //me guardo el tiempo medio de espera para cada hora (t de espera acumulado dividido numero de pac atendidos en esa hora)
                t_acum=0;
                NPACxhora=0;
                Chart1->Series[0]->Clear();
                Edit4->Text=AnsiString((int)(t_acum_tot/NATENDIDOS));
                for(int i=0;i<24;i++) //voy graficando la evolucion del tiempo medio de espera
                {
                        Chart1->Series[0]->AddXY(i,tiempos[i]);
                }
        }

        //calculo la hora del dia para poner en el reloj
        Edit5->Text=AnsiString(i);
        int min=(int)(t+8*60)%60;
        Edit6->Text=AnsiString(min);
        Edit7->Text=AnsiString(NATENDIDOS);
        Edit8->Text=AnsiString(NPAC);
        if(NPAC!=0) {Edit9->Text=AnsiString(int(NATENDIDOS*100/NTOT));}
        Edit10->Text=AnsiString(NTOT);

}
//---------------------------------------------------------------------------
void TForm1::actualizar()
{
        float hora;
        int a=t-tp; //cuanto tiempo paso desde el inicio del tiempo parametrico
        int b=t1;
        if(a==b)//si es un multiplo del tiempo en el que entro el primer paciente (voy actualizando cada un minuto)
        {
                NPAC++;//llega un paciente
                NTOT++;

                pp=new Paciente; //me creo un nuevo paciente para agregar a la lista

                if(NOCUP<NumConsultorios)// si no estan todos los consultorios llenos, entra un paciente
                {
                        NOCUP++;
                        pp->estado=1;//el paciente esta entrando
                        pp->tiempo=5;//tarda 5 min en entrar
                        pp->tespera=0;//no espero nada

                }
                else //si estan todos los consultorios ocupados el nuevo que viene tiene que esperar
                {
                        pp->estado=0;//esta esperando
                        pp->tiempo=0; //no hay cuenta regresiva de tiempo para hacer
                        pp->tespera=0;//empieza a esperar (empiezo a contar cuanto tiempo espera)

                }

                ListaPac->Add(pp);//me agrego el paciente a la lista

                hora=(t+8*60)/60.0;
                //si el horario es entre las 8hs y las 22hs los pacientes entran cada 2+/-1 min
                if(hora>=8 && hora<22)
                        {t1=gausseana(2.0,1.0);} //genero un nuevo paciente
                //si el horario es entre las 22hs y las 8hs los pacientes entran cada 10+/-5 min
               // if((hora>=22 && hora<24 )|| (hora>=0 && hora<8 ))
               else
                        {t1=gausseana(10.0,5.0);} //genero un nuevo paciente

                tp=t;

                Display->Lines->Clear();

                for(int i=0;i<ListaPac->Count;i++) //recorro la lista de pacientes y la imprimo con el estado del paciente antes de actualizarlo
                {
                        pp=(Paciente *)ListaPac->Items[i]; //levanto el paciente[i] de la lista
                        texto.printf("paciente %d   estado %d    tiempo %f    tiempo de espera %f " , i, pp->estado, pp->tiempo, pp->tespera);
                        Display->Lines->Add(texto); //muestro el estado del paciente antes de actualizarlo

                        switch(pp->estado)
                        {
                                case 0: //esta esperando
                                        if(NOCUP<NumConsultorios) //si hay algun consultorio desocupado
                                        {
                                                pp->estado=1;//lo hago entrar
                                                pp->tiempo=5; //tiempo que va a tardar en entrar
                                                NOCUP++;
                                        }
                                        else pp->tespera++; //espera un min mas
                                break;
                                case 1: //esta entrando
                                        if(pp->tiempo<=0)//si ya pasaron los 5 min
                                        {
                                                pp->estado=2;//entra al consultorio y se atiende
                                                pp->tiempo=gausseana(25.0,15.0); //lo que tarda en atenderlo el medico
                                        }
                                        else pp->tiempo--;//le falta un minuto menos para entrar
                                break;
                                case 2: //se esta atendiendo
                                        if(pp->tiempo<=0)//ya se atendio
                                        {
                                                pp->estado=3;//sale del consultorio
                                                NOCUP--; //hay un consultorio menos ocupado
                                                pp->tiempo=2; //lo que tarda en salir
                                        }
                                        else pp->tiempo--;//le falta un minuto menos para terminar de atenderse
                                break;
                                case 3: //esta saliendo
                                        if(pp->tiempo<=0)//ya salio
                                        {
                                                pp->estado=4; //esta atendido
                                                pp->tiempo=0;
                                        }
                                        else pp->tiempo--; //le falta un minuto menos para terminar de salir
                                break;
                                case 4: //esta atendido
                                        //me guardo el tiempo de espera en un acumulado
                                        t_acum=t_acum+pp->tespera;//si ya lo atendi me guardo cuanto tuvo que esperar para ser atendido
                                                                  // lo acumulo para todos los pac atendidos
                                        t_acum_tot=t_acum_tot+pp->tespera;
                                        ListaPac->Delete(i); //una vez que el paciente se atendio, lo elimino del array

                                        NPAC--;
                                        NATENDIDOS++; //atendi un paciente mas y se fue
                                        NPACxhora++;


                                break;

                        }

                }
        }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
        if(parar) //si esta habilitado para parar la simulacion
        {
                Timer1->Enabled=false;
                parar=false; //deshabilito para parar==>solo puedo continuar con la simulacion
        }
        else
        {
                Timer1->Enabled=true;
                parar=true; //habilito para parar
        }
}
//---------------------------------------------------------------------------
