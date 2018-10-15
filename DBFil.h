//---------------------------------------------------------------------------

#ifndef DBFilH
#define DBFilH
//---------------------------------------------------------------------------

#include <SysUtils.hpp>
#include <Controls.hpp>
#include <Classes.hpp>
#include <Forms.hpp>
#include <DBCtrls.hpp>
#include <checklst.hpp>

//---------------------------------------------------------------------------
class EFilterExc:public Exception
{
 public:
 __fastcall EFilterExc(UnicodeString Msg);
};
//---------------------------------------------------------------------------
//oszukanie nieupublicznionych wlasnosci
class PACKAGE TMainWinControl :public TWinControl{
public:
void __fastcall SelectNext(TWinControl* CurControl, bool GoForward, bool CheckTabStop)
{ TWinControl::SelectNext(CurControl,GoForward,CheckTabStop);}
void __fastcall SelectFirst(void){ TWinControl::SelectFirst();}
protected:

 __published:
  __property Ctl3D;
  __property Text;
  __property Color;
  __property OnKeyPress;

};

//---------------------------------------------------------------------------
class PACKAGE TDBFilter : public TDBLookupControl
{
public:
// konstruktor destruktor
        __fastcall TDBFilter(TComponent* Owner);
        __fastcall ~TDBFilter(void);
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

protected:
//OnChange
 TNotifyEvent FOnChange;
private:
//Wlasciwosc BorderStyle
	Forms::TFormBorderStyle __fastcall GetBorderStyle(void){return  FpaTop->BorderStyle;};
//
protected:
	virtual void __fastcall SetBorderStyle(Forms::TFormBorderStyle Value);


protected:
// Zmiana koloru po wybraniu Enabled=false
        virtual void __fastcall SetEnabled(bool aEnabled);
        virtual bool __fastcall GetEnabled(void);


//obsluga zdarzen
               //OnClick
               virtual void __fastcall DBFilterClick(TObject* Sender);
               //OnResize
               virtual void __fastcall OnResizeFilter(TObject* Sender){};
               //OnEnter
               DYNAMIC void __fastcall DoEnter(void);
               //OnChange
               virtual void __fastcall DoChange(TObject * Sender);
               //OnKeyPress
               virtual void __fastcall DoKeyPress(TObject * Sender,wchar_t& Key);
               //OnKeyPress
               virtual void __fastcall DoKeyDown(TObject * Sender,Word& Key, TShiftState State);
//obsluga wlasnosci
protected:
        //Zwraca jako ciag znakow oddzielony przecinkami
        virtual UnicodeString __fastcall GetList(void){return NULL;};
        virtual UnicodeString __fastcall GetStringList(void);
        virtual UnicodeString __fastcall GetCondition(void);
       //przy pobieraniu ze strumienia rozciaga edita
       virtual void __fastcall Loaded(void);
       //lista zaznaczonych kluczy do wyœwietlania w nag³ówkach itp
       virtual UnicodeString __fastcall GetSelectedKeys(void){return "";}
//wlasciwosci
public:
__published:
        __property UnicodeString AsStringList={read=GetStringList};
        __property UnicodeString AsCondition={read=GetCondition};
       //lista zaznaczonych kluczy do wyœwietlania w nag³ówkach itp
        __property UnicodeString AsSelectedKeys={read=GetSelectedKeys};
	__property Align ;
	__property Anchors;
	__property BiDiMode ;
	__property Forms::TFormBorderStyle BorderStyle = {read=GetBorderStyle,  write=SetBorderStyle};
        __property UnicodeString Caption ={read=GetCaption,write=SetCaption};
	__property Color ;
	__property Constraints ;
	__property Ctl3D ;
	__property DragCursor ;
	__property DragKind ;
	__property DragMode ;
	__property Enabled ={read =GetEnabled, write= SetEnabled};
	__property Font ;
	__property ImeMode ;
	__property ImeName ;

	 __property KeyField;
	 __property ListSource;
	__property ParentBiDiMode ;
	__property ParentColor ;
	__property ParentCtl3D ;
	__property ParentFont ;
	__property ParentShowHint ;
	__property PopupMenu ;
	__property ReadOnly ;
	__property ShowHint ;
	__property TabOrder ;
	__property TabStop ;
	__property Visible ;
	__property OnClick;
		// ={read =GetOnClick,write=SetOnClick};
	__property OnContextPopup ;
	__property OnDblClick ;
	__property OnDragDrop ;
	__property OnDragOver ;
	__property OnEndDock ;
	__property OnEndDrag ;
	__property OnEnter ;
	__property OnExit ;
	__property OnKeyDown ;
	__property OnKeyPress ;
	__property OnKeyUp ;
	__property OnMouseDown ;
	__property OnMouseMove ;
	__property OnMouseUp ;
	__property OnStartDock ;
	__property OnStartDrag ;
        __property TNotifyEvent OnChange = {read=FOnChange, write=FOnChange};
        __property Text;

};
//---------------------------------------------------------------------------
#endif
extern UnicodeString KeyFieldErr;
