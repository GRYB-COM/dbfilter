//---------------------------------------------------------------------------

#ifndef DBEditFilterH
#define DBEditFilterH
//---------------------------------------------------------------------------
#include "dbequalfilter.h"
//---------------------------------------------------------------------------
class PACKAGE TDBEditFilter : public TDBEqualFilter
{
private:
protected:
virtual void __fastcall SetBorderStyle(Forms::TFormBorderStyle Value);
//Nadpisanie obslugi enabled
    virtual UnicodeString __fastcall GetEditMask(void){return  dynamic_cast<TMaskEdit*>(FEdit)->EditMask;}
    virtual void       __fastcall SetEditMask(UnicodeString Mask){dynamic_cast<TMaskEdit*>(FEdit)->EditMask=Mask;}
    //Tworzenie Edita
    virtual void __fastcall CreateEdit(void);
public:
        __fastcall TDBEditFilter(TComponent* Owner);
__published:
  __property UnicodeString   EditMask={read=GetEditMask, write=SetEditMask};
};
//---------------------------------------------------------------------------
#endif
