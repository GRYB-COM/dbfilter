//---------------------------------------------------------------------------

#include <vcl.h>
#include <assert.h>
#pragma hdrstop

#include "DBMEdit.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------
// ValidCtrCheck is used to assure that the components created do not have
// any pure virtual functions.
//

static inline void ValidCtrCheck(TDBMaskEdit *)
{
        new TDBMaskEdit(NULL);
}
//---------------------------------------------------------------------------
__fastcall TDBMaskEdit::TDBMaskEdit(TComponent* Owner)
        : TDBEdit(Owner)
{
  TFieldDataLink* DataLink =(TFieldDataLink*) Perform(CM_GETDATALINK,0,0);
  OnDataChangeOld=DataLink->OnDataChange;
  DataLink->OnDataChange= DataChange;
}
//---------------------------------------------------------------------------
void __fastcall  TDBMaskEdit::DataChange(TObject* Sender)
{
 UnicodeString Blank="____";
 OnDataChangeOld(Sender);
 SetCurr();
 Blank += FormatField();
 Text=Blank;
}
//---------------------------------------------------------------------------
void __fastcall  TDBMaskEdit::DoEnter(void)
{
 SetSel(0,2);
 TDBEdit::DoEnter();
}
//---------------------------------------------------------------------------
UnicodeString __fastcall  TDBMaskEdit::FormatField(void)
{
 UnicodeString Res;
 UnicodeString EdMask=TDBEdit::EditMask;
 if(Field)
   {
    if(!Field->Value.IsNull())
       {
        switch(Field->DataType)
              {
               case ftFloat:
               case ftBCD:
                EdMask=Reverse(',','.',EdMask);
                Res =FormatFloat(EdMask,Field->AsFloat);
               break;
               case ftCurrency:
                EdMask=Reverse(',','.',EdMask);
                Res=FormatCurr(EdMask,Field->AsCurrency);
               break;
               case ftDateTime:
                Res=FormatDateTime(EdMask,Field->AsDateTime);
               default:
               Res=FormatMaskText(EdMask,Field->AsString);
              }
       }
   }
 return Res;
}
//---------------------------------------------------------------------------
void __fastcall  TDBMaskEdit::KeyPress(wchar_t& Key)
{
 if(Key=='.' | Key==',')
   {
    MoveSep();
    SetSel(EditText.Length()-3,EditText.Length()-3);
   }
 TDBEdit::KeyPress(Key);
}
//---------------------------------------------------------------------------
bool __fastcall  TDBMaskEdit::IsDelimeter(int Len)
{
 bool Res=false;
 int Length =Len<=EditText.Length() ? Len:EditText.Length();
 for(int i=1;i<=Length;i++)
    {
     if(EditText[i]==',' || EditText[i]=='.')
       {
        Res=true;
        break;
       }
    }
  return Res;
}
//---------------------------------------------------------------------------
void __fastcall  TDBMaskEdit::MoveSep(void)
{
 try
    {
     UnicodeString Format(TDBEdit::EditMask);
     int ForLen=Format.Length();
     double Liczba;
     Format[ForLen-3]='0';
     Format[ForLen-2]='.';
     Format[ForLen-1]='0';
     Format[ForLen]='0';
    if( (EditMask[SelStart]=='$') && (!IsDelimeter(SelStart) ) )
      {
       Text=Text.Trim();
       Text=Text.SubString(1,SelStart);
       Liczba=Text.ToDouble();
       Text=FormatFloat(Format,Liczba);
       SetAlignment();
      }
    }
 catch(EConvertError & exc)
    {
 //    SetPos(0);
    }
}
//---------------------------------------------------------------------------
void __fastcall  TDBMaskEdit::RemoveBlanks(void)
{
 int i;
 char aBlank=MaskGetMaskBlank(TDBEdit::EditMask);
 UnicodeString aText=EditText;
 for(int i=1; i<=aText.Length();i++)
    {
     if(aText[i]==aBlank) aText.Delete(i,1);
    }
 Text = aText;
}
//---------------------------------------------------------------------------
UnicodeString __fastcall TDBMaskEdit::Reverse(char Sign,char Char, UnicodeString Source)
{
 UnicodeString EdMask= Source;
 for(int i=1; i<=EdMask.Length();i++)
    {
     if(EdMask[i]==Sign)
        {
         EdMask[i]=Char;
        } 
    }
 return EdMask;
}
//---------------------------------------------------------------------------
void __fastcall TDBMaskEdit::SetCurr(void)
{
 UnicodeString EdMask=Reverse('$','#',FEditMask);
 TDBEdit::EditMask = EdMask;
}
//---------------------------------------------------------------------------
void __fastcall TDBMaskEdit::SetEditMask(UnicodeString aEditMask)
{
 FEditMask=aEditMask;
 SetCurr();

}
//---------------------------------------------------------------------------
void __fastcall  TDBMaskEdit::SetAlignment(void)
{
 char aBlank=MaskGetMaskBlank(TDBEdit::EditMask);
 UnicodeString aBlanks;
 UnicodeString aHalfBlanks;
 UnicodeString aText = Text;
 UnicodeString eText = EditText;
 aText=aText.Trim();
 int aLen =aText.Length();
 int eLen =eText.Length();
 int Diff = eLen - aLen;
 aBlanks=aBlanks.StringOfChar(aBlank,Diff);
 aHalfBlanks=aHalfBlanks.StringOfChar(aBlank,Diff/2);
 if(Field)
   {
    switch(Field->Alignment)
           {
            case taRightJustify:
            eText = aBlanks;
            eText +=aText;
            break;
            case taLeftJustify:
            eText = aText;
            eText +=aBlanks;
            break;
            case taCenter:
            eText=aHalfBlanks;
            eText+=aText;
            eText+=aHalfBlanks;
            break;
           }
    EditText=eText;
    SetSel(0,5);
   }
}
//---------------------------------------------------------------------------
bool __fastcall  TDBMaskEdit::Validate(const UnicodeString Value, int &Pos)
{
//  RemoveBlanks();
 return TDBEdit::Validate(Value,Pos);
}
//---------------------------------------------------------------------------
void __fastcall  TDBMaskEdit::ValidateEdit(void)
{
// RemoveBlanks();
 TDBEdit::ValidateEdit();
}

