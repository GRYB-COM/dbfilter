//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "DBMEdN.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------
// ValidCtrCheck is used to assure that the components created do not have
// any pure virtual functions.
//

static inline void ValidCtrCheck(TDBMaskEditN *)
{
        new TDBMaskEditN(NULL);
}
//---------------------------------------------------------------------------
__fastcall TDBMaskEditN::TDBMaskEditN(TComponent* Owner)
        : TCustomMaskEdit(Owner)
{
}
//---------------------------------------------------------------------------
namespace Dbmedn
{
        void __fastcall PACKAGE Register()
        {
                 TComponentClass classes[1] = {__classid(TDBMaskEditN)};
                 RegisterComponents("Data Controls", classes, 0);
        }
}
//---------------------------------------------------------------------------
 