//---------------------------------------------------------------------------

#ifndef Unit8H
#define Unit8H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Data.DB.hpp>
#include <Data.Win.ADODB.hpp>
#include <Vcl.DBGrids.hpp>
#include <Vcl.Grids.hpp>
//---------------------------------------------------------------------------
class TFRoomTypes : public TForm
{
__published:	// IDE-managed Components
	TButton *Button1;
	TButton *Button2;
	TButton *Button3;
	TADOConnection *ADOConnection1;
	TADOTable *ADOTable1;
	TDataSource *DataSource1;
	TDBGrid *DBGrid1;
	TADOQuery *ADOQuerySort;
	TButton *RemoveButton;
	TComboBox *ComboBox1;
	TButton *SortButton;
	TButton *AddButton;
	TEdit *Edit1;
	TEdit *Edit2;
	TLabel *Label1;
	TLabel *Label2;
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall Button3Click(TObject *Sender);
	void __fastcall RemoveButtonClick(TObject *Sender);
	void __fastcall AddButtonClick(TObject *Sender);
	void __fastcall SortButtonClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TFRoomTypes(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFRoomTypes *FRoomTypes;
//---------------------------------------------------------------------------
#endif
