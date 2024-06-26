object FRoomTypes: TFRoomTypes
  Left = 0
  Top = 0
  BorderIcons = []
  BorderStyle = bsSingle
  Caption = 'HotelPlus'
  ClientHeight = 244
  ClientWidth = 269
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
    Left = 8
    Top = 186
    Width = 28
    Height = 13
    Caption = 'Type:'
  end
  object Label2: TLabel
    Left = 89
    Top = 186
    Width = 54
    Height = 13
    Caption = 'Type_cost:'
  end
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
    Width = 249
    Height = 114
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
        FieldName = 'Type_code'
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
        FieldName = 'Type_cost'
        Width = 60
        Visible = True
      end>
  end
  object RemoveButton: TButton
    Left = 8
    Top = 159
    Width = 75
    Height = 21
    Caption = 'Remove'
    TabOrder = 4
    OnClick = RemoveButtonClick
  end
  object ComboBox1: TComboBox
    Left = 170
    Top = 159
    Width = 81
    Height = 21
    TabOrder = 5
    Items.Strings = (
      'DESC'
      'ASC')
  end
  object SortButton: TButton
    Left = 89
    Top = 159
    Width = 75
    Height = 21
    Caption = 'Sort'
    TabOrder = 6
    OnClick = SortButtonClick
  end
  object AddButton: TButton
    Left = 170
    Top = 205
    Width = 81
    Height = 22
    Caption = 'Add'
    TabOrder = 7
    OnClick = AddButtonClick
  end
  object Edit1: TEdit
    Left = 8
    Top = 205
    Width = 75
    Height = 21
    TabOrder = 8
  end
  object Edit2: TEdit
    Left = 89
    Top = 205
    Width = 75
    Height = 21
    TabOrder = 9
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
    Left = 312
    Top = 65528
  end
  object ADOTable1: TADOTable
    Active = True
    Connection = ADOConnection1
    CursorType = ctStatic
    TableName = 'Room_type'
    Left = 288
    Top = 65528
  end
  object DataSource1: TDataSource
    DataSet = ADOTable1
    Left = 256
    Top = 65520
  end
  object ADOQuerySort: TADOQuery
    Connection = ADOConnection1
    Parameters = <>
    Left = 352
    Top = 65528
  end
end
