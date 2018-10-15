//---------------------------------------------------------------------------

#ifndef DBDateFilterH
#define DBDateFilterH
//---------------------------------------------------------------------------
#include <SysUtils.hpp>
#include <Controls.hpp>
#include <Classes.hpp>
#include <Forms.hpp>
#include "dbequalfilter.h"
#include <DBCtrls.hpp>
//---------------------------------------------------------------------------
class PACKAGE TDBDateFilter : public TDBEqualFilter
{
private:
protected:
//Wlasnosci przeniesine z TDateTimePicker
//CellAligment
virtual void __fastcall SetCalAlignment(TDTCalAlignment aCalAlignment);
virtual TDTCalAlignment __fastcall GetCalAlignment(void);
//Date
virtual void __fastcall SetDate(TDateTime aDate);
virtual TDateTime __fastcall GetDate(void);
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
virtual void __fastcall SetTime(TTime aTime);
virtual TTime __fastcall GetTime(void);
// Lista
    //Tworzenie Edita
    virtual void __fastcall CreateEdit(void);
public:
        __fastcall TDBDateFilter(TComponent* Owner);
__published:
        __property TDTCalAlignment CalAlignment ={read=GetCalAlignment , write=SetCalAlignment};
        __property TDateTime       Date         ={read=GetDate , write=SetDate};
        __property TDTDateFormat   DateFormat   ={read=GetDateFormat , write=SetDateFormat};
        __property TDTDateMode     DateMode     ={read=GetDateMode , write=SetDateMode};
        __property TDateTimeKind   Kind         ={read=GetKind , write=SetKind};
        __property TTime           Time         ={read=GetTime , write=SetTime};
};
//---------------------------------------------------------------------------
#endif
