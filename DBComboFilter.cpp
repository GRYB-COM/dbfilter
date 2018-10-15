//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "DBComboFilter.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------
// ValidCtrCheck is used to assure that the components created do not have
// any pure virtual functions.
//

static inline void ValidCtrCheck(TDBComboFilter *)
{
	new TDBComboFilter(NULL);
}
//---------------------------------------------------------------------------
__fastcall TDBComboFilter::TDBComboFilter(TComponent* Owner)
	: TPanel(Owner)
{
//podloze
 Width=250;
  Height =65;
  Color =clBtnFace;

//panel gorny
 FpaTop = new TPanel(this);
//panel dolny
 FpaBottom = new TPanel(this);
 ShowPanels();

//etykieta do wyswietlania
 FlbCaption=new TLabel(this);
 ShowCaption();
//Edity
 FEditOd = new TDBLookupComboBox(this);
 FEditDo = new TDBLookupComboBox(this);
 OnResize = OnResizeFilter;
 FEditOd->Parent =FpaBottom;
 FEditDo->Parent= FpaBottom;
 FEditOd->OnKeyPress=GotoNextOd;
 FEditDo->OnKeyPress=GotoNextDo;
//Labele od do
 FlbOd = new TLabel(this);
 FlbDo = new TLabel(this);
 FlbOd->Parent = FpaBottom;
 FlbDo->Parent = FpaBottom;
 FlbOd->Caption ="Od";
 FlbDo->Caption = "do";
 OnResizeFilter(this);
}
//---------------------------------------------------------------------------
//destruktor usuwa wszystkie new-y
__fastcall TDBComboFilter::~TDBComboFilter(void)
{
 delete FlbCaption;
 delete FpaBottom;
 delete FpaTop;
 delete FEditOd;
 delete FEditDo;
}
//---------------------------------------------------------------------------
// ustawianie widocznych wlasciwosci panelow
void __fastcall TDBComboFilter::ShowPanels(void)
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
 //EDITY
   FEditOd->Parent = this;
   FEditDo->Parent = this;
   FEditOd->Show();
   FEditDo->Show();
}
//---------------------------------------------------------------------------
//implementacja i obsluga naglowka   SetCaption i GetCaption sa in line
void __fastcall TDBComboFilter::ShowCaption(void)
{
 FlbCaption->Parent=FpaTop;
 FlbCaption->Left=5;
 FlbCaption->Top=5;
 FlbCaption->Width=Width;
 FlbCaption->Caption=Name;
 FlbCaption->Show();
}
//---------------------------------------------------------------------------
/*namespace Dbcombofilter
{
	void __fastcall PACKAGE Register()
	{
		TComponentClass classes[1] = {__classid(TDBComboFilter)};
		RegisterComponents("Data Controls", classes, 0);
	}
} */
//---------------------------------------------------------------------------
void __fastcall TDBComboFilter::OnResizeFilter(TObject * Sender)
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
void __fastcall TDBComboFilter::GotoNextOd(TObject * Sender,wchar_t& Key)
{
 if(Key =='\r' || Key =='\t')
   {
	FEditDo->SetFocus();
	Key=0;
   }
}
//---------------------------------------------------------------------------
void __fastcall TDBComboFilter::GotoNextDo(TObject * Sender,wchar_t& Key)
{
 if(OnKeyPress) OnKeyPress(Sender,Key);
}
//---------------------------------------------------------------------------
//Obsluga zdarzenia OEnter
void __fastcall TDBComboFilter::DoEnter(void)
{
 FEditOd->SetFocus();
 if(OnEnter) OnEnter(this);
}

//---------------------------------------------------------------------------
//Listy
UnicodeString __fastcall TDBComboFilter::GetList(void)
{
 UnicodeString Res("");
 UnicodeString Text1 =  FEditOd->Text;
 UnicodeString Text2 =  FEditDo->Text;
 if( !(Text1.IsEmpty() && (Text2.IsEmpty() ) ) )
   {
    Res = FEditOd->KeyField;
    Res += " BETWEEN ";
    Res += Text1;
    Res += " AND ";
    Res += Text2;
   }
 return Res;
}
//---------------------------------------------------------------------------
UnicodeString __fastcall TDBComboFilter::GetStringList(void)
{
 return GetList();
}
//---------------------------------------------------------------------------
//Nadpisuje Loaded wywolywany przez BCB przy ladowaniu komponentu ze strumienia
void __fastcall TDBComboFilter::Loaded(void)
{
 TPanel::Loaded();
 OnResizeFilter(this);
}
//---------------------------------------------------------------------------
//GetCondition jak wyzej tylko razem z dodanym z przodu predykatem WHERE
UnicodeString __fastcall TDBComboFilter::GetCondition(void)
{
 UnicodeString Res;
 UnicodeString StrList=GetStringList();
 if(!StrList.IsEmpty())
   {
    Res += " WHERE ";
    Res +=StrList;
   }
 return Res;
}

