object FRooms: TFRooms
  Left = 0
  Top = 0
  BorderIcons = []
  BorderStyle = bsSingle
  Caption = 'HotelPlus'
  ClientHeight = 272
  ClientWidth = 438
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
  object Button3: TButton
    Left = 170
    Top = 8
    Width = 75
    Height = 25
    Caption = 'Refresh'
    TabOrder = 2
    OnClick = Button3Click
  end
  object DBGrid1: TDBGrid
    Left = 8
    Top = 39
    Width = 237
    Height = 162
    DataSource = DataSource1
    TabOrder = 3
    TitleFont.Charset = DEFAULT_CHARSET
    TitleFont.Color = clWindowText
    TitleFont.Height = -11
    TitleFont.Name = 'Tahoma'
    TitleFont.Style = []
    Columns = <
      item
        Expanded = False
        FieldName = 'Room_code'
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'Number'
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'Type'
        Visible = True
      end>
  end
  object DBNavigator1: TDBNavigator
    Left = 8
    Top = 207
    Width = 230
    Height = 25
    DataSource = DataSource1
    TabOrder = 4
  end
  object DBGrid2: TDBGrid
    Left = 244
    Top = 39
    Width = 173
    Height = 162
    Ctl3D = True
    DataSource = DataSource2
    ParentCtl3D = False
    ReadOnly = True
    TabOrder = 5
    TitleFont.Charset = DEFAULT_CHARSET
    TitleFont.Color = clWindowText
    TitleFont.Height = -11
    TitleFont.Name = 'Tahoma'
    TitleFont.Style = []
    Columns = <
      item
        Expanded = False
        FieldName = 'Type_code'
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'Type'
        Width = 70
        Visible = True
      end>
  end
  object SortButton: TButton
    Left = 8
    Top = 238
    Width = 75
    Height = 20
    Caption = 'Sort'
    TabOrder = 6
    OnClick = SortButtonClick
  end
  object ComboBox1: TComboBox
    Left = 89
    Top = 238
    Width = 75
    Height = 21
    TabOrder = 7
    Items.Strings = (
      'DESC'
      'ASC')
  end
  object ComboBox2: TComboBox
    Left = 170
    Top = 238
    Width = 68
    Height = 21
    TabOrder = 8
    Items.Strings = (
      'Number'
      'Type')
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
    Left = 400
    Top = 224
  end
  object ADOTable1: TADOTable
    Active = True
    Connection = ADOConnection1
    CursorType = ctStatic
    TableName = 'Rooms'
    Left = 368
    Top = 65528
  end
  object DataSource1: TDataSource
    DataSet = ADOTable1
    Left = 328
  end
  object ADOQuerySort: TADOQuery
    Connection = ADOConnection1
    Parameters = <>
    Left = 280
  end
  object ADOTable2: TADOTable
    Active = True
    Connection = ADOConnection1
    CursorType = ctStatic
    TableName = 'Room_type'
    Left = 360
    Top = 224
  end
  object DataSource2: TDataSource
    DataSet = ADOTable2
    Left = 328
    Top = 224
  end
end
