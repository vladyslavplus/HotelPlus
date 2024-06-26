object FClients: TFClients
  Left = 0
  Top = 0
  BorderIcons = []
  BorderStyle = bsSingle
  Caption = 'HotelPlus'
  ClientHeight = 293
  ClientWidth = 546
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
  object Button1: TButton
    Left = 8
    Top = 8
    Width = 75
    Height = 25
    Caption = 'Back'
    TabOrder = 0
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 89
    Top = 8
    Width = 75
    Height = 25
    Caption = 'Close'
    TabOrder = 1
    OnClick = Button2Click
  end
  object DBGrid1: TDBGrid
    Left = 8
    Top = 39
    Width = 513
    Height = 210
    DataSource = DataSource1
    TabOrder = 2
    TitleFont.Charset = DEFAULT_CHARSET
    TitleFont.Color = clWindowText
    TitleFont.Height = -11
    TitleFont.Name = 'Tahoma'
    TitleFont.Style = []
    Columns = <
      item
        Expanded = False
        FieldName = 'Client_code'
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'FN_client'
        Width = 90
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
        Width = 80
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
        Width = 80
        Visible = True
      end>
  end
  object Button3: TButton
    Left = 89
    Top = 255
    Width = 75
    Height = 20
    Caption = 'Sort'
    TabOrder = 3
    OnClick = Button3Click
  end
  object ComboBox1: TComboBox
    Left = 169
    Top = 255
    Width = 88
    Height = 21
    TabOrder = 4
    Items.Strings = (
      'DESC'
      'ASC')
  end
  object ComboBox2: TComboBox
    Left = 263
    Top = 255
    Width = 88
    Height = 21
    TabOrder = 5
    Items.Strings = (
      'Client_code'
      'Country'
      'Birth_date')
  end
  object RemoveButton: TButton
    Left = 8
    Top = 255
    Width = 75
    Height = 20
    Caption = 'Remove'
    TabOrder = 6
    OnClick = RemoveButtonClick
  end
  object Button4: TButton
    Left = 357
    Top = 255
    Width = 75
    Height = 20
    Caption = 'Refresh'
    TabOrder = 7
    OnClick = Button4Click
  end
  object ADOConnection1: TADOConnection
    Connected = True
    ConnectionString = 
      'Provider=Microsoft.Jet.OLEDB.4.0;Data Source=E:\'#1044#1086#1082#1091#1084#1077#1085#1090#1080'\Embarc' +
      'adero\Studio\Projects\TestHotel.mdb;Persist Security Info=False'
    LoginPrompt = False
    Mode = cmReadWrite
    Provider = 'Microsoft.Jet.OLEDB.4.0'
    Left = 432
  end
  object ADOTable1: TADOTable
    Active = True
    Connection = ADOConnection1
    CursorType = ctStatic
    TableName = 'Clients'
    Left = 400
  end
  object DataSource1: TDataSource
    DataSet = ADOTable1
    Left = 360
  end
  object ADOQuerySort: TADOQuery
    Connection = ADOConnection1
    Parameters = <>
    Left = 472
  end
end
