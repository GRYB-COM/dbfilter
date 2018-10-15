//---------------------------------------------------------------------------

#ifndef DBFilterTestMainFormH
#define DBFilterTestMainFormH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "DBFil.h"
#include "DBLkpFil.h"
#include "ItmFilt.h"
#include <DBCtrls.hpp>
#include "LstFilt.h"
#include <ExtCtrls.hpp>
#include "DBBetweenFilter.h"
#include "NumEditsFilter.h"
#include "DBLCombosFilter.h"
//---------------------------------------------------------------------------
class TForm3 : public TForm
{
__published:	// IDE-managed Components
	TDBListFilter *DBListFilter1;
	TDBItemFilter *DBItemFilter1;
	TNumEditsFilter *NumEditsFilter1;
	TDBLCombosFilter *DBLCombosFilter1;
	TButton *Button1;
	void __fastcall Button1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm3(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm3 *Form3;
//---------------------------------------------------------------------------
#endif
