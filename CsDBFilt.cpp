//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include<TypInfo.hpp>
#include <assert.h>
#include <dbfilter.h>
#pragma package(smart_init)
const UnicodeString SNeed("DataSource needed");
const UnicodeString DNeed("DataSet in DataSource needed");
//---------------------------------------------------------------------------
// ValidCtrCheck is used to assure that the components created do not have
// any pure virtual functions.
//

static inline void ValidCtrCheck(TCustomDBFilter *)
{
        new TCustomDBFilter(NULL);
}
//---------------------------------------------------------------------------
__fastcall TCustomDBFilter::TCustomDBFilter(TComponent* Owner)
        : TPanel(Owner)
{
 FDataLink= new TFieldDataLink();
 FDataLink->Control=this;
}
//---------------------------------------------------------------------------
__fastcall TCustomDBFilter::~TCustomDBFilter()
{
 FDataLink->Control=NULL;
 delete FDataLink;
}
//---------------------------------------------------------------------------
UnicodeString __fastcall TCustomDBFilter::GetDataField()

{
  return FDataLink->FieldName;
}
//---------------------------------------------------------------------------
TDataSource *__fastcall TCustomDBFilter::GetDataSource()

{
  return FDataLink->DataSource;
}
//---------------------------------------------------------------------------
void __fastcall TCustomDBFilter::SetDataField(UnicodeString Value)

{
  FDataLink->FieldName = Value;
}
//---------------------------------------------------------------------------
void __fastcall TCustomDBFilter::SetDataSource(TDataSource *Value)

{
  if(Value != NULL)
    Value->FreeNotification(this);
  FDataLink->DataSource = Value;
}
//---------------------------------------------------------------------------
namespace Csdbfilt
{
/*        void __fastcall PACKAGE Register()
        {
                 TComponentClass classes[1] = {__classid(TCustomDBFilter)};
                 RegisterComponents("Data Controls", classes, 0);

        }*/
}
//---------------------------------------------------------------------------
