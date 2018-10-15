//---------------------------------------------------------------------------

#ifndef NumEditsFilterH
#define NumEditsFilterH
#include <SysUtils.hpp>
#include <Controls.hpp>
#include <Classes.hpp>
#include <Forms.hpp>
#include "dbbetweenfilter.h"
#include "numedit.h"
//---------------------------------------------------------------------------
class PACKAGE TNumEditsFilter : public TDBBetweenFilter
{
 private:
 //-------------------------------------
    class TCustomNumEdit
    {
     private:
          TNumEdit * Edit;
     protected:
    //SETTERY
      void __fastcall SetThousandSep(bool aValue)        {Edit->ThousandSep = aValue;}
      void __fastcall SetIntValue(int aValue)            {Edit->AsInteger   = aValue;}
      void __fastcall SetNumValue(double aValue)         {Edit->AsNumber    = aValue;}
      void __fastcall SetCurrValue(const Currency& aValue){Edit->AsCurrency  = aValue;}
      void __fastcall SetDecLength(int aValue)           {Edit->DecLength   = aValue;}
      void __fastcall SetKind(TNumberKind aValue)        {Edit->Kind        = aValue;}
      void __fastcall SetMaxValue(double aValue)         {Edit->MaxValue    = aValue;}
      void __fastcall SetMinValue(double aValue)         {Edit->MinValue    = aValue;}
      void __fastcall SetMaxDigits(int aValue)           {Edit->MaxDigits   = aValue;}
      void __fastcall SetAsString(const UnicodeString& _Text)     {Edit->AsString    = _Text;}
    //GETTERY
      bool        __fastcall GetThousandSep(void){return Edit->ThousandSep;}
      int         __fastcall GetIntValue(void)   {return Edit->AsInteger;}
      double      __fastcall GetNumValue(void)   {return Edit->AsNumber;}
      Currency    __fastcall GetCurrValue(void)   {return Edit->AsCurrency;}
      int         __fastcall GetDecLength(void)  {return Edit->DecLength;}
      TNumberKind __fastcall GetKind(void)       {return Edit->Kind;}
      double      __fastcall GetMaxValue(void)   {return Edit->MaxValue;}
      double      __fastcall GetMinValue(void)   {return Edit->MinValue;}
      int         __fastcall GetMaxDigits(void)  {return Edit->MaxDigits;}
	  UnicodeString      __fastcall GetAsString(void)   {return Edit->AsString;}
	public:
	//KONSTRUKTORY
	 TCustomNumEdit(TWinControl * _Edit) { Edit = dynamic_cast<TNumEdit*>(_Edit);}
   //W£AŒCIWOŒCI
	 __property bool        ThousandSep = {read = GetThousandSep, write = SetThousandSep};
	 __property int         AsInteger   = {read = GetIntValue,    write = SetIntValue};
	 __property Currency    AsCurrency  = {read = GetCurrValue,   write = SetCurrValue};
	 __property double      AsNumber    = {read = GetNumValue,    write = SetNumValue};
	 __property UnicodeString  AsString    = {read = GetAsString,      write = SetAsString};
	 __property int         DecLength   = {read = GetDecLength,   write = SetDecLength};
     __property TNumberKind Kind        = {read = GetKind,        write = SetKind};
     __property double      MaxValue    = {read = GetMaxValue,    write = SetMaxValue};
     __property double      MinValue    = {read = GetMinValue,    write = SetMinValue};
     __property int         MaxDigits   = {read = GetMaxDigits,   write = SetMaxDigits};
    };
   //-----------------------------------------------
 protected:
  //GETTERY
    TCustomNumEdit  __fastcall GetEditOd(void) { return TCustomNumEdit(FEditOd); }
    TCustomNumEdit  __fastcall GetEditDo(void) { return TCustomNumEdit(FEditDo); }
    virtual UnicodeString __fastcall GetList(void);
  //KONSTRUKTORY
   virtual void __fastcall CreateEdit(void);
 public:
        __fastcall TNumEditsFilter(TComponent* Owner);
 //W£AŒCIWOŒCI
    __property TCustomNumEdit EditOd = {read = GetEditOd};
    __property TCustomNumEdit EditDo = {read = GetEditDo};
};
#endif

