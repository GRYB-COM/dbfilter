object Form3: TForm3
  Left = 0
  Top = 0
  Caption = 'Form3'
  ClientHeight = 301
  ClientWidth = 562
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object DBListFilter1: TDBListFilter
    Left = 24
    Top = 16
    Width = 250
    Height = 150
    BorderStyle = bsSingle
    Color = clBtnFace
    TabOrder = 0
  end
  object DBItemFilter1: TDBItemFilter
    Left = 296
    Top = 16
    Width = 250
    Height = 150
    BorderStyle = bsSingle
    Color = clBtnFace
    TabOrder = 1
    Single = True
    Items.Strings = (
      '1'
      '2'
      '3'
      '4'
      '5'
      '6'
      '7'
      '8'
      '90')
    Values.Strings = (
      '1'
      '2'
      '3'
      '4'
      '5'
      '6'
      '7'
      '8'
      '90')
  end
  object NumEditsFilter1: TNumEditsFilter
    Left = 48
    Top = 192
    Width = 250
    Height = 65
    BorderStyle = bsSingle
    Color = clBtnFace
    TabOrder = 2
    Text = '0,00'
    TextDo = '0,00'
  end
  object DBLCombosFilter1: TDBLCombosFilter
    Left = 304
    Top = 192
    Width = 250
    Height = 65
    BorderStyle = bsSingle
    Color = clBtnFace
    TabOrder = 3
  end
  object Button1: TButton
    Left = 463
    Top = 263
    Width = 75
    Height = 25
    Caption = 'Button1'
    TabOrder = 4
    OnClick = Button1Click
  end
end
