//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "dbbetweenfilter.h"

//---------------------------------------------------------------------------

#pragma package(smart_init)
//---------------------------------------------------------------------------
__fastcall TDBBetweenFilter::TDBBetweenFilter(TComponent* Owner)
        : TDBFilter(Owner)
{
 CreateEdit();
 FEditOd->Parent =FpaBottom;
 FEditDo->Parent= FpaBottom;
 Height =65;
 ( ( TMainWinControl*)FEditOd)->OnKeyPress=GotoNextOd;
 ( (TMainWinControl*)FEditDo)->OnKeyPress=GotoNextDo;
 OnResizeFilter(this);
}
//---------------------------------------------------------------------------
__fastcall TDBBetweenFilter::~TDBBetweenFilter(void)
{
 delete FEditOd;
 delete FEditDo;
 delete FlbOd;
 delete FlbDo;
}
//---------------------------------------------------------------------------
void __fastcall TDBBetweenFilter::OnResizeFilter(TObject * Sender)
{
 FlbOd->Left=5;
 FlbOd->Top =8;
 FlbOd->Height =FpaBottom->Height-15;
 int EditWidth=(FpaBottom->Width - FlbOd->Width -FlbDo->Width -31)/2;

 FEditOd->Top   = 5;
 FEditOd->Left  = FlbOd->Width + 10;
 FEditOd->Width = EditWidth;
 FEditOd->Height =FpaBottom->Height - 15;

 FlbDo->Top = 8;
 FlbDo->Left = FEditOd->Left + EditWidth + 5;
 FlbDo->Height = FpaBottom->Height - 15;

 FEditDo->Top =5;
 FEditDo->Height = FpaBottom->Height - 15;
 FEditDo->Left =FlbDo->Left + FlbDo->Width + 5;
 FEditDo->Width = EditWidth;
}
//---------------------------------------------------------------------------
//Border style
void __fastcall TDBBetweenFilter::SetBorderStyle(Forms::TFormBorderStyle _BorderStyle)
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
void __fastcall TDBBetweenFilter::SetEnabled(bool aEnabled)
{
  TDBFilter::SetEnabled(aEnabled);
  FEditOd->Enabled = aEnabled;
  FEditDo->Enabled = aEnabled;
  if(aEnabled)
    {
      ((TMainWinControl*)FEditOd)->Color = clWindow;
      ((TMainWinControl*)FEditDo)->Color = clWindow;
    }
  else
    {
     ((TMainWinControl*)FEditOd)->Color=clInactiveCaptionText;
     ((TMainWinControl*)FEditDo)->Color=clInactiveCaptionText;
    }
    ( (TMainWinControl*) FEditOd)->Ctl3D=aEnabled;
    ( (TMainWinControl*) FEditDo)->Ctl3D=aEnabled;
}
//---------------------------------------------------------------------------
//Obsluga zdarzenia OEnter
void __fastcall TDBBetweenFilter::DoEnter(void)
{
 FEditOd->SetFocus();
 if(OnEnter) OnEnter(this);
}

//---------------------------------------------------------------------------
//Listy
UnicodeString __fastcall TDBBetweenFilter::GetList(void)
{
 UnicodeString Res("");
 UnicodeString Text1 =  ( (TMainWinControl*) FEditOd)->Text;
 UnicodeString Text2 =  ( (TMainWinControl*) FEditDo)->Text;
 if( !(Text1.IsEmpty() && (Text2.IsEmpty() ) ) )
   {
    Res = KeyField;
    Res += " BETWEEN ";
    Res += Text1;
    Res += " AND ";
    Res += Text2;
   }
 return Res;
}
//---------------------------------------------------------------------------
UnicodeString __fastcall TDBBetweenFilter::GetStringList(void)
{
 return GetList();
}
//---------------------------------------------------------------------------
UnicodeString __fastcall TDBBetweenFilter::GetTextOd(void)
{
 return ( (TMainWinControl*) FEditOd)->Text;
}
//---------------------------------------------------------------------------
void __fastcall TDBBetweenFilter::SetTextOd(UnicodeString aText)
{
  ( (TMainWinControl*) FEditOd)->Text=aText;
}
//---------------------------------------------------------------------------
UnicodeString __fastcall TDBBetweenFilter::GetTextDo(void)
{
 return ( (TMainWinControl*) FEditDo)->Text;
}
//---------------------------------------------------------------------------
void __fastcall TDBBetweenFilter::SetTextDo(UnicodeString aText)
{
  ( (TMainWinControl*) FEditDo)->Text=aText;
}
//---------------------------------------------------------------------------
void __fastcall TDBBetweenFilter::CreateEdit(void)
{
 FlbOd = new TLabel(this);
 FlbDo = new TLabel(this);
 FlbOd->Parent = FpaBottom;
 FlbDo->Parent = FpaBottom;
 FlbOd->Caption ="Od";
 FlbDo->Caption = "do";
}
//---------------------------------------------------------------------------
void __fastcall TDBBetweenFilter::GotoNextOd(TObject * Sender,wchar_t& Key)
{
 if(Key =='\r' || Key =='\t')
   {
	FEditDo->SetFocus();
	Key=0;
   }
}
//---------------------------------------------------------------------------
void __fastcall TDBBetweenFilter::GotoNextDo(TObject * Sender,wchar_t& Key)
{
 if(OnKeyPress) OnKeyPress(Sender,Key);
}

//---------------------------------------------------------------------------

