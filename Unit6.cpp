//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit2.h"
#include "Unit3.h"
#include "Unit6.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFEditInfo *FEditInfo;
//---------------------------------------------------------------------------
__fastcall TFEditInfo::TFEditInfo(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFEditInfo::BackButtonClick(TObject *Sender)
{
	FEditInfo->Close();
	FInformation->Show();
	FInformation->ADOTableInformation->Active = false;
    FInformation->ADOTableInformation->Active = true;
}
//---------------------------------------------------------------------------
void __fastcall TFEditInfo::CloseButtonClick(TObject *Sender)
{
	FEditInfo->Close();
	FInformation->Close();
	FMain->Close();
}
//---------------------------------------------------------------------------

void __fastcall TFEditInfo::RemoveEditButtonClick(TObject *Sender)
{
	try
	{
		String InformationCode = ADOTable1->FieldByName("Information_code")->AsString;

		if (InformationCode.IsEmpty()) {
			ShowMessage("Будь ласка, виберіть послугу для видалення.");
			return;
		}

		String SQLDeleteService = "DELETE FROM Information WHERE Information_code = :Information_code";
		TADOQuery *ADOQuery1 = new TADOQuery(NULL);
		ADOQuery1->Connection = ADOConnectionEdit;
		ADOQuery1->SQL->Text = SQLDeleteService;
		ADOQuery1->Parameters->ParamByName("Information_code")->Value = InformationCode;
		ADOQuery1->ExecSQL();
		delete ADOQuery1;

		ADOTable1->Close();
		ADOTable1->Open();

		ShowMessage("Запис успішно видалено.");
	}
	catch (const Exception &e)
	{
		ShowMessage("Помилка: " + e.Message);
	}
}
//---------------------------------------------------------------------------

