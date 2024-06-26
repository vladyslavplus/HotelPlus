//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Project1.cpp"
#include "Unit2.h"
#include "Unit5.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFServices *FServices;
//---------------------------------------------------------------------------
__fastcall TFServices::TFServices(TComponent* Owner)
	: TForm(Owner)
{
	ADOTable1->Active = true;
	if(username != "admin")
	{
		RemoveButton->Enabled = false;
		RemoveButton->Visible = false;
		ServiceEdit->Enabled = false;
		CostEdit->Enabled = false;
		RemoveByTitleButton->Enabled = false;
        Button1->Enabled = false;
    }
}
//---------------------------------------------------------------------------
void __fastcall TFServices::BackButtonClick(TObject *Sender)
{
	FServices->Close();
	FMain->Show();
}
//---------------------------------------------------------------------------
void __fastcall TFServices::ExitButtonClick(TObject *Sender)
{
	FServices->Close();
    FMain->Close();
}
//---------------------------------------------------------------------------
void __fastcall TFServices::Button1Click(TObject *Sender)
{
	try
	{
		String ServiceTitle = ServiceEdit->Text;
		double Cost = StrToFloat(CostEdit->Text);

		String SQLInsertService = "INSERT INTO Additional_services (Service_title, Cost) VALUES (:Service_title, :Cost)";
		TADOQuery *ADOQuery1 = new TADOQuery(NULL);
		ADOQuery1->Connection = ADOConnection1;
		ADOQuery1->SQL->Text = SQLInsertService;
		ADOQuery1->Parameters->ParamByName("Service_title")->Value = ServiceTitle;
		ADOQuery1->Parameters->ParamByName("Cost")->Value = Cost;
		ADOQuery1->ExecSQL();
		delete ADOQuery1;

		ADOTable1->Active = false;
		ADOTable1->Active = true;

		ShowMessage("Дані успішно збережено.");
	}
	catch (const Exception &e)
	{
		ShowMessage("Помилка: " + e.Message);
	}
}
//---------------------------------------------------------------------------

void __fastcall TFServices::RemoveButtonClick(TObject *Sender)
{
	DataSource1->DataSet = ADOTable1;
	try
	{
		String ServiceTitle = ADOTable1->FieldByName("Service_title")->AsString;

		if (ServiceTitle.IsEmpty()) {
			ShowMessage("Будь ласка, виберіть послугу для видалення.");
			return;
		}

		String SQLDeleteService = "DELETE FROM Additional_services WHERE Service_title = :Service_title";
		TADOQuery *ADOQuery1 = new TADOQuery(NULL);
		ADOQuery1->Connection = ADOConnection1;
		ADOQuery1->SQL->Text = SQLDeleteService;
		ADOQuery1->Parameters->ParamByName("Service_title")->Value = ServiceTitle;
		ADOQuery1->ExecSQL();
		delete ADOQuery1;

		ADOTable1->Active = false;
		ADOTable1->Active = true;

		ShowMessage("Запис успішно видалено.");
	}
	catch (const Exception &e)
	{
		ShowMessage("Помилка: " + e.Message);
	}
}
//---------------------------------------------------------------------------
void __fastcall TFServices::RemoveByTitleButtonClick(TObject *Sender)
{
	try
	{
		String ServiceTitle = ServiceEdit->Text;

		String SQLDeleteService = "DELETE FROM Additional_services WHERE Service_title = :Service_title";
		TADOQuery *ADOQuery1 = new TADOQuery(NULL);
		ADOQuery1->Connection = ADOConnection1;
		ADOQuery1->SQL->Text = SQLDeleteService;
		ADOQuery1->Parameters->ParamByName("Service_title")->Value = ServiceTitle;
		ADOQuery1->ExecSQL();
		delete ADOQuery1;

		ADOTable1->Active = false;
		ADOTable1->Active = true;

		ShowMessage("Запис успішно видалено.");
	}
	catch (const Exception &e)
	{
		ShowMessage("Помилка: " + e.Message);
	}
}
//---------------------------------------------------------------------------

void __fastcall TFServices::Button2Click(TObject *Sender)
{
	try
	{
		if (!ADOConnection1->Connected) {
            ShowMessage("Помилка з'єднання з базою даних.");
			return;
        }

		String sortColumn;
		if (ComboBox2->Text == "Cost") {
			sortColumn = "Cost";
		}
		else {
			ShowMessage("Будь ласка, оберіть стовпець для сортування.");
            return;
		}

        // Визначення напрямку сортування
		String sortOrder = ComboBox1->Text == "DESC" ? "DESC" : "ASC";

        // Побудова SQL-запиту для сортування даних
		String SQLQuery = "SELECT * FROM Additional_services ORDER BY " + sortColumn + " " + sortOrder;
		ADOQuerySort->Close();
		ADOQuerySort->SQL->Text = SQLQuery;
		ADOQuerySort->Open();

		// Прив'язка результатів до компонента даних
		DataSource1->DataSet = ADOQuerySort;

		ShowMessage("Таблицю відсортовано за " + sortColumn + " " + sortOrder + ".");
    }
    catch (const Exception &e)
    {
        ShowMessage("Помилка: " + e.Message);
	}
}
//---------------------------------------------------------------------------

void __fastcall TFServices::RefreshButtonClick(TObject *Sender)
{
	DataSource1->DataSet = ADOTable1;
	ADOTable1->Active = false;
	ADOTable1->Active = true;
}
//---------------------------------------------------------------------------

