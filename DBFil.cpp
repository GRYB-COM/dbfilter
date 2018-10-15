//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "dbfil.h"
#pragma package(smart_init)
//ElookupFilterExc
 __fastcall EFilterExc:: EFilterExc(UnicodeString Msg)
             :Exception(Msg){};

UnicodeString KeyFieldErr="W³aœciwoœæ KeyField nie ma wartoœci";
//---------------------------------------------------------------------------
// konstruktor i destruktor
__fastcall TDBFilter::TDBFilter(TComponent* Owner)
        : TDBLookupControl(Owner)
{

 Width=250;
 Height=150;
 Color =clBtnFace;
//panel gorny
 FpaTop = new TPanel(this);
 FpaTop->Name="paTop";
 FpaTop->Caption="";
 FpaTop->BorderStyle = bsSingle;
//panel dolny
 FpaBottom = new TPanel(this);
 FpaBottom->Name="paBotttom";
 FpaBottom->Caption="";
 FpaBottom->BorderStyle = bsSingle;
 ShowPanels();
//etykieta do wyswietlania
 FlbCaption=new TLabel(this);
 FlbCaption->Name="lbCaption";
 ShowCaption();
 OnResize = OnResizeFilter;

}
//---------------------------------------------------------------------------
//destruktor usuwa wszystkie new-y
__fastcall TDBFilter::~TDBFilter(void)
{
 delete FlbCaption;
 delete FpaBottom;
 delete FpaTop;
}


//---------------------------------------------------------------------------
// ustawianie widocznych wlasciwosci panelow
void __fastcall TDBFilter::ShowPanels(void)
{
 //FpaTop
 FpaTop->Parent=this;
 FpaTop->Align=alTop;
 FpaTop->Height=27;
 FpaTop->ParentColor=true;
 FpaTop->BorderStyle= bsSingle;
 FpaTop->Show();
// FpaBottom
 FpaBottom->Parent=this;
 FpaBottom->Align=alClient;
 FpaBottom->ParentColor=true;
 FpaBottom->ParentFont=true;
 FpaBottom->ParentShowHint=true;
 FpaBottom->Height=32;
 FpaBottom->BevelInner=bvSpace;
 FpaBottom->BorderStyle= bsSingle;
 FpaBottom->Show();
}
//---------------------------------------------------------------------------
//implementacja i obsluga naglowka   SetCaption i GetCaption sa in line
void __fastcall TDBFilter::ShowCaption(void)
{
 FlbCaption->Parent=FpaTop;
 FlbCaption->Left=5;
 FlbCaption->Top=5;
 FlbCaption->Width=Width;
 FlbCaption->Caption=Name;
 FlbCaption->Show();
}
//---------------------------------------------------------------------------
//implementacja wlasciwosci BorderStyle

void __fastcall TDBFilter::SetBorderStyle(Forms::TFormBorderStyle _BorderStyle)
{
  FpaBottom->BorderStyle = _BorderStyle;
  FpaTop->BorderStyle    = _BorderStyle;
}
//---------------------------------------------------------------------------
//obsluga Enabled
bool __fastcall TDBFilter::GetEnabled(void)
{
 return TDBLookupControl::Enabled;
}
//---------------------------------------------------------------------------
void __fastcall TDBFilter::SetEnabled(bool aEnabled)
{
  TDBLookupControl::Enabled=aEnabled;
  if(aEnabled)
    {
     Color=clBtnFace;
    }
  else
    {
     Color=clInactiveCaptionText;
    }
}
//Obsluga zdarzenia OnClick
//---------------------------------------------------------------------------
void __fastcall TDBFilter::DBFilterClick(TObject* Sender)
{
  if(OnClick)
     {
      OnClick(Sender);
     }
}
//Obsluga zdarzenia OnEnter
//---------------------------------------------------------------------------
void __fastcall TDBFilter::DoEnter(void)
{
 SelectFirst();
 if(OnEnter) OnEnter(this);
}
//Obsluga zdarzenia OnChange
//---------------------------------------------------------------------------
void __fastcall TDBFilter::DoChange(TObject* Sender)
{
  if(OnChange) OnChange(Sender);
}
//Obsluga zdarzenia OnKeyPress
//---------------------------------------------------------------------------
void __fastcall TDBFilter::DoKeyPress(TObject* Sender, wchar_t& Key)
{
  if(OnKeyPress) OnKeyPress(Sender,Key);
}
//---------------------------------------------------------------------------
//Obsluga zdarzenia OnKeyDown
//---------------------------------------------------------------------------
void __fastcall TDBFilter::DoKeyDown(TObject * Sender,Word& Key, TShiftState State)
{
  if(OnKeyDown) OnKeyDown(Sender,Key,State);
}
//---------------------------------------------------------------------------
//Nadpisuje Loaded wywolywany przez BCB przy ladowaniu komponentu ze strumienia
void __fastcall TDBFilter::Loaded(void)
{
 TDBLookupControl::Loaded();
 OnResizeFilter(this);
}
//---------------------------------------------------------------------------
// GetStringList zwraca liste wybranych wartosci
UnicodeString __fastcall TDBFilter::GetStringList(void)
{
 UnicodeString Res("Zwraca wyra¿enie KeyVal  IN ('VAL1', 'VAL2', 'VAL3' ) ");
 if( ComponentState.Contains(csDesigning) ) return Res;
 Res="";
 UnicodeString List=GetList();
    if(KeyField.IsEmpty()) throw EFilterExc(KeyFieldErr) ;
    if(!List.IsEmpty())
      {
       Res+=KeyField;
       Res+=" IN (" ;
       Res+=List;
       Res+=")";
      }
 return Res;
}
//---------------------------------------------------------------------------
//GetCondition jak wyzej tylko razem z dodanym z przodu predykatem WHERE
UnicodeString __fastcall TDBFilter::GetCondition(void)
{
 UnicodeString Res("Zwraca wyra¿enie WHERE KeyVal IN ('VAL1', 'VAL2', 'VAL3' ) ");
 if( ComponentState.Contains(csDesigning) ) return Res;
 Res="";
 UnicodeString StrList=GetStringList();
 if(!StrList.IsEmpty())
   {
    Res = " WHERE ";
    Res +=StrList;
   }
 return Res;
}
//---------------------------------------------------------------------------


