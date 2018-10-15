//---------------------------------------------------------------------------

#ifndef DBEqualFilterH
#define DBEqualFilterH
//---------------------------------------------------------------------------
#include <SysUtils.hpp>
#include <Controls.hpp>
#include <Classes.hpp>
#include <Forms.hpp>
#include "dbfil.h"
#include <DBCtrls.hpp>
//---------------------------------------------------------------------------
class PACKAGE TDBEqualFilter : public TDBFilter
{
protected :
     //rodzaje porownania tkEqual - = tkLike - Like tkIs - Is
     enum TEqualKind {ekEqual,ekLike,ekIs, ekGreater, ekLess};
private:
      TEqualKind FEqualKind;
protected:
  TWinControl  * FEdit;
// rozciaga edita
  virtual void __fastcall OnResizeFilter(TObject * Sender);
// Nadpisanie obslugi wlasnisci BorderStyle
    virtual void __fastcall SetBorderStyle(Forms::TFormBorderStyle Value);
//Nadpisanie obslugi enabled
    virtual void __fastcall SetEnabled(bool aEnabled);
//Nadpisanie GetList - zwraca niepusta wartosc z edita
    virtual UnicodeString __fastcall GetList(void);
//Obsluga zdarzen
               //OnEnter
               DYNAMIC void __fastcall DoEnter(void);
//Nadpisanie GetStringList __fastcall
        virtual UnicodeString __fastcall GetStringList(void);
        //Obsluga wlasnosci EqualKind
        virtual void __fastcall SetEqualKind(TEqualKind aEqualKind);
        virtual UnicodeString __fastcall GetEqualKind(void);
        // funkcja wirtualna w klasach pochodnych tworzy Edita
        virtual void __fastcall CreateEdit(void){};
        //obsluga wlasnosci Text
        virtual void __fastcall SetText(UnicodeString aText);
        virtual UnicodeString __fastcall GetText(void);
public:
        __fastcall TDBEqualFilter(TComponent* Owner);
        __fastcall ~TDBEqualFilter(void);
__published:
    __property TEqualKind EqualKind= {read= FEqualKind, write=SetEqualKind, default=ekEqual};
    __property Text ={ read=GetText, write=SetText};
};
//---------------------------------------------------------------------------
#endif
