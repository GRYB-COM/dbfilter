//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "dbequalfilter.h"
#pragma link "DBFil"
#pragma package(smart_init)
//---------------------------------------------------------------------------
__fastcall TDBEqualFilter::TDBEqualFilter(TComponent* Owner)
        : TDBFilter(Owner)
{
 CreateEdit();
 FEdit->Parent=FpaBottom;
  Height=65;
 OnResizeFilter(this);
}
//---------------------------------------------------------------------------
__fastcall TDBEqualFilter::~TDBEqualFilter(void)
{
 delete FEdit;
}
//---------------------------------------------------------------------------
void __fastcall TDBEqualFilter::OnResizeFilter(TObject * Sender)
{
 FEdit->Left=5;

 FEdit->Top =5;
 
 FEdit->Width =FpaBottom->Width-15;

 FEdit->Height =FpaBottom->Height-15;
}
//---------------------------------------------------------------------------
//Border style
void __fastcall TDBEqualFilter::SetBorderStyle(Forms::TFormBorderStyle _BorderStyle)
{
TDBFilter::SetBorderStyle(_BorderStyle);
   if(_BorderStyle==bsNone)
     {
       FpaBottom->BevelInner=bvNone;
       FpaBottom->BevelOuter=bvNone;
       FpaTop->BevelInner=bvNone;
       FpaTop->BevelOuter=bvNone;
     }
     else
     {
      FpaBottom->BevelInner=bvRaised;
      FpaBottom->BevelOuter=bvRaised;
      FpaTop->BevelInner=bvRaised;
      FpaTop->BevelOuter=bvRaised;
     }
}
//---------------------------------------------------------------------------
//Enabled
void __fastcall TDBEqualFilter::SetEnabled(bool aEnabled)
{
  TDBFilter::SetEnabled(aEnabled);
  FEdit->Enabled = aEnabled;
  if(aEnabled) ((TMainWinControl*)FEdit)->Color = clWindow;
  else ((TMainWinControl*)FEdit)->Color=clInactiveCaptionText;
    ( (TMainWinControl*) FEdit)->Ctl3D=aEnabled;
}

//---------------------------------------------------------------------------
//Obsluga zdarzenia OnClick
void __fastcall TDBEqualFilter::DoEnter(void)
{
 FEdit->SetFocus();
 if(OnEnter) OnEnter(this);
}
//---------------------------------------------------------------------------
//Listy
UnicodeString __fastcall TDBEqualFilter::GetList(void)
{
 return ( (TMainWinControl*) FEdit)->Text;
}
//---------------------------------------------------------------------------
UnicodeString __fastcall TDBEqualFilter::GetStringList(void)
{
 UnicodeString Res("");
 UnicodeString List=GetList();
 if(!List.IsEmpty() )
 {
  Res=KeyField;
  Res+=GetEqualKind();
  Res += List;
 }
 return Res;
}
//---------------------------------------------------------------------------
//EqualKind
void __fastcall TDBEqualFilter::SetEqualKind(TEqualKind aEqualKind)
{
 FEqualKind=aEqualKind;
}
//---------------------------------------------------------------------------
UnicodeString __fastcall TDBEqualFilter::GetEqualKind(void)
{
 UnicodeString Res("");
 switch(FEqualKind)
  {
   case ekEqual:
   Res = " = ";
   break;
   case ekLike:
   Res = " LIKE ";
   break;
   case ekIs:
    Res = " IS ";
   break;
   case ekLess:
    Res = " < ";
   break;
   case ekGreater:
    Res = " > " ;
   break;
  }
 return Res;
}
//---------------------------------------------------------------------------
UnicodeString __fastcall TDBEqualFilter::GetText(void)
{
 return ( (TMainWinControl*) FEdit)->Text;
}
//---------------------------------------------------------------------------
void __fastcall TDBEqualFilter::SetText(UnicodeString aText)
{
  ( (TMainWinControl*) FEdit)->Text=aText;
}
