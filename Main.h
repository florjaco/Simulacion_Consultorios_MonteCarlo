//---------------------------------------------------------------------------

#ifndef MainH
#define MainH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Chart.hpp>
#include <Series.hpp>
#include <TeEngine.hpp>
#include <TeeProcs.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TMemo *Display;
        TGroupBox *GroupBox1;
        TEdit *Edit1;
        TButton *Simular;
        TTimer *Timer1;
        TChart *Chart1;
        TLineSeries *Series1;
        TGroupBox *GroupBox2;
        TEdit *Edit2;
        TGroupBox *GroupBox3;
        TEdit *Edit3;
        TGroupBox *GroupBox4;
        TEdit *Edit4;
        TButton *Button1;
        TGroupBox *GroupBox5;
        TEdit *Edit5;
        TEdit *Edit6;
        TLabel *Label1;
        TLabel *Label2;
        TLabel *Label3;
        TEdit *Edit7;
        TGroupBox *GroupBox6;
        TGroupBox *GroupBox7;
        TEdit *Edit8;
        TGroupBox *GroupBox8;
        TEdit *Edit9;
        TGroupBox *GroupBox9;
        TEdit *Edit10;
        void __fastcall SimularClick(TObject *Sender);
        void __fastcall Timer1Timer(TObject *Sender);
        void __fastcall Button1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TForm1(TComponent* Owner);
        float ran0(long * idum);
        double gausseana(float media, float SD /*desvio stantard*/);

        TList * ListaPac;
        AnsiString texto;

        void actualizar(); //Lista de pacientes

        int NOCUP;//numero de consultorios ocupados
        int NPAC;
        int NATENDIDOS; //nro de pacientes atendidos
        int NumConsultorios;
        float t,tp,t_acum, t_acum_tot, t1;
        int NPACxhora;
        int NTOT; //total de pacientes q ingresaron

        bool parar;

        float tiempos[24];//me guardo el tiempo medio de espera para cada hora

        struct paciente{
                int estado; //0->esperando, 1->entrando, 2->atendiendo, 3->saliendo, 4->atendido
                float tiempo;
                float tespera;
        };

        typedef struct paciente Paciente;

        Paciente * pp; //puntero a paciente
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
