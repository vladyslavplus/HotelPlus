//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Data.DB.hpp>
#include <Data.Win.ADODB.hpp>
//---------------------------------------------------------------------------
class TFLogin : public TForm
{
__published:	// IDE-managed Components
	TLabel *usernameLabel;
	TLabel *passwordLabel;
	TEdit *editUsername;
	TEdit *editPassword;
	TButton *Button1;
	TADOConnection *Connection;
	TADOTable *ADOUsers;
	void __fastcall Button1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TFLogin(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFLogin *FLogin;
//---------------------------------------------------------------------------
#endif
