//---------------------------------------------------------------------------

#ifndef CsDBFiltH
#define CsDBFiltH
//---------------------------------------------------------------------------
#include <SysUtils.hpp>
#include <Controls.hpp>
#include <Classes.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <DB.hpp>
#include <DBTables.hpp>
#include <dbctrls.hpp>
#include <dsgnintf.hpp>
#include <Checklst.hpp>
//---------------------------------------------------------------------------
class PACKAGE TCustomDBFilter : public TPanel
{
private:
    TFieldDataLink * FDataLink;
    UnicodeString __fastcall GetDataField();             // methods are private
    TDataSource *__fastcall GetDataSource();          // returns name of data field
    void __fastcall SetDataField(UnicodeString Value); // returns reference to data                                                           // source
    void __fastcall SetDataSource(TDataSource *Value);    // assigns name of data field
protected:
public:
        __fastcall TCustomDBFilter(TComponent* Owner);
        __fastcall ~TCustomDBFilter();
__published:
    __property UnicodeString DataField = {read=GetDataField, write=SetDataField, nodefault};
    __property TDataSource * DataSource = {read=GetDataSource, write=SetDataSource,       nodefault};

};
//---------------------------------------------------------------------------
#endif

