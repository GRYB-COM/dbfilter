//---------------------------------------------------------------------------

#include <vcl.h>                       
#pragma hdrstop
#include "LstFilt.h"
#pragma link "DBLkpFil"
#pragma package(smart_init)
const UnicodeString ListSourceErr= "W³aœciwoœæ ListSource nie ma wartoœci";
const UnicodeString DataSetErr= "W³aœciwoœæ DataSet z ListSource nie ma wartoœci";
//---------------------------------------------------------------------------
// ValidCtrCheck is used to assure that the components created do not have
// any pure virtual functions.                                                                      
static inline void ValidCtrCheck(TDBListFilter *)
{
        new TDBListFilter(NULL);
}
//---------------------------------------------------------------------------
__fastcall TDBListFilter::TDBListFilter(TComponent* Owner)
        : TDBLookupFilter(Owner)
{
}
//---------------------------------------------------------------------------
UnicodeString __fastcall TDBListFilter::FieldsValues(void)
{
 UnicodeString Res;
 UnicodeString FName;
 try{
 int FCount =FieldCount(ListField,';');
 for(int i=0; i<FCount;i++)
	{
	 FName= ReturnFieldName(i);
	 Res+=ListSource->DataSet->FieldByName( FName.Trim() )->AsString;
	 Res+=" ";
	}
 }catch(Exception & exc)
 {
  exc.Message = exc.Message + "\nUnicodeString __fastcall TDBListFilter::FieldsValues(void)";
  throw;
 }
 return Res;
}
//---------------------------------------------------------------------------
void __fastcall TDBListFilter::FillItems(void)
{
 try{
 Items->Clear();
 if(ListSource !=  NULL)
   {
	TDataSet* DataSet = ListSource->DataSet;
	if(DataSet != NULL)
	  {
	   if(DataSet->Active)
		 {
		  DataSet->First();
		  while(!DataSet->Eof)
			{
			 Items->Add(FieldsValues());
			 DataSet->Next();
			}
		  DataSet->First();

		}
	  }
   }
 }
 catch(Exception & exc)
 {
  exc.Message = exc.Message + "\nvoid __fastcall TDBListFilter::FillItems(void)";
  throw;
 }
}
//---------------------------------------------------------------------------
UnicodeString __fastcall TDBListFilter::GetKey(const int Indx)
{
 UnicodeString Res("Zwraca wartoœæ pola KeyField o indeksie Indx");
 if( ComponentState.Contains(csDesigning) ) return Res;
 Res="";
 bool IsActive;
 if(ListSource==NULL) throw EFilterExc(ListSourceErr);
 if(ListSource->DataSet==NULL) throw EFilterExc(DataSetErr);
 TDataSet * DataSet= ListSource->DataSet;
 IsActive=DataSet->Active;
 DataSet->Open();
 DataSet->First();
 DataSet->MoveBy(Indx);
 Res = DataSet->FieldByName(KeyField)->AsString;
 DataSet->Active=IsActive;
 return Res;
}
//---------------------------------------------------------------------------
 UnicodeString __fastcall TDBListFilter::GetListField(void)
 {
  UnicodeString Res =TDBLookupFilter::ListField;
  return Res;
 }
//---------------------------------------------------------------------------
void __fastcall TDBListFilter::DataChange(TObject* Sender)
{
 FillItems();
}
//---------------------------------------------------------------------------
void __fastcall TDBListFilter::SetListField(UnicodeString aListField)
 {
  try{
    UnicodeString Res =aListField;
	TDBLookupFilter::ListField=aListField;

  }
  catch(EDatabaseError &E)
    {
	 E.Message = E.Message + "\nvoid __fastcall TDBListFilter::SetListField(UnicodeString aListField)";
	 TDBLookupFilter::ListField="";
      Application->ShowException(&E);

    }

 }
//---------------------------------------------------------------------------
int __fastcall TDBListFilter::FieldCount(UnicodeString aListField,char aChar)
{
 int Count(0);
 try{
 int Len =aListField.Length();
 for(int i=1;i<Len;i++)
	{
	 if(aListField[i]==aChar) Count++;
	}
 if(!aListField.IsEmpty()) Count++;
 }
 catch(Exception & exc)
 {
  exc.Message = exc.Message + "\nint __fastcall TDBListFilter::FieldCount(UnicodeString aListField,char aChar)";
  throw;
 }
 return Count;
}
//---------------------------------------------------------------------------
UnicodeString __fastcall TDBListFilter::ReturnFieldName(int Index)
{
 UnicodeString Res;
 try{
 Res=ListField;
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
  }
 catch(Exception & exc)
 {
  exc.Message = exc.Message + "\nUnicodeString __fastcall TDBListFilter::ReturnFieldName(int Index)";
  throw;
 }
 return Res;
}
//---------------------------------------------------------------------------
void __fastcall TDBListFilter::Refresh(void)
{
 try{
 if(!ListField.IsEmpty())
   {
	FillItems();
   }
 }
 catch(Exception & exc)
 {
  exc.Message = exc.Message + "\nvoid __fastcall TDBListFilter::Refresh(void)";
  throw;
 }
}
//---------------------------------------------------------------------------
UnicodeString __fastcall TDBListFilter::GetList(void)
{
 UnicodeString Res("Lista wartoœci w ciutkach po przecinkach");
 try{
  if( ComponentState.Contains(csDesigning) ) return Res;
 bool IsActive;
 int i(0);
 if(ListSource==NULL) throw EFilterExc(ListSourceErr);
 if(ListSource->DataSet==NULL) throw EFilterExc(DataSetErr);
 TDataSet * DataSet= ListSource->DataSet;
 IsActive=DataSet->Active;
 DataSet->Open();
 DataSet->First();
 Res="";
 while(!DataSet->Eof)
	 {
      if(FCheckListBox->Checked[i])
         {
          Res+="'";
          Res +=DataSet->FieldByName(KeyField)->AsString;
          Res+="'";
          Res +=",";
         }
      i++;
      DataSet->Next();
     }
  DataSet->Active=IsActive;
 }
 catch(Exception & exc)
 {
  exc.Message = exc.Message + "\nUnicodeString __fastcall TDBListFilter::GetList(void)";
  throw;
 }
 return Res.SetLength(Res.Length()-1);
}
//---------------------------------------------------------------------------
UnicodeString __fastcall TDBListFilter::GetSelectedKeys(void)
{
 UnicodeString Res("Lista wartoœci po przecinkach");
 try{
 if( ComponentState.Contains(csDesigning) ) return Res;
 bool IsActive;
 int i(0);
 if(ListSource==NULL) throw EFilterExc(ListSourceErr);
 if(ListSource->DataSet==NULL) throw EFilterExc(DataSetErr);
 TDataSet * DataSet= ListSource->DataSet;
 IsActive=DataSet->Active;
 DataSet->Open();
 DataSet->First();
 Res="";
 while(!DataSet->Eof)
	 {
      if(FCheckListBox->Checked[i])
         {
          Res +=DataSet->FieldByName(KeyField)->AsString;
          Res +=", ";
         }
      i++;
      DataSet->Next();
     }
  DataSet->Active=IsActive;
 }
 catch(Exception & exc)
 {
  exc.Message = exc.Message + "\nUnicodeString __fastcall TDBListFilter::GetSelectedKeys(void)";
  throw;
 }
 return Res.SetLength(Res.Length()-2);
}
//---------------------------------------------------------------------------
void __fastcall TDBListFilter::UpdateListFields(void)
{
 try{
 TDBLookupControl::UpdateListFields();
 FillItems();
 }
 catch(Exception & exc)
 {
  exc.Message = exc.Message + "\nvoid __fastcall TDBListFilter::UpdateListFields(void)";
  throw;
 }
}
//---------------------------------------------------------------------------
/*namespace Lstfilt
{
		void __fastcall PACKAGE Register()
		{
				 TComponentClass classes[1] = {__classid(TDBListFilter)};
				 RegisterComponents("Data Controls", classes, 0);
		}
} */
//---------------------------------------------------------------------------
