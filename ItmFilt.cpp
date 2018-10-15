//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "ItmFilt.h"
#pragma link "DBLkpFil"
#pragma package(smart_init)
const UnicodeString ItemValErr="Items i Values nie maj¹ tej samej iloœci linii";
//---------------------------------------------------------------------------
// ValidCtrCheck is used to assure that the components created do not have
// any pure virtual functions.
//

static inline void ValidCtrCheck(TDBItemFilter *)
{
        new TDBItemFilter(NULL);
}
//---------------------------------------------------------------------------
__fastcall TDBItemFilter::TDBItemFilter(TComponent* Owner)
        : TDBLookupFilter(Owner)
{
 FValues = (TStrings*) new TStringList();
}
//---------------------------------------------------------------------------
__fastcall TDBItemFilter::~TDBItemFilter(void)
{
 delete FValues;
}
//---------------------------------------------------------------------------
UnicodeString __fastcall TDBItemFilter::GetKey(int Indx)
{
 if( ComponentState.Contains(csDesigning) ) return UnicodeString("Wartoœæ z wiersza o podanym indeksie");
 UnicodeString _Res("");
 if(Indx >= 0 && Indx < FValues->Count)
 {
   //LINIA TESTOWA
	 _Res = FValues->Strings[Indx];
 }
 return _Res;
}
//---------------------------------------------------------------------------
void __fastcall TDBItemFilter::SetValues(TStrings* aValues)
{
 FValues->Assign(aValues);
 if(FValues->Count != Items->Count) throw EFilterExc(ItemValErr);
}
//---------------------------------------------------------------------------
void __fastcall TDBItemFilter::SetItems(TStrings* aValues)
{
 TDBLookupFilter::Items->Assign(aValues);
 if(FValues->Count <1) FValues->Assign(aValues);
 if(FValues->Count != Items->Count) throw EFilterExc(ItemValErr);
}
//---------------------------------------------------------------------------
UnicodeString __fastcall TDBItemFilter::GetList(void)
{
 if( ComponentState.Contains(csDesigning) ) return UnicodeString("Lista zaznaczonych wartoœci w ciutkach");
 UnicodeString Res;
 if(Items->Count != Values->Count) throw EFilterExc(ItemValErr);
  int Count = Items->Count > Values->Count?Values->Count:Items->Count;
  for(int i=0;i<Count;i++)
	 {
	  if(FCheckListBox->Checked[i])
		{
		 Res+="'";
		 Res+=Values->Strings[i];
		 Res+="'";
		 Res+=",";
		}
	 }

  return Res.SetLength(Res.Length()-1);
}
//---------------------------------------------------------------------------
UnicodeString __fastcall TDBItemFilter::GetSelectedKeys(void)
{
 if( ComponentState.Contains(csDesigning) ) return UnicodeString("Lista zaznaczonych wartoœci bez ciutków");
 UnicodeString Res;
 if(Items->Count != Values->Count) throw EFilterExc(ItemValErr);
  int Count = Items->Count > Values->Count?Values->Count:Items->Count;
  for(int i=0;i<Count;i++)
     {
      if(FCheckListBox->Checked[i])
        {
         Res+=Values->Strings[i];
         Res+=", ";
        }
     }

  return Res.SetLength(Res.Length()-2);
}
//---------------------------------------------------------------------------
/*namespace Itmfilt
{
        void __fastcall PACKAGE Register()
        {
                 TComponentClass classes[1] = {__classid(TDBItemFilter)};
                 RegisterComponents("Data Controls", classes, 0);
        }
} */
