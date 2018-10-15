//---------------------------------------------------------------------------

#ifndef DBFilterTestH
#define DBFilterTestH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Data.DB.hpp>
#include <Datasnap.DBClient.hpp>
#include "DBFil.h"
#include "DBLkpFil.h"
#include "LstFilt.h"
#include <Vcl.DBCtrls.hpp>
#include "DBBetweenFilter.h"
#include "DBDatesFilter.h"
#include "DBEditsFilter.h"
#include "DBLCombosFilter.h"
#include "NumEditsFilter.h"
//---------------------------------------------------------------------------
class TForm3 : public TForm
{
__published:	// IDE-managed Components
	TClientDataSet *ClientDataSet1;
	TDBListFilter *AAA;
	TDataSource *DataSource1;
	TLabel *Label2;
	TButton *Button1;
	TNumEditsFilter *NumEditsFilter1;
	TDBLCombosFilter *DBLCombosFilter1;
	TNumEditsFilter *NumEditsFilter2;
	TDBEditsFilter *DBEditsFilter1;
	TDBDatesFilter *DBDatesFilter1;
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall AAAClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm3(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm3 *Form3;
//---------------------------------------------------------------------------
#endif
