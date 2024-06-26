//---------------------------------------------------------------------------

#ifndef Unit5H
#define Unit5H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Data.DB.hpp>
#include <Data.Win.ADODB.hpp>
#include <Vcl.DBCtrls.hpp>
#include <Vcl.DBGrids.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Grids.hpp>
//---------------------------------------------------------------------------
class TFServices : public TForm
{
__published:	// IDE-managed Components
	TADOConnection *ADOConnection1;
	TADOTable *ADOTable1;
	TDataSource *DataSource1;
	TDBGrid *DBGrid1;
	TButton *BackButton;
	TButton *ExitButton;
	TEdit *ServiceEdit;
	TEdit *CostEdit;
	TButton *Button1;
	TLabel *Label1;
	TLabel *Label2;
	TButton *RemoveButton;
	TButton *RemoveByTitleButton;
	TButton *Button2;
	TComboBox *ComboBox1;
	TComboBox *ComboBox2;
	TADOQuery *ADOQuerySort;
	TButton *RefreshButton;
	void __fastcall BackButtonClick(TObject *Sender);
	void __fastcall ExitButtonClick(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall RemoveButtonClick(TObject *Sender);
	void __fastcall RemoveByTitleButtonClick(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall RefreshButtonClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TFServices(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFServices *FServices;
//---------------------------------------------------------------------------
#endif
