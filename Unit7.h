//---------------------------------------------------------------------------

#ifndef Unit7H
#define Unit7H
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
class TFClients : public TForm
{
__published:	// IDE-managed Components
	TButton *Button1;
	TButton *Button2;
	TADOConnection *ADOConnection1;
	TADOTable *ADOTable1;
	TDataSource *DataSource1;
	TDBGrid *DBGrid1;
	TButton *Button3;
	TComboBox *ComboBox1;
	TComboBox *ComboBox2;
	TADOQuery *ADOQuerySort;
	TButton *RemoveButton;
	TButton *Button4;
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Button3Click(TObject *Sender);
	void __fastcall RemoveButtonClick(TObject *Sender);
	void __fastcall Button4Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TFClients(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFClients *FClients;
//---------------------------------------------------------------------------
#endif
