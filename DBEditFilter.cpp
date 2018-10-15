//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "dbeditfilter.h"
//#include <maskprop.hpp>
#include <assert.h>
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
        : TDBEqualFilter(Owner)
{
 Width=130;
}
//---------------------------------------------------------------------------
void __fastcall TDBEditFilter::SetBorderStyle(Forms::TFormBorderStyle _BorderStyle)
{
   TDBEqualFilter::SetBorderStyle(BorderStyle);
   dynamic_cast<TMaskEdit*>(FEdit)->BorderStyle=  _BorderStyle;
}

//---------------------------------------------------------------------------
void __fastcall TDBEditFilter::CreateEdit(void)
{
 FEdit = new TMaskEdit(this);
 FEdit->Name="EditPoj";
 TMaskEdit *Buff = dynamic_cast<TMaskEdit*>(FEdit) ;
 Buff->Text="";
 Buff->OnChange = DoChange;
 Buff->OnKeyPress=DoKeyPress;
 Buff->OnKeyDown=DoKeyDown;
}
//---------------------------------------------------------------------------
/*namespace Dbeditfilter
{


        void __fastcall PACKAGE Register()
        {
                 TComponentClass classes[1] = {__classid(TDBEditFilter)};
                 RegisterComponents("Data Controls", classes, 0);
        }
} */
//---------------------------------------------------------------------------
