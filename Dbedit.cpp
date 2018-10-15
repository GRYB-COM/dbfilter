//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Dbedit.h"

//---------------------------------------------------------------------------

#pragma package(smart_init)
//---------------------------------------------------------------------------
__fastcall TDBEditFilter::TDBEditFilter(TComponent * Owner)
  :TDBFilter(Owner)
{
 FEditOd = new TMaskEdit(this);
 FEditOd->Parent=FpaBottom;
 FEditOd->Left=5;
 FEditOd->Top=5;
}
//---------------------------------------------------------------------------
__fastcall TDBEditFilter::~TDBEditFilter(void)
{
 delete FEditOd;
}
//---------------------------------------------------------------------------
namespace dbedfil
{
        void __fastcall PACKAGE Register()
        {
                 TComponentClass classes[1] = {__classid(TDBEditFilter)};
                 RegisterComponents("Data Controls", classes, 0);

        }
}
//---------------------------------------------------------------------------
