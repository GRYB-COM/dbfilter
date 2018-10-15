//---------------------------------------------------------------------------

#ifndef DBEditsFilterH
#define DBEditsFilterH
//---------------------------------------------------------------------------
#include <SysUtils.hpp>
#include <Controls.hpp>
#include <Classes.hpp>
#include <Forms.hpp>
#include "dbbetweenfilter.h"
//---------------------------------------------------------------------------
class PACKAGE TDBEditsFilter : public TDBBetweenFilter
{
private:
protected:
   virtual UnicodeString __fastcall GetEditMask(void);
   virtual void       __fastcall SetEditMask(UnicodeString Mask);
   virtual void       __fastcall SetTextOd(UnicodeString aText);
   virtual UnicodeString __fastcall GetTextOd(void);
   virtual void       __fastcall SetTextDo(UnicodeString aText);
   virtual UnicodeString __fastcall GetTextDo(void);
   virtual UnicodeString __fastcall GetList(void);

virtual void __fastcall CreateEdit(void);
public:
        __fastcall TDBEditsFilter(TComponent* Owner);
__published:
   __property UnicodeString EditMask={read =GetEditMask, write=SetEditMask};
};
//---------------------------------------------------------------------------
#endif
 