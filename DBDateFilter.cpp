//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "dbdatefilter.h"

#pragma link "DBEqualFilter"
#pragma link "DBFil"
#pragma package(smart_init)

//---------------------------------------------------------------------------
// ValidCtrCheck is used to assure that the components created do not have
// any pure virtual functions.
//

static inline void ValidCtrCheck(TDBDateFilter *)
{
        new TDBDateFilter(NULL);
}
//---------------------------------------------------------------------------
__fastcall TDBDateFilter::TDBDateFilter(TComponent* Owner)
        : TDBEqualFilter(Owner)
{

}
//---------------------------------------------------------------------------
void __fastcall TDBDateFilter::CreateEdit(void)
{
 FEdit = new TDateTimePicker(this);
 Width=160;
 TDateTimePicker *Buff = dynamic_cast<TDateTimePicker*>(FEdit) ;
 Buff->OnKeyPress=DoKeyPress;
 Buff->OnKeyDown=DoKeyDown;
}
//---------------------------------------------------------------------------
//CellAlignment
void __fastcall TDBDateFilter::SetCalAlignment(TDTCalAlignment aCalAlignment)
{
  dynamic_cast<TDateTimePicker *>(FEdit)->CalAlignment =aCalAlignment;
}
//---------------------------------------------------------------------------
TDTCalAlignment __fastcall TDBDateFilter::GetCalAlignment(void)
{
 return   dynamic_cast<TDateTimePicker *>(FEdit)->CalAlignment;
}
//---------------------------------------------------------------------------
//Date
void __fastcall TDBDateFilter::SetDate(TDateTime aDate)
{
  dynamic_cast<TDateTimePicker *>(FEdit)->Date=aDate;
}
//---------------------------------------------------------------------------
TDateTime __fastcall TDBDateFilter::GetDate(void)
{
 return   dynamic_cast<TDateTimePicker *>(FEdit)->Date;
}
//---------------------------------------------------------------------------
//DateFormat
void __fastcall TDBDateFilter::SetDateFormat(TDTDateFormat aDateFormat)
{
  dynamic_cast<TDateTimePicker *>(FEdit)->DateFormat =aDateFormat;
}
//---------------------------------------------------------------------------
TDTDateFormat __fastcall TDBDateFilter::GetDateFormat(void)
{
 return   dynamic_cast<TDateTimePicker *>(FEdit)->DateFormat;
}
//---------------------------------------------------------------------------
//DateMode
void __fastcall TDBDateFilter::SetDateMode(TDTDateMode aDateMode)
{
  dynamic_cast<TDateTimePicker *>(FEdit)->DateMode=aDateMode;
}
//---------------------------------------------------------------------------
TDTDateMode  __fastcall TDBDateFilter::GetDateMode(void)
{
 return   dynamic_cast<TDateTimePicker *>(FEdit)->DateMode;
}
//---------------------------------------------------------------------------
//Kind
void __fastcall TDBDateFilter::SetKind(TDateTimeKind aKind)
{
  dynamic_cast<TDateTimePicker *>(FEdit)->Kind=aKind;
}
//---------------------------------------------------------------------------
TDateTimeKind __fastcall TDBDateFilter::GetKind(void)
{
 return   dynamic_cast<TDateTimePicker *>(FEdit)->Kind;
}
//---------------------------------------------------------------------------
//Time
void __fastcall TDBDateFilter::SetTime(TTime aTime)
{
  dynamic_cast<TDateTimePicker *>(FEdit)->Time =aTime;
}
//---------------------------------------------------------------------------
TTime __fastcall TDBDateFilter::GetTime(void)
{
 return   dynamic_cast<TDateTimePicker *>(FEdit)->Time;
}
//---------------------------------------------------------------------------
/*namespace Dbdatefilter
{
		void __fastcall PACKAGE Register()
		{
				 TComponentClass classes[1] = {__classid(TDBDateFilter)};
				 RegisterComponents("Data Controls", classes, 0);
		}
} */
//---------------------------------------------------------------------------
