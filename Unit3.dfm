object FInformation: TFInformation
  Left = 0
  Top = 0
  BorderIcons = []
  BorderStyle = bsSingle
  Caption = 'HotelPlus'
  ClientHeight = 311
  ClientWidth = 982
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
  object BackButton: TButton
    Left = 8
    Top = 8
    Width = 75
    Height = 25
    Caption = 'Back'
    TabOrder = 0
    OnClick = BackButtonClick
  end
  object CloseButton: TButton
    Left = 89
    Top = 8
    Width = 75
    Height = 25
    Caption = 'Close'
    TabOrder = 1
    OnClick = CloseButtonClick
  end
  object DBGrid1: TDBGrid
    Left = 8
    Top = 39
    Width = 961
    Height = 226
    DataSource = DataSource1
    ReadOnly = True
    TabOrder = 2
    TitleFont.Charset = DEFAULT_CHARSET
    TitleFont.Color = clWindowText
    TitleFont.Height = -11
    TitleFont.Name = 'Tahoma'
    TitleFont.Style = []
    Columns = <
      item
        Expanded = False
        FieldName = 'Information_code'
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'Number'
        Width = 50
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'Type'
        Width = 80
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'FN_client'
        Width = 80
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'Phone_number'
        Width = 85
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'Serial_number'
        Width = 85
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'Country'
        Width = 70
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'Birth_date'
        Width = 70
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'Service_title'
        Width = 80
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'Arrival_data'
        Width = 80
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'Eviction_data'
        Width = 80
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'Total Cost'
        Visible = True
      end>
  end
  object Button1: TButton
    Left = 889
    Top = 8
    Width = 75
    Height = 25
    Caption = 'Edit'
    TabOrder = 3
    OnClick = Button1Click
  end
  object RefreshButton: TButton
    Left = 251
    Top = 271
    Width = 75
    Height = 22
    Caption = 'Refresh'
    TabOrder = 4
    OnClick = RefreshButtonClick
  end
  object Button2: TButton
    Left = 8
    Top = 272
    Width = 75
    Height = 21
    Caption = 'Sort'
    TabOrder = 5
    OnClick = Button2Click
  end
  object ComboBox1: TComboBox
    Left = 89
    Top = 271
    Width = 75
    Height = 21
    TabOrder = 6
    Items.Strings = (
      'DESC'
      'ASC')
  end
  object ComboBox2: TComboBox
    Left = 170
    Top = 271
    Width = 75
    Height = 21
    TabOrder = 7
    Items.Strings = (
      'Number')
  end
  object ADOConnection: TADOConnection
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
    Left = 432
  end
  object ADOTableInformation: TADOTable
    Active = True
    Connection = ADOConnection
    CursorType = ctStatic
    TableName = 'GetInfo'
    Left = 400
  end
  object DataSource1: TDataSource
    DataSet = ADOTableInformation
    Left = 368
  end
  object ADOQuerySort: TADOQuery
    Connection = ADOConnection
    Parameters = <>
    Left = 480
  end
end
