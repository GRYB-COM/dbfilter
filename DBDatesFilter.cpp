//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "dbdatesfilter.h"
#pragma link "DBBetweenFilter"
#pragma link "DBFil"
#pragma package(smart_init)
//---------------------------------------------------------------------------
// ValidCtrCheck is used to assure that the components created do not have
// any pure virtual functions.
//

static inline void ValidCtrCheck(TDBDatesFilter *)
{
        new TDBDatesFilter(NULL);
}
//---------------------------------------------------------------------------
void __fastcall TDBDatesFilter::CreateEdit(void)
{
 TDBBetweenFilter::CreateEdit();
 FEditOd = new TDateTimePicker(this);
 FEditDo = new TDateTimePicker(this);
 ( (TEdit*) FEditOd)->Text ="";
 ( (TEdit*) FEditDo)->Text ="";
 ( (TDateTimePicker*) FEditOd)->ShowCheckbox = true;
 ( (TDateTimePicker*) FEditDo)->ShowCheckbox = true;
}
//---------------------------------------------------------------------------
__fastcall TDBDatesFilter::TDBDatesFilter(TComponent* Owner)
        : TDBBetweenFilter(Owner)
{
}
//---------------------------------------------------------------------------
//CellAlignment
void __fastcall TDBDatesFilter::SetCalAlignment(TDTCalAlignment aCalAlignment)
{
  dynamic_cast<TDateTimePicker *>(FEditOd)->CalAlignment =aCalAlignment;
  dynamic_cast<TDateTimePicker *>(FEditDo)->CalAlignment =aCalAlignment;
}
//---------------------------------------------------------------------------
TDTCalAlignment __fastcall TDBDatesFilter::GetCalAlignment(void)
{
 return   dynamic_cast<TDateTimePicker *>(FEditOd)->CalAlignment;
}
//---------------------------------------------------------------------------
//Date
void __fastcall TDBDatesFilter::SetDateOd(TDateTime aDate)
{
  dynamic_cast<TDateTimePicker *>(FEditOd)->Date=aDate;

}
//---------------------------------------------------------------------------
void __fastcall TDBDatesFilter::SetDateDo(TDateTime aDate)
{
  dynamic_cast<TDateTimePicker *>(FEditDo)->Date=aDate;

}
//---------------------------------------------------------------------------
TDateTime __fastcall TDBDatesFilter::GetDateOd(void)
{
 TDateTimePicker * _DOd =  dynamic_cast<TDateTimePicker *>(FEditOd);
 bool _Signed = !_DOd->ShowCheckbox ||  (_DOd->ShowCheckbox && _DOd->Checked);
 TDateTime _Res  = _Signed ?  _DOd->Date : TDateTime(0.00);
 return   _Res;
}
//---------------------------------------------------------------------------
TDateTime __fastcall TDBDatesFilter::GetDateDo(void)
{
 TDateTimePicker * _DDo =  dynamic_cast<TDateTimePicker *>(FEditDo);
 bool _Signed = !_DDo->ShowCheckbox ||  (_DDo->ShowCheckbox && _DDo->Checked);
 TDateTime _Res  = _Signed ?  _DDo->Date :TDateTime(9999,12,31);
 return   _Res;
}
//---------------------------------------------------------------------------
//DateFormat
void __fastcall TDBDatesFilter::SetDateFormat(TDTDateFormat aDateFormat)
{
  dynamic_cast<TDateTimePicker *>(FEditOd)->DateFormat =aDateFormat;
  dynamic_cast<TDateTimePicker *>(FEditDo)->DateFormat =aDateFormat;
}
//---------------------------------------------------------------------------
TDTDateFormat __fastcall TDBDatesFilter::GetDateFormat(void)
{
 return   dynamic_cast<TDateTimePicker *>(FEditOd)->DateFormat;
}
//---------------------------------------------------------------------------
//DateMode
void __fastcall TDBDatesFilter::SetDateMode(TDTDateMode aDateMode)
{
  dynamic_cast<TDateTimePicker *>(FEditOd)->DateMode=aDateMode;
  dynamic_cast<TDateTimePicker *>(FEditDo)->DateMode=aDateMode;
}
//---------------------------------------------------------------------------
TDTDateMode  __fastcall TDBDatesFilter::GetDateMode(void)
{
 return   dynamic_cast<TDateTimePicker *>(FEditOd)->DateMode;
}
//---------------------------------------------------------------------------
//Kind
void __fastcall TDBDatesFilter::SetKind(TDateTimeKind aKind)
{
  dynamic_cast<TDateTimePicker *>(FEditOd)->Kind=aKind;
  dynamic_cast<TDateTimePicker *>(FEditDo)->Kind=aKind;
}
//---------------------------------------------------------------------------
TDateTimeKind __fastcall TDBDatesFilter::GetKind(void)
{
 return   dynamic_cast<TDateTimePicker *>(FEditOd)->Kind;
}
//---------------------------------------------------------------------------
//Time
void __fastcall TDBDatesFilter::SetTimeOd(TTime aTime)
{
  dynamic_cast<TDateTimePicker *>(FEditOd)->Time =aTime;
}
//---------------------------------------------------------------------------
void __fastcall TDBDatesFilter::SetTimeDo(TTime aTime)
{
  dynamic_cast<TDateTimePicker *>(FEditDo)->Time =aTime;
}
//---------------------------------------------------------------------------
TTime __fastcall TDBDatesFilter::GetTimeOd(void)
{
 return   dynamic_cast<TDateTimePicker *>(FEditOd)->Time;
}
//---------------------------------------------------------------------------
TTime __fastcall TDBDatesFilter::GetTimeDo(void)
{
 return   dynamic_cast<TDateTimePicker *>(FEditDo)->Time;
}
//---------------------------------------------------------------------------
void __fastcall TDBDatesFilter::SetShowCheckbox(const bool _Showcb)
{
 dynamic_cast<TDateTimePicker *>(FEditOd)->ShowCheckbox = _Showcb;
 dynamic_cast<TDateTimePicker *>(FEditDo)->ShowCheckbox = _Showcb;
}
//---------------------------------------------------------------------------
bool __fastcall TDBDatesFilter::GetShowCheckbox(void)
{
 return dynamic_cast<TDateTimePicker *>(FEditOd)->ShowCheckbox;
}
//---------------------------------------------------------------------------
bool __fastcall TDBDatesFilter::getCheckedSince(void)
{
 return dynamic_cast<TDateTimePicker *>(FEditOd)->Checked;
}

//---------------------------------------------------------------------------
bool __fastcall TDBDatesFilter::getCheckedTo(void)
{
 return dynamic_cast<TDateTimePicker *>(FEditDo)->Checked;
}

//---------------------------------------------------------------------------
void __fastcall TDBDatesFilter::setCheckedSince(const bool _Checked)
{
 dynamic_cast<TDateTimePicker *>(FEditOd)->Checked = _Checked;
}

//---------------------------------------------------------------------------
void __fastcall TDBDatesFilter::setCheckedTo(const bool _Checked)
{
 dynamic_cast<TDateTimePicker *>(FEditDo)->Checked = _Checked;
}

//---------------------------------------------------------------------------
/*namespace Dbdatesfilter
{
		void __fastcall PACKAGE Register()
		{
				 TComponentClass classes[1] = {__classid(TDBDatesFilter)};
				 RegisterComponents("Data Controls", classes, 0);
		}
} */
//---------------------------------------------------------------------------
