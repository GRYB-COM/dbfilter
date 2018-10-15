//---------------------------------------------------------------------------

#ifndef DBMEditH
#define DBMEditH
//---------------------------------------------------------------------------
#include <SysUtils.hpp>
#include <Controls.hpp>
#include <Classes.hpp>
#include <Forms.hpp>
#include <DBCtrls.hpp>
#include <Mask.hpp>
#include <StdCtrls.hpp>
//---------------------------------------------------------------------------
class PACKAGE TDBMaskEdit : public TDBEdit
{
private:
 UnicodeString FEditMask;
 TNotifyEvent OnDataChangeOld;
 void __fastcall SetCurr(void);
 void __fastcall MoveSep(void);
 void __fastcall SetEditMask(UnicodeString aEditMask);
 void __fastcall SetAlignment(void);
 void __fastcall DataChange(TObject * Sender);
 void __fastcall RemoveBlanks(void);
 bool __fastcall IsDelimeter(int Len);

protected:
virtual  UnicodeString __fastcall Reverse(char Sign,char Char, UnicodeString);
virtual bool __fastcall Validate(const UnicodeString Value, int &Pos);
DYNAMIC void __fastcall KeyPress(wchar_t &Key);
DYNAMIC void __fastcall DoEnter(void);
virtual UnicodeString __fastcall FormatField(void);
public:

        __fastcall TDBMaskEdit(TComponent* Owner);
	virtual void __fastcall ValidateEdit(void);
__published:
  __property UnicodeString EditMask={read=FEditMask,write=SetEditMask};
};
//---------------------------------------------------------------------------
#endif
