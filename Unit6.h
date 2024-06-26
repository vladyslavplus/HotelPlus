//---------------------------------------------------------------------------

#ifndef Unit6H
#define Unit6H
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
class TFEditInfo : public TForm
{
__published:	// IDE-managed Components
	TButton *BackButton;
	TButton *CloseButton;
	TADOConnection *ADOConnectionEdit;
	TDataSource *DataSource1;
	TDBGrid *DBGrid1;
	TADOTable *ADOTable1;
	TButton *RemoveEditButton;
	void __fastcall BackButtonClick(TObject *Sender);
	void __fastcall CloseButtonClick(TObject *Sender);
	void __fastcall RemoveEditButtonClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TFEditInfo(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFEditInfo *FEditInfo;
//---------------------------------------------------------------------------
#endif
