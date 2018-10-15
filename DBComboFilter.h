//---------------------------------------------------------------------------

#ifndef DBComboFilterH
#define DBComboFilterH
//---------------------------------------------------------------------------
#include <SysUtils.hpp>
#include <Controls.hpp>
#include <Classes.hpp>
#include <Forms.hpp>
#include <DBCtrls.hpp>
//---------------------------------------------------------------------------
class PACKAGE TDBComboFilter : public TPanel
{
private:
//panele
       protected:
       TPanel * FpaTop;       
       TPanel * FpaBottom;
       virtual void __fastcall ShowPanels(void);

private:
//Caption
           TLabel* FlbCaption;
           protected:
           virtual void __fastcall ShowCaption(void);
           private:
           void __fastcall SetCaption(UnicodeString aCaption){FlbCaption->Caption=aCaption;};
           UnicodeString __fastcall GetCaption(void){return FlbCaption->Caption;};
//Labele Od do
 TLabel *FlbOd;
 TLabel *FlbDo;

// LookupCombo
private:
	TDBLookupComboBox * FEditOd;
        TDBLookupComboBox * FEditDo;
//obsluga zdarzen
               //OnClick
               //virtual void __fastcall DBFilterClick(TObject* Sender);
               //OnResize
               virtual void __fastcall OnResizeFilter(TObject* Sender);
               //OnEnter
               DYNAMIC void __fastcall DoEnter(void);
//obsluga wlasnosci
protected:
        //Zwraca jako ciag znakow oddzielony przecinkami
        virtual UnicodeString __fastcall GetList(void);
        virtual UnicodeString __fastcall GetStringList(void);
        virtual UnicodeString __fastcall GetCondition(void);
       //przy pobieraniu ze strumienia rozciaga edita
       virtual void __fastcall Loaded(void);
//przenoszenie Keya do do nastepnego edita
 void __fastcall GotoNextOd(TObject * Sender, wchar_t& Key);
 void __fastcall GotoNextDo(TObject * Sender, wchar_t& Key);

//wlasciwosci
public:
__published:
        __property UnicodeString AsStringList={read=GetStringList};
        __property UnicodeString AsCondition={read=GetCondition};

protected:
public:
	__fastcall TDBComboFilter(TComponent* Owner);
        __fastcall ~TDBComboFilter(void);
__published:
};
//---------------------------------------------------------------------------
#endif
