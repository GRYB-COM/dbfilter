//---------------------------------------------------------------------------

#ifndef DBDatesFilterH
#define DBDatesFilterH
//---------------------------------------------------------------------------
#include <SysUtils.hpp>
#include <Controls.hpp>
#include <Classes.hpp>
#include <Forms.hpp>
#include "dbbetweenfilter.h"
#include <DBCtrls.hpp>
//---------------------------------------------------------------------------
class PACKAGE TDBDatesFilter : public TDBBetweenFilter
{
private:
protected:
//Wlasnosci przeniesine z TDateTimePicker
//CellAligment
virtual void __fastcall SetCalAlignment(TDTCalAlignment aCalAlignment);
virtual TDTCalAlignment __fastcall GetCalAlignment(void);
//Date
virtual void __fastcall SetDateOd(TDateTime aDate);
virtual TDateTime __fastcall GetDateOd(void);
virtual void __fastcall SetDateDo(TDateTime aDate);
virtual TDateTime __fastcall GetDateDo(void);
//DateFormat
virtual void __fastcall SetDateFormat(TDTDateFormat aDateFormat);
virtual TDTDateFormat __fastcall GetDateFormat(void);
//DateMode
virtual void __fastcall SetDateMode(TDTDateMode aDateMode);
virtual TDTDateMode  __fastcall GetDateMode(void);
//Kind
virtual void __fastcall SetKind(TDateTimeKind aKind);
virtual TDateTimeKind __fastcall GetKind(void);
//Time
virtual void  __fastcall SetTimeDo(TTime aTime);
virtual TTime __fastcall GetTimeDo(void);
virtual void  __fastcall SetTimeOd(TTime aTime);
virtual TTime __fastcall GetTimeOd(void);
// Lista
//Checkbox
virtual void  __fastcall SetShowCheckbox(const bool _Showcb);
virtual bool  __fastcall GetShowCheckbox(void);
//CHECKED
		bool  __fastcall getCheckedSince(void);
		bool  __fastcall getCheckedTo(void);
		void  __fastcall setCheckedSince(const bool _Checked);
		void  __fastcall setCheckedTo(const bool _Checked);
	//Tworzenie Edita
    virtual void __fastcall CreateEdit(void);
public:
        __fastcall TDBDatesFilter(TComponent* Owner);
__published:
        __property TDTCalAlignment CalAlignment ={read=GetCalAlignment , write=SetCalAlignment};
        __property TDateTime       DateSince    ={read=GetDateOd , write=SetDateOd};
        __property TDateTime       DateTo       ={read=GetDateDo , write=SetDateDo};
        __property TDTDateFormat   DateFormat   ={read=GetDateFormat , write=SetDateFormat};
        __property TDTDateMode     DateMode     ={read=GetDateMode , write=SetDateMode};
        __property TDateTimeKind   Kind         ={read=GetKind , write=SetKind};
        __property TTime           TimeSince    ={read=GetTimeOd , write=SetTimeOd};
        __property TTime           TimeTo       ={read=GetTimeDo , write=SetTimeDo};
		__property bool            ShowCheckbox ={read=GetShowCheckbox, write=SetShowCheckbox};
		__property bool            CheckedSince ={read=getCheckedSince, write=setCheckedSince};
		__property bool            CheckedTo    ={read=getCheckedTo,   write=setCheckedTo};
};
//---------------------------------------------------------------------------
#endif
