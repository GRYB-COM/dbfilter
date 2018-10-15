//---------------------------------------------------------------------------

#ifndef ItmFiltH
#define ItmFiltH
//---------------------------------------------------------------------------
#include <SysUtils.hpp>
#include <Controls.hpp>
#include <Classes.hpp>
#include <Forms.hpp>
#include "dblkpfil.h"
#include <DBCtrls.hpp>
//---------------------------------------------------------------------------
class PACKAGE TDBItemFilter : public TDBLookupFilter
{
private:
 TStrings* FValues;
 virtual  void __fastcall SetValues(TStrings * Values);
 virtual  void __fastcall SetItems(TStrings * aStrings);
protected:
virtual UnicodeString __fastcall GetList(void);
virtual UnicodeString __fastcall GetKey(int Indx);
virtual UnicodeString __fastcall GetSelectedKeys(void );
public:
        __fastcall TDBItemFilter(TComponent* Owner);
        __fastcall ~TDBItemFilter(void);
__published:
      __property AsStringList;
      __property AsCondition;
      __property Items;
      __property  TStrings * Values={read=FValues,write=SetValues};
};
//---------------------------------------------------------------------------
#endif
