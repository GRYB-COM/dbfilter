//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Reg.h"
#include <dbfilter.h>
//---------------------------------------------------------------------------

#pragma package(smart_init)
namespace Lstfilt
{
        void __fastcall PACKAGE Register()
        {
                 TComponentClass classes[1] = {__classid(TDBListFilter)};
                 RegisterComponents("Data Controls", classes, 0);
                 RegisterPropertyEditor(ListFieldTypeInfo("ListField"),
                                   __classid(TDBListFilter),
                                  "ListField",
                                   __classid(TListFieldEditor)
                                      );


        }
}
//---------------------------------------------------------------------------
 