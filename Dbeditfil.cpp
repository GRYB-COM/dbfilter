//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Dbeditfil.h"
#pragma link "DBFil"
#pragma package(smart_init)
//---------------------------------------------------------------------------
// ValidCtrCheck is used to assure that the components created do not have
// any pure virtual functions.
//

static inline void ValidCtrCheck(TDBEditFilter *)
{
        new TDBEditFilter(NULL);
}
//---------------------------------------------------------------------------
__fastcall TDBEditFilter::TDBEditFilter(TComponent* Owner)
        : TDBFilter(Owner)
{
 FEditOd = new TMaskEdit(this);
 FEditOd->Parent=FpaBottom;
 OnResize=ResizeEdit;
 Height =50;
 Width=121;
 FEditOd->Left=1;
 FEditOd->Top=1;
 FEditOd->Width =Width-5;

}
//---------------------------------------------------------------------------
__fastcall TDBEditFilter::~TDBEditFilter(void)
{
 delete FEditOd;
}
//---------------------------------------------------------------------------
void __fastcall TDBEditFilter::ResizeEdit(TObject * Sender)
{
 FEditOd->Width =Width -5;
}
//---------------------------------------------------------------------------
namespace Dbeditfil
{
        void __fastcall PACKAGE Register()
        {
                 TComponentClass classes[1] = {__classid(TDBEditFilter)};
                 RegisterComponents("Data Controls", classes, 0);
        }
}
//---------------------------------------------------------------------------

