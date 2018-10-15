//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "DBItemFilterTest.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "DBFil"
#pragma link "DBLkpFil"
#pragma link "ItmFilt"
#pragma link "LstFilt"
#pragma resource "*.dfm"
TForm2 *Form2;
//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
