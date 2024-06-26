object FServices: TFServices
  Left = 0
  Top = 0
  BorderIcons = []
  BorderStyle = bsSingle
  Caption = 'HotelPlus'
  ClientHeight = 211
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
  object Label1: TLabel
    Left = 296
    Top = 41
    Width = 65
    Height = 13
    Caption = 'Service_titile:'
  end
  object Label2: TLabel
    Left = 391
    Top = 41
    Width = 26
    Height = 13
    Caption = 'Cost:'
  end
  object DBGrid1: TDBGrid
    Left = 8
    Top = 39
    Width = 273
    Height = 138
    DataSource = DataSource1
    ReadOnly = True
    TabOrder = 0
    TitleFont.Charset = DEFAULT_CHARSET
    TitleFont.Color = clWindowText
    TitleFont.Height = -11
    TitleFont.Name = 'Tahoma'
    TitleFont.Style = []
    Columns = <
      item
        Expanded = False
        FieldName = 'Service_code'
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'Service_title'
        Width = 100
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'Cost'
        Width = 65
        Visible = True
      end>
  end
  object BackButton: TButton
    Left = 8
    Top = 8
    Width = 75
    Height = 25
    Caption = 'Back'
    TabOrder = 1
    OnClick = BackButtonClick
  end
  object ExitButton: TButton
    Left = 89
    Top = 8
    Width = 75
    Height = 25
    Caption = 'Close'
    TabOrder = 2
    OnClick = ExitButtonClick
  end
  object ServiceEdit: TEdit
    Left = 296
    Top = 60
    Width = 89
    Height = 21
    TabOrder = 3
  end
  object CostEdit: TEdit
    Left = 391
    Top = 60
    Width = 89
    Height = 21
    TabOrder = 4
  end
  object Button1: TButton
    Left = 296
    Top = 87
    Width = 89
    Height = 25
    Caption = 'Add'
    TabOrder = 5
    OnClick = Button1Click
  end
  object RemoveButton: TButton
    Left = 8
    Top = 183
    Width = 89
    Height = 21
    Caption = 'Remove'
    TabOrder = 6
    OnClick = RemoveButtonClick
  end
  object RemoveByTitleButton: TButton
    Left = 391
    Top = 87
    Width = 89
    Height = 25
    Caption = 'Remove by title'
    TabOrder = 7
    OnClick = RemoveByTitleButtonClick
  end
  object Button2: TButton
    Left = 296
    Top = 153
    Width = 89
    Height = 21
    Caption = 'Sort'
    TabOrder = 8
    OnClick = Button2Click
  end
  object ComboBox1: TComboBox
    Left = 296
    Top = 126
    Width = 89
    Height = 21
    TabOrder = 9
    Items.Strings = (
      'DESC'
      'ASC')
  end
  object ComboBox2: TComboBox
    Left = 391
    Top = 126
    Width = 89
    Height = 21
    TabOrder = 10
    Items.Strings = (
      'Cost')
  end
  object RefreshButton: TButton
    Left = 391
    Top = 153
    Width = 89
    Height = 21
    Caption = 'Refresh'
    TabOrder = 11
    OnClick = RefreshButtonClick
  end
  object ADOConnection1: TADOConnection
    Connected = True
    ConnectionString = 
      'Provider=Microsoft.Jet.OLEDB.4.0;Data Source=E:\'#1044#1086#1082#1091#1084#1077#1085#1090#1080'\Embarc' +
      'adero\Studio\Projects\TestHotel.mdb;Mode=ReadWrite;Persist Secur' +
      'ity Info=False'
    LoginPrompt = False
    Mode = cmReadWrite
    Provider = 'Microsoft.Jet.OLEDB.4.0'
    Left = 336
  end
  object ADOTable1: TADOTable
    Active = True
    Connection = ADOConnection1
    CursorType = ctStatic
    TableName = 'Additional_services'
    Left = 280
  end
  object DataSource1: TDataSource
    DataSet = ADOTable1
    Left = 472
    Top = 8
  end
  object ADOQuerySort: TADOQuery
    Connection = ADOConnection1
    Parameters = <>
    Left = 408
  end
end
