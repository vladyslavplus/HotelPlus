//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit2.h"
#include "Unit7.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFClients *FClients;
//---------------------------------------------------------------------------
__fastcall TFClients::TFClients(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFClients::Button2Click(TObject *Sender)
{
	FClients->Close();
    FMain->Close();
}
//---------------------------------------------------------------------------
void __fastcall TFClients::Button1Click(TObject *Sender)
{
	FClients->Close();
    FMain->Show();
}
//---------------------------------------------------------------------------
void __fastcall TFClients::Button3Click(TObject *Sender)
{
	try
	{
		if (!ADOConnection1->Connected) {
			ShowMessage("Помилка з'єднання з базою даних.");
			return;
		}

		String sortColumn;
		if (ComboBox2->Text == "Client_code") {
			sortColumn = "Client_code";
		}
		else if(ComboBox2->Text == "Country")
		{
			sortColumn = "Country";
		}
		else if(ComboBox2->Text == "Birth_date")
		{
			sortColumn = "Birth_date";
		}
		else {
			ShowMessage("Будь ласка, оберіть стовпець для сортування.");
			return;
		}

		// Визначення напрямку сортування
		String sortOrder = ComboBox1->Text == "DESC" ? "DESC" : "ASC";

		// Побудова SQL-запиту для сортування даних
		String SQLQuery = "SELECT * FROM Clients ORDER BY " + sortColumn + " " + sortOrder;
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

void __fastcall TFClients::RemoveButtonClick(TObject *Sender)
{
	DataSource1->DataSet = ADOTable1;
	try
	{
		String ClientCode = ADOTable1->FieldByName("Client_code")->AsString;

		if (ClientCode.IsEmpty()) {
			ShowMessage("Будь ласка, виберіть послугу для видалення.");
			return;
		}

		String SQLDeleteService = "DELETE FROM Clients WHERE Client_code = :Client_code";
		TADOQuery *ADOQuery1 = new TADOQuery(NULL);
		ADOQuery1->Connection = ADOConnection1;
		ADOQuery1->SQL->Text = SQLDeleteService;
		ADOQuery1->Parameters->ParamByName("Client_code")->Value = ClientCode;
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

void __fastcall TFClients::Button4Click(TObject *Sender)
{
	DataSource1->DataSet = ADOTable1;
	ADOTable1->Close();
	ADOTable1->Open();
}
//---------------------------------------------------------------------------

