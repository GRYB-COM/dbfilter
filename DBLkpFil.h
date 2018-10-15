//---------------------------------------------------------------------------

#ifndef DBLkpFilH
#define DBLkpFilH
//---------------------------------------------------------------------------

#include "dbfil.h"
//---------------------------------------------------------------------------
class PACKAGE TDBLookupFilter : public TDBFilter
{
private:
//kolejne elementy komponentu

  TBitBtn  *    FbtAll;
  TBitBtn  *    FbtNone;
  TBitBtn  *    FbtReverse;
protected:
  TCheckListBox* FCheckListBox;
    virtual void __fastcall SetBorderStyle(Forms::TFormBorderStyle Value);
private:
//Wlasciwosc Single
   bool FSingle;
void __fastcall SetSingle(bool aSingle);

protected:

//wyglad komponentu
// Zmiana koloru po wybraniu Enabled=false
        virtual void __fastcall SetEnabled(bool aEnabled);
//Odznaczanie pozostalych wartosci przy Single=true
        void __fastcall SingleChose(void);
//obsluga zdarzen
//Obsluga zdarzenia OnClick
        virtual void __fastcall DBFilterClick(TObject* Sender);
//Obsluga zdarzenia OnResize
        void __fastcall DBFilterResize(TObject* Sender);
//OnEnter
               DYNAMIC void __fastcall DoEnter(void);
//OnExit
               DYNAMIC void __fastcall DoExit(void);
//OnKeyPress
 virtual void __fastcall ListKeyPress(TObject* Sender, wchar_t& Key);

        TStrings* __fastcall GetItems(void) {return FCheckListBox->Items;};
        virtual void __fastcall SetItems(TStrings* Items) {FCheckListBox->Items=Items;};
// Sprawdzanie czy jest cos wybrane
bool __fastcall GetChecked(void);
//sprawdzanie czy jest wszystko wybrane
bool __fastcall GetAllChecked(void);
//
TNotifyEvent __fastcall GetOnClick(void);
void __fastcall SetOnClick(TNotifyEvent Event);
//Rysowanie buttonow
void __fastcall DrawButtons(void);
//obsluga Count
int __fastcall GetCount(void){return FCheckListBox->Items->Count;}

protected:
virtual UnicodeString __fastcall GetSelectedKey(void);
virtual UnicodeString __fastcall GetKey(const int Indx) {return UnicodeString("Zwraca wartoœæ zaznaczonego wiersza Funkcja TDBLookupFilter::GetKey");}
//Lista wartosci do zaznaczenia

        //metody dostêpu do zdarzen FCheckListBox

        virtual void __fastcall Reverse(void);
        virtual void __fastcall btAllClick(TObject *Sender);
        virtual void __fastcall btNoneClick(TObject *Sender);
        virtual void __fastcall btReverseClick(TObject *Sender);
        virtual int __fastcall GetSelected(void);
        virtual int __fastcall GetItemsCount(void);
        virtual UnicodeString __fastcall GetSelectedValues(void);
        virtual bool  __fastcall GetCheckedItem(int Indx);
        virtual void __fastcall SetCheckedItem(int Indx,bool Chck);

public:
        __fastcall TDBLookupFilter(TComponent* Owner);
        __fastcall ~TDBLookupFilter(void);
		virtual void __fastcall CheckAll(bool Select); //Zaznaczenie lub odznaczenie wszstkich wartsci
//wlasciwosci
		__property TStrings* Items={read=GetItems,write=SetItems};
		__property bool Checked[int Indx] ={ read = GetCheckedItem, write = SetCheckedItem};  //wartosc keya o indeksie  Indx
		__property UnicodeString CheckedValue[int Indx]={read =GetKey};
		__property int        Count={read=GetCount};
__published:
		__property bool IsChecked = {read=GetChecked };
        __property bool IsAllChecked={read=GetAllChecked};
        __property int ItemsCount={read=GetItemsCount};
        __property int ItemsSelected ={read=GetSelected};
        __property UnicodeString SelectedValues={read=GetSelectedValues};
        __property bool Single ={read=FSingle, write=SetSingle, default=false};
        __property UnicodeString SelectedKey={read=GetSelectedKey};
        __property UnicodeString AsList ={read=GetList};
};
//---------------------------------------------------------------------------
#endif
