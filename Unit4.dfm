object FRegister: TFRegister
  Left = 0
  Top = 0
  BorderIcons = []
  BorderStyle = bsSingle
  Caption = 'HotelPlus'
  ClientHeight = 219
  ClientWidth = 445
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poScreenCenter
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 16
    Top = 39
    Width = 50
    Height = 13
    Caption = 'Full Name:'
  end
  object Label2: TLabel
    Left = 16
    Top = 85
    Width = 74
    Height = 13
    Caption = 'Phone Number:'
  end
  object Label3: TLabel
    Left = 17
    Top = 133
    Width = 70
    Height = 13
    Caption = 'Serial Number:'
  end
  object Label4: TLabel
    Left = 160
    Top = 133
    Width = 51
    Height = 13
    Caption = 'Birth date:'
  end
  object Label5: TLabel
    Left = 160
    Top = 39
    Width = 43
    Height = 13
    Caption = 'Country:'
  end
  object Label6: TLabel
    Left = 160
    Top = 85
    Width = 41
    Height = 13
    Caption = 'Number:'
  end
  object Label7: TLabel
    Left = 304
    Top = 133
    Width = 88
    Height = 13
    Caption = 'Additional service:'
  end
  object Label8: TLabel
    Left = 304
    Top = 39
    Width = 60
    Height = 13
    Caption = 'Arrival data:'
  end
  object Label9: TLabel
    Left = 304
    Top = 85
    Width = 66
    Height = 13
    Caption = 'Eviction data:'
  end
  object FNEdit: TEdit
    Left = 18
    Top = 58
    Width = 121
    Height = 21
    TabOrder = 0
  end
  object ButtonBackReg: TButton
    Left = 8
    Top = 8
    Width = 75
    Height = 25
    Caption = 'Back'
    TabOrder = 1
    OnClick = ButtonBackRegClick
  end
  object ButtonCloseReg: TButton
    Left = 89
    Top = 8
    Width = 75
    Height = 25
    Caption = 'Close'
    TabOrder = 2
    OnClick = ButtonCloseRegClick
  end
  object PhoneEdit: TEdit
    Left = 18
    Top = 106
    Width = 121
    Height = 21
    TabOrder = 3
  end
  object SNEdit: TEdit
    Left = 18
    Top = 152
    Width = 121
    Height = 21
    TabOrder = 4
  end
  object CountryEdit: TEdit
    Left = 160
    Top = 58
    Width = 121
    Height = 21
    TabOrder = 5
  end
  object NumberBox: TComboBox
    Left = 160
    Top = 106
    Width = 121
    Height = 21
    TabOrder = 6
  end
  object ServiceBox: TComboBox
    Left = 304
    Top = 152
    Width = 121
    Height = 21
    TabOrder = 7
  end
  object ButtonRegister: TButton
    Left = 18
    Top = 179
    Width = 75
    Height = 25
    Caption = 'Register'
    TabOrder = 8
    OnClick = ButtonRegisterClick
  end
  object BirthPicker: TDateTimePicker
    Left = 160
    Top = 152
    Width = 121
    Height = 21
    Date = 45467.535730902780000000
    Time = 45467.535730902780000000
    TabOrder = 9
  end
  object EvictDataPicker: TDateTimePicker
    Left = 304
    Top = 106
    Width = 121
    Height = 21
    Date = 45467.535730902780000000
    Time = 45467.535730902780000000
    TabOrder = 10
  end
  object ArrDataPicker: TDateTimePicker
    Left = 304
    Top = 58
    Width = 121
    Height = 21
    Date = 45467.000000000000000000
    Time = 45467.000000000000000000
    TabOrder = 11
  end
  object ADOConnection1: TADOConnection
    Connected = True
    ConnectionString = 
      'Provider=Microsoft.Jet.OLEDB.4.0;User ID=Admin;Data Source=E:\'#1044#1086 +
      #1082#1091#1084#1077#1085#1090#1080'\Embarcadero\Studio\Projects\TestHotel.mdb;Mode=ReadWrite' +
      ';Persist Security Info=False;Jet OLEDB:System database="";Jet OL' +
      'EDB:Registry Path="";Jet OLEDB:Database Password="";Jet OLEDB:En' +
      'gine Type=5;Jet OLEDB:Database Locking Mode=1;Jet OLEDB:Global P' +
      'artial Bulk Ops=2;Jet OLEDB:Global Bulk Transactions=1;Jet OLEDB' +
      ':New Database Password="";Jet OLEDB:Create System Database=False' +
      ';Jet OLEDB:Encrypt Database=False;Jet OLEDB:Don'#39't Copy Locale on' +
      ' Compact=False;Jet OLEDB:Compact Without Replica Repair=False;Je' +
      't OLEDB:SFP=False'
    LoginPrompt = False
    Mode = cmReadWrite
    Provider = 'Microsoft.Jet.OLEDB.4.0'
    Left = 376
  end
  object ADOQuery1: TADOQuery
    Connection = ADOConnection1
    Parameters = <>
    Left = 336
  end
end
