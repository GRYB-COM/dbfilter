//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "DBLCombosFilter.h"
#pragma link "DBBetweenFilter"
#pragma link "DBFil"
#pragma package(smart_init)
//---------------------------------------------------------------------------
// ValidCtrCheck is used to assure that the components created do not have
// any pure virtual functions.
//

static inline void ValidCtrCheck(TDBLCombosFilter *)
{
	new TDBLCombosFilter(NULL);
}
//---------------------------------------------------------------------------
__fastcall TDBLCombosFilter::TDBLCombosFilter(TComponent* Owner)
	: TDBBetweenFilter(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TDBLCombosFilter::CreateEdit(void)
{
 TDBBetweenFilter::CreateEdit();
 FEditOd = new TComboBox(this);
 FEditDo = new TComboBox(this);
}
//---------------------------------------------------------------------------
UnicodeString __fastcall TDBLCombosFilter::FieldsValues(void)
{
 UnicodeString Res;
 UnicodeString FName;
 int FCount =FieldCount(ListField,';');
 for(int i=0; i<FCount;i++)
    {
     FName= ReturnFieldName(i);
     Res+=ListSource->DataSet->FieldByName(FName)->AsString;
     Res+=" ";
    }
 return Res;
}
//---------------------------------------------------------------------------
UnicodeString __fastcall TDBLCombosFilter::ReturnFieldName(int Index)
{
 UnicodeString Res=ListField;
 UnicodeString FList=ListField;
 int FCount =FieldCount(ListField,';');

 int Indx(0);
 int FIndx(0);
 for(int i=0;i<FCount;i++)
      {
       Indx=FList.Pos(";");
       if(Indx>0)
         {
          Res=FList.SubString(1,Indx-1);
          FList.Delete(1,Indx);
          if(FIndx==Index)
            {
             break;
            }
          else
            {
             FIndx++;
            }
         }
       else
         {
          Res=FList;
         }
      }
 return Res;
}
int __fastcall TDBLCombosFilter::FieldCount(UnicodeString aListField,char aChar)
{
 int Count(0);
 int Len =aListField.Length();
 for(int i=1;i<Len;i++)
    {
     if(aListField[i]==aChar) Count++;
    }
 if(!aListField.IsEmpty()) Count++;
 return Count;
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
/*namespace Dblcombosfilter
{
	void __fastcall PACKAGE Register()
	{
		TComponentClass classes[1] = {__classid(TDBLCombosFilter)};
		RegisterComponents("Data Controls", classes, 0);
	}
}  */
//---------------------------------------------------------------------------
