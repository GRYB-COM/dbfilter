//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "DBLkpFil.h"
#include <DBCtrls.hpp>
#include <CheckLst.hpp>
#include <ExtCtrls.hpp>
#include "ItmFilt.h"
#include "LstFilt.h"
#include <Db.hpp>
#include <DBTables.hpp>
#include <Mask.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TTable *Table1;
        TDataSource *DataSource1;
        TTable *Table2;
        TDataSource *DataSource2;
        TDBLookupFilter *DBLookupFilter1;
        TDBListFilter *DBListFilter1;
private:	// User declarations
public:		// User declarations
        __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
