//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "DBFilterTestMainForm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "DBBetweenFilter"
#pragma link "NumEditsFilter"
#pragma link "DBLCombosFilter"
#pragma resource "*.dfm"
TForm3 *Form3;
//---------------------------------------------------------------------------
__fastcall TForm3::TForm3(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm3::Button1Click(TObject *Sender)
{
 bool _Is = DBItemFilter1->IsAllChecked;
 UnicodeString _S = DBItemFilter1->SelectedKey;
}
//---------------------------------------------------------------------------

