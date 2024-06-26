//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit2.h"
#include "Unit9.h"
#include "Unit10.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFRoomsEdit *FRoomsEdit;
//---------------------------------------------------------------------------
__fastcall TFRoomsEdit::TFRoomsEdit(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFRoomsEdit::Button1Click(TObject *Sender)
{
	FRoomsEdit->Close();
    FRooms->Show();
}
//---------------------------------------------------------------------------
void __fastcall TFRoomsEdit::Button2Click(TObject *Sender)
{
	FRoomsEdit->Close();
	FRooms->Close();
	FMain->Close();
}
//---------------------------------------------------------------------------
