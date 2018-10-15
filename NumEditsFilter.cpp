//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "NumEditsFilter.h"

//---------------------------------------------------------------------------

#pragma package(smart_init)
static inline void ValidCtrCheck(TNumEditsFilter *)
{
        new TNumEditsFilter(NULL);
}
//---------------------------------------------------------------------------
__fastcall TNumEditsFilter::TNumEditsFilter(TComponent* Owner)
        : TDBBetweenFilter(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TNumEditsFilter::CreateEdit(void)
{
 TDBBetweenFilter::CreateEdit();
 FEditOd = new TNumEdit(this);
 TNumEdit * Buff =dynamic_cast<TNumEdit*>(FEditOd);
 FEditOd->Name = "FeditOd";
 Buff->AsNumber=0.0;
 Buff->OnChange   =DoChange;
 Buff->OnKeyPress =DoKeyPress;
 Buff->OnKeyDown=DoKeyDown;

 FEditDo = new TNumEdit(this);
 Buff = dynamic_cast<TNumEdit*>(FEditDo);
 FEditDo->Name = "FeditDo";
 Buff->AsNumber=0.0;
 Buff->OnChange  =DoChange;
 Buff->OnKeyPress=DoKeyPress;
 Buff->OnKeyDown=DoKeyDown;
}
//---------------------------------------------------------------------------
UnicodeString __fastcall TNumEditsFilter::GetList(void)
{
 UnicodeString Res("");
 UnicodeString Text1 =  dynamic_cast<TNumEdit*>(FEditOd)->AsString;
 UnicodeString Text2 =  dynamic_cast<TNumEdit*>(FEditDo)->AsString;
 if( !(Text1.IsEmpty() && (Text2.IsEmpty() ) ) )
   {
    Res = KeyField;
    Res += " BETWEEN ";
    Res += Text1;
    Res += " AND ";
    Res += Text2;
   }
 return Res;
}
//---------------------------------------------------------------------------
 namespace Numeditsfilter
{
  /*      void __fastcall PACKAGE Register()
		{
				 TComponentClass classes[1] = {__classid(TNumEditsFilter)};
				 RegisterComponents("Data Controls", classes, 0);
		}   */
}
//---------------------------------------------------------------------------