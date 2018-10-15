//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "DBLkpFil.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------
// ValidCtrCheck is used to assure that the components created do not have
// any pure virtual functions.
//

static inline void ValidCtrCheck(TDBLookupFilter *)
{
        new TDBLookupFilter(NULL);
}
 //konstruktor i destruktor
//---------------------------------------------------------------------------
__fastcall TDBLookupFilter::TDBLookupFilter(TComponent* Owner)
        : TDBFilter(Owner)
{

 //lista
 FCheckListBox = new TCheckListBox(this);
 FpaBottom->Align=alBottom;
 FpaBottom->Height =32;
 FCheckListBox->Parent=this;
 FCheckListBox->Align=alClient;
 FCheckListBox->ParentColor=false;
  FCheckListBox->Color=clWindow;
 FCheckListBox->ParentFont=true;
 FCheckListBox->ParentShowHint=true;
 FCheckListBox->Flat=false;
 FCheckListBox->Show();
 FCheckListBox->OnClick=DBFilterClick;
 FCheckListBox->OnKeyPress=ListKeyPress;
 FCheckListBox->Name = "CheckListBox";
//Buttony
 FbtAll    = new TBitBtn(this);
 FbtNone   = new TBitBtn(this);
 FbtReverse= new TBitBtn(this);

 FbtAll->Name="btAll";
 FbtNone->Name="btNone";
 FbtReverse->Name="btReverse";

 FbtAll->Parent    =FpaBottom;
 FbtNone->Parent   =FpaBottom;
 FbtReverse->Parent=FpaBottom;

 FbtAll->Caption    ="Wszystkie";
 FbtNone->Caption   ="¯adne";
 FbtReverse->Caption="Zamieñ";
 FbtAll->OnClick=btAllClick;
 FbtNone->OnClick=btNoneClick;
 FbtReverse->OnClick=btReverseClick;
 FbtAll->Align= alLeft;
 FbtReverse->Align= alRight;
 FbtNone->Align= alClient;
 FbtAll->Show();
 FbtNone->Show();
 FbtReverse->Show();

 DrawButtons();
//obsuga zdarzeñ
 FpaBottom->OnResize=DBFilterResize;

}
//---------------------------------------------------------------------------
__fastcall TDBLookupFilter::~TDBLookupFilter(void)
{
 delete FCheckListBox;
}
//---------------------------------------------------------------------------
void __fastcall TDBLookupFilter::btAllClick(TObject *Sender)
{
 CheckAll(true);
 if(OnClick) OnClick(Sender);
}
//---------------------------------------------------------------------------
void __fastcall TDBLookupFilter::btNoneClick(TObject *Sender)
{
 CheckAll(false);
 if(OnClick) OnClick(Sender);
}
//---------------------------------------------------------------------------
void __fastcall TDBLookupFilter::btReverseClick(TObject *Sender)
{
 Reverse();
 if(OnClick) OnClick(Sender);
}
//---------------------------------------------------------------------------
void __fastcall TDBLookupFilter::CheckAll(bool Select)
{
 int i=0;
 for(i=0;i<FCheckListBox->Items->Count;i++)
    {
     FCheckListBox->Checked[i]=Select;
    }
}
//---------------------------------------------------------------------------
bool __fastcall TDBLookupFilter::GetCheckedItem(int Indx)
{
 return FCheckListBox->Checked[Indx];
}
//---------------------------------------------------------------------------
void __fastcall TDBLookupFilter::SetCheckedItem(int Indx, bool Chck)
{
 FCheckListBox->Checked[Indx]=Chck;
}
//---------------------------------------------------------------------------
void __fastcall TDBLookupFilter::DBFilterResize(TObject* Sender)
{
   DrawButtons();
}
//---------------------------------------------------------------------------
void __fastcall TDBLookupFilter::DBFilterClick(TObject* Sender)
{
  SingleChose();
  if(OnClick)
     {
      OnClick(Sender);
     }
}
//---------------------------------------------------------------------------
void __fastcall TDBLookupFilter::DoEnter(void)
{
 TControl* _Act(NULL);
 TForm*    _Form(NULL);
 if(Owner)
 {
  _Form = dynamic_cast<TForm*>(Owner);
  if(_Form) _Act = _Form->ActiveControl;
 }
 if(_Act != FbtAll && _Act !=FbtNone && _Act!= FbtReverse)
 {
  FCheckListBox->SetFocus();
 }
 //if(FCheckListBox->Items->Count>0)FCheckListBox->ItemIndex=0;
 if(OnEnter) OnEnter(this);
}
//---------------------------------------------------------------------------
void __fastcall TDBLookupFilter::DoExit(void)
{
 FCheckListBox->ItemIndex=-1;
 TDBFilter::DoExit();
}
//---------------------------------------------------------------------------

void inline  __fastcall TDBLookupFilter::ListKeyPress(TObject* Sender, wchar_t& Key)
{
 if(OnKeyPress) OnKeyPress(Sender,Key);
}
//---------------------------------------------------------------------------
void __fastcall TDBLookupFilter::DrawButtons(void)
{
 int BtnWidth=0; 

    while(BtnWidth <= FbtNone->Width)
      {
       FbtAll->Width=BtnWidth;
       FbtReverse->Width=BtnWidth;
       BtnWidth++;
      }
}
//---------------------------------------------------------------------------
bool __fastcall TDBLookupFilter::GetChecked(void)
{
 bool Res(false);
 int i(0);
 for(i=0;i<FCheckListBox->Items->Count;i++)
    {
     if(FCheckListBox->Checked[i]==true)Res=true;
    }
 return Res;
}
//---------------------------------------------------------------------------
bool __fastcall TDBLookupFilter::GetAllChecked(void)
{
 bool Res(true);
 int i(0);
 for(i=0;i<FCheckListBox->Items->Count;i++)
    {
     if(FCheckListBox->Checked[i]==false)
       {
        Res=false;
        break;
       }
    }
 return Res;
}

//---------------------------------------------------------------------------
int __fastcall TDBLookupFilter::GetItemsCount(void)
{
 return FCheckListBox->Items->Count;
}
//---------------------------------------------------------------------------
TNotifyEvent __fastcall TDBLookupFilter::GetOnClick(void)
{
 return FCheckListBox->OnClick;
}
//---------------------------------------------------------------------------
int __fastcall TDBLookupFilter::GetSelected(void)
{
 int Count(0);
 for(int i=0;i<FCheckListBox->Items->Count;i++)
    {
     if(FCheckListBox->Checked[i]) Count++;
    }
 return Count;
}
//---------------------------------------------------------------------------
UnicodeString __fastcall TDBLookupFilter::GetSelectedKey(void)
{
 UnicodeString Res("Zwraca wartoœæ zaznaczonego wiersza funkcja GetSelectedKey");
 try
 {
  if( ComponentState.Contains(csDesigning) ) return Res;
  Res="";
  int Indx(-1);
   if(FSingle)
   {
	for(int i =0; i< FCheckListBox->Items->Count;i++)
	{
	 if(FCheckListBox->Checked[i])
	 {
	  Indx=i;
	  break;
	 }
	}
	 Res=GetKey(Indx);
	}
 }
 catch(Exception& exc)
 {
  exc.Message = exc.Message + "UnicodeString __fastcall TDBLookupFilter::GetSelectedKey(void)\n";
 }
 return Res;   
}
//---------------------------------------------------------------------------
UnicodeString __fastcall TDBLookupFilter::GetSelectedValues(void)
{
 UnicodeString Res("Lista wartoœci po przecinkach");
 if( ComponentState.Contains(csDesigning) ) return Res;
 int Range=FCheckListBox->Items->Count;
 int i(0);
 Res="";
 for(i=0;i<Range;i++)
    {
     if(FCheckListBox->Checked[i])
       {
        Res+=FCheckListBox->Items->Strings[i];
        Res=Res.Trim();
        Res+= ", ";
       }
    }
 Res=Res.SubString(1,Res.Length()-2);
 return Res;
}
//---------------------------------------------------------------------------
void __fastcall TDBLookupFilter::Reverse(void)
{
 int i=0;
 for(i=0;i<FCheckListBox->Items->Count;i++)
    {
     if(FCheckListBox->Checked[i])
       {
        FCheckListBox->Checked[i]=false;
       }
     else
       {
        FCheckListBox->Checked[i]=true;
       }
    }
}
//---------------------------------------------------------------------------

void __fastcall TDBLookupFilter::SetBorderStyle(Forms::TFormBorderStyle BorderStyle)
{
 TDBFilter::SetBorderStyle(BorderStyle);
  FCheckListBox->BorderStyle=(Forms::TFormBorderStyle)BorderStyle;
}
//---------------------------------------------------------------------------
void __fastcall TDBLookupFilter::SetEnabled(bool aEnabled)
{
 TDBFilter::SetEnabled(aEnabled);
 FCheckListBox->Enabled=aEnabled;
 FpaBottom->Enabled=aEnabled;
 FbtAll->Visible=aEnabled;
 FbtNone->Visible=aEnabled;
 FbtReverse->Visible=aEnabled;
 if(aEnabled) FCheckListBox->Color=clWindow;
 else  FCheckListBox->Color=Color;
}
//---------------------------------------------------------------------------
void __fastcall TDBLookupFilter::SetOnClick(TNotifyEvent  Event)
{
 FCheckListBox->OnClick=Event;
}
//---------------------------------------------------------------------------
void __fastcall TDBLookupFilter::SetSingle(bool aSingle)
{
 FSingle=aSingle;
 FpaBottom->Visible = !aSingle;
 if(aSingle)  CheckAll(false);
}
//---------------------------------------------------------------------------
void __fastcall TDBLookupFilter::SingleChose(void)
{
 int i(0);
 for(i=0;i<FCheckListBox->Items->Count;i++)
    {
     if((!FCheckListBox->Selected[i]) && Single)
        {
         FCheckListBox->Checked[i]=false;
        }
    }
}

