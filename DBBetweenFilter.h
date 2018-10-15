//---------------------------------------------------------------------------

#ifndef DBBetweenFilterH
#define DBBetweenFilterH
#include "dbfil.h"
//---------------------------------------------------------------------------
class PACKAGE TDBBetweenFilter : public TDBFilter
{
private:
  TLabel * FlbOd;
  TLabel * FlbDo;
//przenoszenie Keya do do nastepnego edita
 void __fastcall GotoNextOd(TObject * Sender, wchar_t& Key);
 void __fastcall GotoNextDo(TObject * Sender, wchar_t& Key);
protected:
  TWinControl  * FEditOd;
  TWinControl  * FEditDo;
// rozciaga edity
  virtual void __fastcall OnResizeFilter(TObject * Sender);
// Nadpisanie obslugi wlasnisci BorderStyle
virtual void __fastcall SetBorderStyle(Forms::TFormBorderStyle Value);
//Nadpisanie obslugi enabled
    virtual void __fastcall SetEnabled(bool aEnabled);
//Obsluga zdarzen
               DYNAMIC void __fastcall DoEnter(void);
//Nadpisanie GetList - zwraca niepusta wartosc z edita

    virtual UnicodeString __fastcall GetList(void);
//Nadpisanie GetStringList __fastcall
        virtual UnicodeString __fastcall GetStringList(void);

        virtual void __fastcall CreateEdit(void);
        //obsluga wlasnosci Text
        virtual void __fastcall SetTextOd(UnicodeString aText);
        virtual UnicodeString __fastcall GetTextOd(void);
        virtual void __fastcall SetTextDo(UnicodeString aText);
        virtual UnicodeString __fastcall GetTextDo(void);
public:
        __fastcall TDBBetweenFilter(TComponent* Owner);
        __fastcall ~TDBBetweenFilter(void);
__published:
    __property Text ={ read=GetTextOd, write=SetTextOd};
    __property UnicodeString TextDo={ read=GetTextDo, write=SetTextDo};
};
//---------------------------------------------------------------------------

#endif
 