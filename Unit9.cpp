//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Project1.cpp"
#include "Unit2.h"
#include "Unit9.h"
#include "Unit10.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFRooms *FRooms;
//---------------------------------------------------------------------------
__fastcall TFRooms::TFRooms(TComponent* Owner)
	: TForm(Owner)
{
	if(username != "admin")
	{
		DBNavigator1->Enabled = false;
    }

}
//---------------------------------------------------------------------------
void __fastcall TFRooms::Button1Click(TObject *Sender)
{
	FRooms->Close();
    FMain->Show();
}
//---------------------------------------------------------------------------
void __fastcall TFRooms::Button2Click(TObject *Sender)
{
	FRooms->Close();
	FMain->Close();
}
//---------------------------------------------------------------------------
void __fastcall TFRooms::EditButtonClick(TObject *Sender)
{
	FRoomsEdit->Show();
	FRooms->Hide();
}
//---------------------------------------------------------------------------

void __fastcall TFRooms::Button3Click(TObject *Sender)
{
	DataSource1->DataSet = ADOTable1;
	ADOTable1->Active = false;
	ADOTable1->Active = true;
}
//---------------------------------------------------------------------------


void __fastcall TFRooms::SortButtonClick(TObject *Sender)
{
	try
	{
		if (!ADOConnection1->Connected) {
			ShowMessage("Помилка з'єднання з базою даних.");
			return;
		}

		String sortColumn;
		if (ComboBox2->Text == "Number") {
			sortColumn = "Number";
		}
		else if(ComboBox2->Text == "Type")
		{
			sortColumn = "Type";
		}
		else {
			ShowMessage("Будь ласка, оберіть стовпець для сортування.");
			return;
		}

		// Визначення напрямку сортування
		String sortOrder = ComboBox1->Text == "DESC" ? "DESC" : "ASC";

		// Побудова SQL-запиту для сортування даних
		String SQLQuery = "SELECT * FROM Rooms ORDER BY " + sortColumn + " " + sortOrder;
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

