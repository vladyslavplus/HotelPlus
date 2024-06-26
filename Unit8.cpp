//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Project1.cpp"
#include "Unit2.h"
#include "Unit8.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFRoomTypes *FRoomTypes;
//---------------------------------------------------------------------------
__fastcall TFRoomTypes::TFRoomTypes(TComponent* Owner)
	: TForm(Owner)
{
	if(username != "admin")
	{
		RemoveButton->Enabled = false;
		AddButton->Enabled = false;
		Edit1->Enabled = false;
		Edit2->Enabled = false;
    }
}
//---------------------------------------------------------------------------
void __fastcall TFRoomTypes::Button1Click(TObject *Sender)
{
	FRoomTypes->Close();
	FMain->Show();
}
//---------------------------------------------------------------------------
void __fastcall TFRoomTypes::Button2Click(TObject *Sender)
{
	FRoomTypes->Close();
	FMain->Close();
}
//---------------------------------------------------------------------------
void __fastcall TFRoomTypes::Button3Click(TObject *Sender)
{
	DataSource1->DataSet = ADOTable1;
	ADOTable1->Close();
	ADOTable1->Open();
}
//---------------------------------------------------------------------------
void __fastcall TFRoomTypes::RemoveButtonClick(TObject *Sender)
{
	DataSource1->DataSet = ADOTable1;
	try
	{
		String TypeCode = ADOTable1->FieldByName("Type_code")->AsString;

		if (TypeCode.IsEmpty()) {
			ShowMessage("Будь ласка, виберіть послугу для видалення.");
			return;
		}

		String SQLDeleteService = "DELETE FROM Room_type WHERE Type_code = :Type_code";
		TADOQuery *ADOQuery1 = new TADOQuery(NULL);
		ADOQuery1->Connection = ADOConnection1;
		ADOQuery1->SQL->Text = SQLDeleteService;
		ADOQuery1->Parameters->ParamByName("Type_code")->Value = TypeCode;
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
void __fastcall TFRoomTypes::AddButtonClick(TObject *Sender)
{
	try
	{
		String RoomType = Edit1->Text;
		double TypeCost = StrToFloat(Edit2->Text);

		String SQLInsertService = "INSERT INTO Room_type (Type, Type_cost) VALUES (:Type, :Type_cost)";
		TADOQuery *ADOQuery1 = new TADOQuery(NULL);
		ADOQuery1->Connection = ADOConnection1;
		ADOQuery1->SQL->Text = SQLInsertService;
		ADOQuery1->Parameters->ParamByName("Type")->Value = RoomType;
		ADOQuery1->Parameters->ParamByName("Type_cost")->Value = TypeCost;
		ADOQuery1->ExecSQL();
		delete ADOQuery1;

		DataSource1->DataSet = ADOTable1;
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
void __fastcall TFRoomTypes::SortButtonClick(TObject *Sender)
{
	try
	{
		if (!ADOConnection1->Connected) {
			ShowMessage("Помилка з'єднання з базою даних.");
			return;
		}

		String sortColumn = "Type_cost";

		String sortOrder = ComboBox1->Text == "DESC" ? "DESC" : "ASC";

		// Побудова SQL-запиту для сортування даних
		String SQLQuery = "SELECT * FROM Room_type ORDER BY " + sortColumn + " " + sortOrder;
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
