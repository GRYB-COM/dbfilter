//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "DBFilterTest.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "DBFil"
#pragma link "DBLkpFil"
#pragma link "LstFilt"
#pragma link "DBBetweenFilter"
#pragma link "DBDatesFilter"
#pragma link "DBEditsFilter"
#pragma link "DBLCombosFilter"
#pragma link "NumEditsFilter"
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
 Caption = AAA->SelectedKey;
}
//---------------------------------------------------------------------------

void __fastcall TForm3::AAAClick(TObject *Sender)
{
 Caption = AAA->AsSelectedKeys;
}
//---------------------------------------------------------------------------

