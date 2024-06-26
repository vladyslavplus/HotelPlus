//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Project1.cpp"
#include "Unit1.h"
#include "Unit2.h"
#include "Unit3.h"
#include "Unit4.h"
#include "Unit5.h"
#include "Unit7.h"
#include "Unit8.h"
#include "Unit9.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

TFMain *FMain;
//---------------------------------------------------------------------------
__fastcall TFMain::TFMain(TComponent* Owner)
	: TForm(Owner)
{
	if(username != "admin")
	{
		Button4->Enabled = false;
    }

}
//---------------------------------------------------------------------------

void __fastcall TFMain::ButtonInfoClick(TObject *Sender)
{
	FInformation->Show();
	FMain->Hide();
	FInformation->ADOTableInformation->Close();
    FInformation->ADOTableInformation->Open();
}
//---------------------------------------------------------------------------

void __fastcall TFMain::ButtonRegisterClick(TObject *Sender)
{
    FRegister->Show();
	FMain->Hide();
}
//---------------------------------------------------------------------------


void __fastcall TFMain::Button1Click(TObject *Sender)
{
	FServices->Show();
	FMain->Hide();
}
//---------------------------------------------------------------------------


void __fastcall TFMain::Button2Click(TObject *Sender)
{
	FClients->Show();
	FMain->Hide();
	FClients->ADOTable1->Active = false;
	FClients->ADOTable1->Active = true;
}
//---------------------------------------------------------------------------


void __fastcall TFMain::Button4Click(TObject *Sender)
{
	FRoomTypes->Show();
    FMain->Hide();
}
//---------------------------------------------------------------------------

void __fastcall TFMain::Button5Click(TObject *Sender)
{
	FRooms->Show();
	FMain->Hide();
}
//---------------------------------------------------------------------------

