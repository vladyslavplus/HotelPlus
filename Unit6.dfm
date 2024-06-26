object FEditInfo: TFEditInfo
  Left = 0
  Top = 0
  BorderIcons = []
  BorderStyle = bsSingle
  Caption = 'HotelPlus'
  ClientHeight = 288
  ClientWidth = 524
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
    Width = 505
    Height = 210
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
        FieldName = 'Client'
        Width = 45
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'Room_number'
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'Additional_service'
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
      end>
  end
  object RemoveEditButton: TButton
    Left = 8
    Top = 255
    Width = 75
    Height = 25
    Caption = 'Remove'
    TabOrder = 3
    OnClick = RemoveEditButtonClick
  end
  object ADOConnectionEdit: TADOConnection
    Connected = True
    ConnectionString = 
      'Provider=Microsoft.Jet.OLEDB.4.0;Data Source=E:\'#1044#1086#1082#1091#1084#1077#1085#1090#1080'\Embarc' +
      'adero\Studio\Projects\TestHotel.mdb;Mode=ReadWrite;Persist Secur' +
      'ity Info=False'
    LoginPrompt = False
    Mode = cmReadWrite
    Provider = 'Microsoft.Jet.OLEDB.4.0'
    Left = 376
  end
  object DataSource1: TDataSource
    DataSet = ADOTable1
    Left = 432
  end
  object ADOTable1: TADOTable
    Active = True
    Connection = ADOConnectionEdit
    CursorType = ctStatic
    TableName = 'Information'
    Left = 472
  end
end
