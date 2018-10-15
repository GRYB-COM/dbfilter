object Form1: TForm1
  Left = 82
  Top = 129
  Width = 544
  Height = 375
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
  object DBLookupFilter1: TDBLookupFilter
    Left = 72
    Top = 48
    Width = 200
    Height = 193
    ParentColor = False
    TabOrder = 0
    TabStop = True
  end
  object DBListFilter1: TDBListFilter
    Left = 288
    Top = 40
    Width = 200
    Height = 233
    ParentColor = False
    TabOrder = 1
    TabStop = True
  end
  object Table1: TTable
    Active = True
    DatabaseName = 'BCDEMOS'
    TableName = 'animals.dbf'
    Left = 392
  end
  object DataSource1: TDataSource
    DataSet = Table1
    Left = 480
    Top = 8
  end
  object Table2: TTable
    Active = True
    DatabaseName = 'BCDEMOS'
    TableName = 'clients.dbf'
    Left = 104
  end
  object DataSource2: TDataSource
    DataSet = Table1
    Left = 192
    Top = 8
  end
end
