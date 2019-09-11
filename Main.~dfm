object Form1: TForm1
  Left = 228
  Top = 127
  Width = 989
  Height = 561
  Caption = 'Form1'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object GroupBox6: TGroupBox
    Left = 576
    Top = 200
    Width = 177
    Height = 49
    Caption = 'Pacientes atendidos'
    TabOrder = 11
  end
  object Display: TMemo
    Left = 16
    Top = 8
    Width = 345
    Height = 505
    Lines.Strings = (
      'Display')
    TabOrder = 0
  end
  object GroupBox1: TGroupBox
    Left = 392
    Top = 16
    Width = 169
    Height = 49
    Caption = 'Numero de consultorios'
    TabOrder = 1
    object Edit1: TEdit
      Left = 16
      Top = 16
      Width = 137
      Height = 21
      TabOrder = 0
      Text = '5'
    end
  end
  object Simular: TButton
    Left = 392
    Top = 80
    Width = 169
    Height = 41
    Caption = 'Simular'
    TabOrder = 2
    OnClick = SimularClick
  end
  object Chart1: TChart
    Left = 400
    Top = 264
    Width = 345
    Height = 265
    BackWall.Brush.Color = clWhite
    BackWall.Brush.Style = bsClear
    Title.Text.Strings = (
      'TChart')
    BottomAxis.Title.Caption = 'Hora del d'#237'a'
    LeftAxis.Title.Caption = 'Tiempo medio de espera (min)'
    Legend.Visible = False
    View3D = False
    TabOrder = 3
    object Series1: TLineSeries
      Marks.ArrowLength = 8
      Marks.Visible = False
      SeriesColor = clRed
      Pointer.InflateMargins = True
      Pointer.Style = psRectangle
      Pointer.Visible = False
      XValues.DateTime = False
      XValues.Name = 'X'
      XValues.Multiplier = 1
      XValues.Order = loAscending
      YValues.DateTime = False
      YValues.Name = 'Y'
      YValues.Multiplier = 1
      YValues.Order = loNone
    end
  end
  object GroupBox2: TGroupBox
    Left = 584
    Top = 16
    Width = 145
    Height = 49
    Caption = 'Tiempo transcurrido (min)'
    TabOrder = 4
    object Edit2: TEdit
      Left = 16
      Top = 16
      Width = 113
      Height = 21
      TabOrder = 0
      Text = '0'
    end
  end
  object GroupBox3: TGroupBox
    Left = 584
    Top = 80
    Width = 145
    Height = 49
    Caption = 'Tiempo transcurrido (h)'
    TabOrder = 5
    object Edit3: TEdit
      Left = 16
      Top = 16
      Width = 113
      Height = 21
      TabOrder = 0
      Text = '0'
    end
  end
  object GroupBox4: TGroupBox
    Left = 576
    Top = 144
    Width = 177
    Height = 49
    Caption = 'Tiempo medio de espera total (min)'
    TabOrder = 6
  end
  object Edit4: TEdit
    Left = 600
    Top = 160
    Width = 121
    Height = 21
    TabOrder = 7
    Text = '0'
  end
  object Button1: TButton
    Left = 392
    Top = 136
    Width = 169
    Height = 41
    Caption = 'Parar/Continuar'
    TabOrder = 8
    OnClick = Button1Click
  end
  object GroupBox5: TGroupBox
    Left = 392
    Top = 184
    Width = 161
    Height = 65
    Caption = 'Hora del d'#237'a'
    TabOrder = 9
    object Label1: TLabel
      Left = 72
      Top = 32
      Width = 6
      Height = 20
      Caption = ':'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label2: TLabel
      Left = 24
      Top = 16
      Width = 21
      Height = 13
      Caption = 'hora'
    end
    object Label3: TLabel
      Left = 96
      Top = 16
      Width = 16
      Height = 13
      Caption = 'min'
    end
    object Edit5: TEdit
      Left = 8
      Top = 32
      Width = 57
      Height = 21
      TabOrder = 0
    end
    object Edit6: TEdit
      Left = 88
      Top = 32
      Width = 57
      Height = 21
      TabOrder = 1
    end
  end
  object Edit7: TEdit
    Left = 592
    Top = 216
    Width = 145
    Height = 21
    TabOrder = 10
    Text = '0'
  end
  object GroupBox7: TGroupBox
    Left = 752
    Top = 16
    Width = 161
    Height = 49
    Caption = 'Pacientes en espera'
    TabOrder = 12
    object Edit8: TEdit
      Left = 16
      Top = 16
      Width = 121
      Height = 21
      TabOrder = 0
      Text = '0'
    end
  end
  object GroupBox8: TGroupBox
    Left = 752
    Top = 80
    Width = 161
    Height = 49
    Caption = '% de pacientes atendidos'
    TabOrder = 13
    object Edit9: TEdit
      Left = 16
      Top = 16
      Width = 121
      Height = 21
      TabOrder = 0
      Text = '0'
    end
  end
  object GroupBox9: TGroupBox
    Left = 768
    Top = 144
    Width = 161
    Height = 49
    Caption = 'Total de pacientes ingresados'
    TabOrder = 14
    object Edit10: TEdit
      Left = 16
      Top = 16
      Width = 121
      Height = 21
      TabOrder = 0
      Text = '0'
    end
  end
  object Timer1: TTimer
    Enabled = False
    Interval = 1
    OnTimer = Timer1Timer
    Left = 368
    Top = 248
  end
end
