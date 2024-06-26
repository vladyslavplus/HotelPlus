//---------------------------------------------------------------------------

#ifndef Unit9H
#define Unit9H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Data.DB.hpp>
#include <Data.Win.ADODB.hpp>
#include <Vcl.DBGrids.hpp>
#include <Vcl.Grids.hpp>
#include <Vcl.DBCtrls.hpp>
#include <Vcl.ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TFRooms : public TForm
{
__published:	// IDE-managed Components
	TButton *Button1;
	TButton *Button2;
	TButton *Button3;
	TADOConnection *ADOConnection1;
	TADOTable *ADOTable1;
	TDataSource *DataSource1;
	TADOQuery *ADOQuerySort;
	TDBGrid *DBGrid1;
	TDBNavigator *DBNavigator1;
	TADOTable *ADOTable2;
	TDBGrid *DBGrid2;
	TDataSource *DataSource2;
	TButton *SortButton;
	TComboBox *ComboBox1;
	TComboBox *ComboBox2;
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall EditButtonClick(TObject *Sender);
	void __fastcall Button3Click(TObject *Sender);
	void __fastcall SortButtonClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TFRooms(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFRooms *FRooms;
//---------------------------------------------------------------------------
#endif
