//---------------------------------------------------------------------------

#ifndef DBLCombosFilterH
#define DBLCombosFilterH
//---------------------------------------------------------------------------
#include <SysUtils.hpp>
#include <Controls.hpp>
#include <Classes.hpp>
#include <Forms.hpp>
#include "DBBetweenFilter.h"
#include "DBFil.h"
#include "dbbetweenfilter.h"
//---------------------------------------------------------------------------
class PACKAGE TDBLCombosFilter : public TDBBetweenFilter
{
private:
protected:
//utworxenie combo wywolywane w przodku
virtual void __fastcall CreateEdit(void);
//wartosci z
UnicodeString __fastcall FieldsValues(void);
virtual UnicodeString __fastcall ReturnFieldName(int Indx);
virtual int __fastcall FieldCount(UnicodeString aFieldCount, char Sep);
void       __fastcall FillItems(void);
public:
	__fastcall TDBLCombosFilter(TComponent* Owner);
__published:
};
//---------------------------------------------------------------------------
#endif
