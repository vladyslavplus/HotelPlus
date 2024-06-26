//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "Unit2.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFLogin *FLogin;
String username, password;
//---------------------------------------------------------------------------
__fastcall TFLogin::TFLogin(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFLogin::Button1Click(TObject *Sender)
{
	username = editUsername->Text;
	password = editPassword->Text;

	bool foundUsername = false, foundPassword = false;

	int rcount = ADOUsers->RecordCount;
	ADOUsers->First();
	for(int i = 0; i < rcount; i++)
	{
		if(username.LowerCase() == ADOUsers->FieldByName("username")->AsString.LowerCase())
		{
			foundUsername = true;
			if(password == ADOUsers->FieldByName("password")->AsString)
			{
				foundPassword = true;
				ShowMessage("Welcome " + ADOUsers->FieldByName("username")->AsString);
			}
		}

		ADOUsers->Next();
	}

	if(foundUsername==false)
	{
		ShowMessage("Wrong Username");
		return;
	}
	if(foundPassword == false)
	{
		ShowMessage("Wrong Password");
		return;
	}

	ModalResult = mrOk;
}
//---------------------------------------------------------------------------



