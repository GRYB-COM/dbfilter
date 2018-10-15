//---------------------------------------------------------------------------

#ifndef PropEditH
#define PropEditH
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#include <SysUtils.hpp>
#include <Controls.hpp>
#include <Classes.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <DB.hpp>
#include <DBTables.hpp>
#include <dbctrls.hpp>
#include <DesignEditors.hpp>
#include <Checklst.hpp>
//---------------------------------------------------------------------------
class PACKAGE TListFieldEditor:public TPropertyEditor
{
public:
 virtual TPropertyAttributes __fastcall   GetAttributes(void);
 virtual void __fastcall GetValues(Classes::TGetStrProc Proc);
 virtual UnicodeString __fastcall GetValue(void);
 virtual void __fastcall SetValue(const System::UnicodeString Value);
 virtual void __fastcall SetValue(const System::WideString Value);
};

//---------------------------------------------------------------------------
class PACKAGE TKeyFieldEditor:public TPropertyEditor
{
public:
 virtual TPropertyAttributes __fastcall   GetAttributes(void);
 virtual void __fastcall GetValues(Classes::TGetStrProc Proc);
 virtual UnicodeString __fastcall GetValue(void);
 virtual void __fastcall SetValue(const System::UnicodeString Value);
 virtual void __fastcall SetValue(const System::WideString Value);
};

class PACKAGE TBorderStyleEditor:public TPropertyEditor
{
public:
 virtual TPropertyAttributes __fastcall   GetAttributes(void);
 virtual void __fastcall GetValues(Classes::TGetStrProc Proc);
 virtual UnicodeString __fastcall GetValue(void);
 virtual void __fastcall SetValue(const System::UnicodeString Value);
 virtual void __fastcall SetValue(const System::WideString Value);
};
#endif

