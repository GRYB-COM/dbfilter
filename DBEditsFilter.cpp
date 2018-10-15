//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "dbeditsfilter.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------
// ValidCtrCheck is used to assure that the components created do not have
// any pure virtual functions.
//

static inline void ValidCtrCheck(TDBEditsFilter *)
{
        new TDBEditsFilter(NULL);
}
//---------------------------------------------------------------------------
__fastcall TDBEditsFilter::TDBEditsFilter(TComponent* Owner)
        : TDBBetweenFilter(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TDBEditsFilter::CreateEdit(void)
{
 TDBBetweenFilter::CreateEdit();
 FEditOd = new TMaskEdit(this);
 TMaskEdit * Buff =dynamic_cast<TMaskEdit*>(FEditOd);
 FEditOd->Name = "FeditOd";
 Buff->Text="";
 Buff->OnChange   =DoChange;
 Buff->OnKeyPress =DoKeyPress;
 Buff->OnKeyDown=DoKeyDown;

 FEditDo = new TMaskEdit(this);
 Buff = dynamic_cast<TMaskEdit*>(FEditDo);
 FEditDo->Name = "FeditDo";
 Buff->Text="";
 Buff->OnChange  =DoChange;
 Buff->OnKeyPress=DoKeyPress;
 Buff->OnKeyDown=DoKeyDown;
}
//---------------------------------------------------------------------------
UnicodeString __fastcall  TDBEditsFilter::GetEditMask(void)
{
 return  dynamic_cast<TMaskEdit*>(FEditOd)->EditMask;
}
//---------------------------------------------------------------------------
void __fastcall  TDBEditsFilter::SetEditMask(UnicodeString Mask)
{
 dynamic_cast<TMaskEdit*>(FEditOd)->EditMask=Mask;
 dynamic_cast<TMaskEdit*>(FEditDo)->EditMask=Mask;
}
//---------------------------------------------------------------------------
void __fastcall  TDBEditsFilter::SetTextOd(UnicodeString aText)
{
 dynamic_cast<TMaskEdit*>(FEditOd)->Text =aText;
}
//---------------------------------------------------------------------------

void __fastcall  TDBEditsFilter::SetTextDo(UnicodeString aText)
{
 dynamic_cast<TMaskEdit*>(FEditDo)->Text =aText;
}
//---------------------------------------------------------------------------
UnicodeString __fastcall TDBEditsFilter :: GetTextOd(void)
{
 return  dynamic_cast<TMaskEdit*>(FEditOd)->Text;
}
//---------------------------------------------------------------------------
UnicodeString __fastcall TDBEditsFilter :: GetTextDo(void)
{
 return  dynamic_cast<TMaskEdit*>(FEditDo)->Text;
}
//---------------------------------------------------------------------------
UnicodeString __fastcall TDBEditsFilter::GetList(void)
{
 UnicodeString Res("");
 UnicodeString Text1 =  dynamic_cast<TMaskEdit*>(FEditOd)->Text;
 UnicodeString Text2 =  dynamic_cast<TMaskEdit*>(FEditDo)->Text;
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
/*namespace Dbeditsfilter
{
		void __fastcall PACKAGE Register()
		{
				 TComponentClass classes[1] = {__classid(TDBEditsFilter)};
				 RegisterComponents("Data Controls", classes, 0);
		}
} */
//---------------------------------------------------------------------------
 