//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "Unit2.h"
#include "Unit3.h"
#include "Unit6.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFInformation *FInformation;
//---------------------------------------------------------------------------
__fastcall TFInformation::TFInformation(TComponent* Owner)
	: TForm(Owner)
{

	ADOTableInformation->Active = false;
	ADOTableInformation->Active = true;
}
//---------------------------------------------------------------------------
void __fastcall TFInformation::BackButtonClick(TObject *Sender)
{
	FInformation->Close();
	FMain->Show();
}
//---------------------------------------------------------------------------
void __fastcall TFInformation::CloseButtonClick(TObject *Sender)
{
	FInformation->Close();
	FMain->Close();
}
//---------------------------------------------------------------------------
void __fastcall TFInformation::Button1Click(TObject *Sender)
{
	FInformation->Close();
	FEditInfo->Show();
	FEditInfo->ADOTable1->Active = false;
	FEditInfo->ADOTable1->Active = true;
}
//---------------------------------------------------------------------------

void __fastcall TFInformation::RefreshButtonClick(TObject *Sender)
{
	DataSource1->DataSet = ADOTableInformation;
	ADOTableInformation->Active = false;
	ADOTableInformation->Active = true;
}
//---------------------------------------------------------------------------

void __fastcall TFInformation::Button2Click(TObject *Sender)
{
    try
	{
		if (!ADOConnection->Connected) {
            ShowMessage("Помилка з'єднання з базою даних.");
            return;
        }

		String sortColumn;
        if (ComboBox2->Text == "Number") {
            sortColumn = "Number";
		}
		else {
            ShowMessage("Будь ласка, оберіть стовпець для сортування.");
            return;
		}

        String sortOrder = ComboBox1->Text == "DESC" ? "DESC" : "ASC";

        String SQLQuery = "SELECT * FROM GetInfo ORDER BY " + sortColumn + " " + sortOrder;
        ADOQuerySort->Close();
        ADOQuerySort->SQL->Text = SQLQuery;
        ADOQuerySort->Open();

		DataSource1->DataSet = ADOQuerySort;

        ShowMessage("Таблицю відсортовано за " + sortColumn + " " + sortOrder + ".");
    }
    catch (const Exception &e)
    {
        ShowMessage("Помилка: " + e.Message);
    }
}
//---------------------------------------------------------------------------

