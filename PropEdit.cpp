//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include <assert.h>
#pragma package(smart_init)
#include "propedit.h"
#include "DBLkpFil.h"
#include "LstFilt.h"
#include "ItmFilt.h"
#include "DBMEDIT.h"
#include "DBDateFilter.h"
#include "DBDatesFilter.h"
#include "DBEditFilter.h"
#include "DBEditsFilter.h"
#include "NumEditsFilter.h"
#include "DBLCombosFilter.h"
#include "DBComboFilter.h"
#include "ItmFilt.h"
#include "NumEdit.h"
 #include <maskprop.hpp>
 #include <dialogs.hpp>
const UnicodeString SNeed("DataSource needed");
const UnicodeString DNeed("DataSet in DataSource needed");
//---------------------------------------------------------------------------
//#pragma package(smart_init)
//---------------------------------------------------------------------------
//TListFieldEditor
//Ustawienie edytora pola DataField na Listê rozwijann¹
TPropertyAttributes __fastcall TListFieldEditor:: GetAttributes(void)
{
 return TPropertyAttributes()<<paValueList;
}
//---------------------------------------------------------------------------
void __fastcall TListFieldEditor::GetValues(TGetStrProc Proc)
{
 bool IsActive;
 TDBLookupFilter* EdObject =(TDBLookupFilter*) GetComponent(0);
 TDataSource * DataSource =EdObject->ListSource;
 if(DataSource!=NULL)
   {
	TDataSet * DataSet = EdObject->ListSource->DataSet;
	if(DataSet!=NULL && DataSet->Active)
	{
	   for(int i= 0;i<DataSet->FieldCount;i++)
	   {
		Proc(DataSet->Fields->Fields[i]->FieldName);
	   }
	}
	else
	{
	   Proc(DNeed);
	}
   }
 else
   {
    Proc(SNeed);
   }
}
//---------------------------------------------------------------------------

UnicodeString __fastcall TListFieldEditor::GetValue(void)
{
 UnicodeString FieldName("");
 FieldName  = ((TDBListFilter*) GetComponent(0))->ListField;
 return FieldName;
}
//---------------------------------------------------------------------------
void __fastcall TListFieldEditor::SetValue(const UnicodeString aValue)
{
 try
   {
    if( !(aValue == SNeed || aValue == DNeed) )
      {
       ((TDBListFilter*) GetComponent(0))->ListField=aValue;
      }
    else
      {
       ((TDBListFilter*) GetComponent(0))->ListField="";
      }
   }
  catch(...)
   {
      ((TDBListFilter*) GetComponent(0))->ListField="";
   }
}
//---------------------------------------------------------------------------
void __fastcall TListFieldEditor::SetValue(const WideString aValue)
{
 try
   {
    if( !(aValue == SNeed || aValue == DNeed) )
      {
       ((TDBListFilter*) GetComponent(0))->ListField=aValue;
      }
    else
      {
       ((TDBListFilter*) GetComponent(0))->ListField="";
      }
   }
  catch(...)
   {
      ((TDBListFilter*) GetComponent(0))->ListField="";
   }
}
//---------------------------------------------------------------------------
//TKeyFieldEditor
//Ustawienie edytora pola DataField na Listê rozwijann¹
TPropertyAttributes __fastcall TKeyFieldEditor:: GetAttributes(void)
{
 return TPropertyAttributes()<<paValueList;
}
//---------------------------------------------------------------------------
void __fastcall TKeyFieldEditor::GetValues(TGetStrProc Proc)
{
 bool IsActive;
 TDBLookupFilter* EdObject =(TDBLookupFilter*) GetComponent(0);
 TDataSource * DataSource =EdObject->ListSource;
 if(DataSource!=NULL)
   {
    TDataSet * DataSet = EdObject->ListSource->DataSet;
    if(DataSet!=NULL)
      {
       IsActive =DataSet->Active;
       DataSet->Close();
       DataSet->Open();
       for(int i= 0;i<DataSet->FieldCount;i++)
          {
           Proc(DataSet->Fields->Fields[i]->FieldName);
          }
       DataSet->Active=IsActive;
      }
    else
      {
       Proc(DNeed);
      }
   }
 else
   {
    Proc(SNeed);
   }

}
//---------------------------------------------------------------------------

UnicodeString __fastcall TKeyFieldEditor::GetValue(void)
{
 UnicodeString FieldName("");
 FieldName  = ((TDBLookupFilter*) GetComponent(0))->KeyField;
 return FieldName;
}
//---------------------------------------------------------------------------

void __fastcall TKeyFieldEditor::SetValue(UnicodeString aValue)
{
 if( !(aValue == SNeed || aValue == DNeed) )
   {
    ((TDBLookupFilter*) GetComponent(0))->KeyField=aValue;
   }
 else
   {
    ((TDBLookupFilter*) GetComponent(0))->KeyField="";
   }
}
//---------------------------------------------------------------------------
void __fastcall TKeyFieldEditor::SetValue(WideString aValue)
{
 if( !(aValue == SNeed || aValue == DNeed) )
   {
    ((TDBLookupFilter*) GetComponent(0))->KeyField=aValue;
   }
 else
   {
    ((TDBLookupFilter*) GetComponent(0))->KeyField="";
   }
}
//---------------------------------------------------------------------------
//TBorderStyleEditor
//Ustawienie edytora pola DataField na Listê rozwijann¹
TPropertyAttributes __fastcall TBorderStyleEditor:: GetAttributes(void)
{
 return TPropertyAttributes()<<paValueList;
}
//---------------------------------------------------------------------------
void __fastcall TBorderStyleEditor::GetValues(TGetStrProc Proc)
{
  PTypeInfo EnumType;
  EnumType = GetPropType();
  Proc(GetEnumName(EnumType, 0));
  Proc(GetEnumName(EnumType, 1));
}
//---------------------------------------------------------------------------

UnicodeString __fastcall TBorderStyleEditor::GetValue(void)
{
  int L;
  L = GetOrdValue();
  return GetEnumName(GetPropType(), L);
}
//---------------------------------------------------------------------------

void __fastcall TBorderStyleEditor::SetValue(UnicodeString aValue)
{
 int  I;
 I = GetEnumValue(GetPropType(), aValue);
 SetOrdValue(I);
}
//---------------------------------------------------------------------------
void __fastcall TBorderStyleEditor::SetValue(WideString aValue)
{
 int  I;
 I = GetEnumValue(GetPropType(), aValue);
 SetOrdValue(I);
}

//---------------------------------------------------------------------------
PTypeInfo EditMaskTypeInfo(void)
{
  PPTypeInfo Temp;

  Temp = GetPropInfo(__typeinfo(TDBMaskEdit), "EditMask")->PropType;
  assert(Temp != NULL);

  return *Temp;
}
//---------------------------------------------------------------------------
void static inline dummy(void)
{
	static const TTypeInfo  * _TypInf =  __typeinfo(TDBDatesFilter);
	_TypInf =  __typeinfo(TDBItemFilter);
	_TypInf =  __typeinfo(TNumEditsFilter);
	_TypInf =  __typeinfo(TDBLCombosFilter);
	_TypInf =  __typeinfo(TNumEdit);
}
//---------------------------------------------------------------------------
PTypeInfo ListFilterTypeInfo(UnicodeString FieldName)
{
  PPTypeInfo Temp;

  Temp = GetPropInfo(__typeinfo(TDBListFilter), FieldName)->PropType;
  assert(Temp != NULL);
  return *Temp;
}
PTypeInfo DBFilterTypeInfo(UnicodeString FieldName)
{
  PPTypeInfo Temp;

  Temp = GetPropInfo(__typeinfo(TDBListFilter), FieldName)->PropType;
  assert(Temp != NULL);
  return *Temp;
}
//---------------------------------------------------------------------------
namespace Propedit
{
		void __fastcall PACKAGE Register()
		{
		 TComponentClass classes[10] = {
										__classid(TNumEditsFilter), __classid(TDBComboFilter), __classid(TDBLCombosFilter),
										__classid(TDBDateFilter),   __classid(TDBDatesFilter), __classid(TDBMaskEdit),
										__classid(TDBEditFilter),   __classid(TDBEditsFilter),
										__classid(TDBListFilter),   __classid(TDBItemFilter)
									  };

		 RegisterComponents("Data Controls", classes, 9);
		 dummy();

				 RegisterPropertyEditor(ListFilterTypeInfo("ListField"),
								   __classid(TDBFilter),
								  "ListField",
								   __classid(TListFieldEditor)
									  );
				 RegisterPropertyEditor(ListFilterTypeInfo("KeyField"),
								   __classid(TDBLookupFilter),
								  "KeyField",
								   __classid(TKeyFieldEditor)
									  );

//				 RegisterPropertyEditor(EditMaskTypeInfo(),
//								   __classid(TDBMaskEdit),
//								  "EditMask",
//								   __classid(TMaskProperty)
//									  );

				 RegisterPropertyEditor(DBFilterTypeInfo("BorderStyle"),
								   __classid(TDBFilter),
								  "BorderStyle",
								   __classid(TBorderStyleEditor)
									  );

		}
}




