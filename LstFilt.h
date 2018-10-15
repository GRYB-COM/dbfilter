//---------------------------------------------------------------------------

#ifndef LstFiltH
#define LstFiltH
//---------------------------------------------------------------------------
#include <SysUtils.hpp>
#include <Controls.hpp>
#include <Classes.hpp>
#include <Forms.hpp>
#include "dblkpfil.h"
#include <DBCtrls.hpp>
//---------------------------------------------------------------------------
class PACKAGE TDBListFilter : public TDBLookupFilter
{
private:
 void       __fastcall SetListField(UnicodeString aListField);
 UnicodeString __fastcall GetListField(void);
 void       __fastcall DataChange(TObject * Sender);
 //Liczy pola w aListField oddzielone aChar
 int            __fastcall FieldCount(UnicodeString aListField, char aChar);
 UnicodeString     __fastcall ReturnFieldName(int Index);
protected:
//wartosci pol
UnicodeString __fastcall FieldsValues(void);
virtual UnicodeString __fastcall GetList(void);
void       __fastcall FillItems(void);
virtual void __fastcall UpdateListFields(void);
virtual UnicodeString __fastcall GetKey( const int Indx);
//nadpisane z DBFIL
virtual UnicodeString __fastcall GetSelectedKeys(void );
public:
        __fastcall TDBListFilter(TComponent* Owner);
virtual void __fastcall Refresh(void);

__published:
        __property KeyField;
	__property ListField={read=GetListField,write=SetListField} ;
	__property ListFieldIndex ;
	__property ListSource ;


};
//---------------------------------------------------------------------------
#endif
