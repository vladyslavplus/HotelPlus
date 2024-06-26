//---------------------------------------------------------------------------

#ifndef Unit3H
#define Unit3H
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
class TFInformation : public TForm
{
__published:	// IDE-managed Components
	TButton *BackButton;
	TButton *CloseButton;
	TADOConnection *ADOConnection;
	TADOTable *ADOTableInformation;
	TDBGrid *DBGrid1;
	TDataSource *DataSource1;
	TButton *Button1;
	TButton *RefreshButton;
	TButton *Button2;
	TComboBox *ComboBox1;
	TADOQuery *ADOQuerySort;
	TComboBox *ComboBox2;
	void __fastcall BackButtonClick(TObject *Sender);
	void __fastcall CloseButtonClick(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall RefreshButtonClick(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TFInformation(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFInformation *FInformation;
//---------------------------------------------------------------------------
#endif
