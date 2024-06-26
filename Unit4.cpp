//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit2.h"
#include "Unit4.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFRegister *FRegister;
//---------------------------------------------------------------------------
__fastcall TFRegister::TFRegister(TComponent* Owner)
	: TForm(Owner)
{
	FillNumberBox();
	FillServiceBox();
}
//---------------------------------------------------------------------------
void __fastcall TFRegister::ButtonBackRegClick(TObject *Sender)
{
	FRegister->Close();
	FMain->Show();

}
//---------------------------------------------------------------------------

void __fastcall TFRegister::ButtonCloseRegClick(TObject *Sender)
{
	FRegister->Close();
	FMain->Close();
}
//---------------------------------------------------------------------------
void __fastcall TFRegister::ButtonRegisterClick(TObject *Sender)
{
	String FullName = FNEdit->Text;
	String SN = SNEdit->Text;
	String PhoneNumber = PhoneEdit->Text;
	String Country = CountryEdit->Text;
	TDateTime BirthDate = BirthPicker->Date;
	int RoomNumber = StrToInt(NumberBox->Text);
	String SelectedService = ServiceBox->Text;
	TDateTime ArrivalDate = ArrDataPicker->Date;
	TDateTime EvictionDate = EvictDataPicker->Date;

	try
	{
		ADOConnection1->BeginTrans();

		// Перевіряємо, чи існує Room_number в таблиці Rooms і отримуємо його ID
		String SQLGetRoomID = "SELECT Room_code FROM Rooms WHERE Number = :Room_number";
		ADOQuery1->SQL->Text = SQLGetRoomID;
		ADOQuery1->Parameters->ParamByName("Room_number")->Value = RoomNumber;
		ADOQuery1->Open();

		if (ADOQuery1->RecordCount == 0)
			throw Exception("The selected room number does not exist in the Rooms table.");

		int RoomID = ADOQuery1->FieldByName("Room_code")->AsInteger;
		ADOQuery1->Close();

		// Отримуємо ідентифікатор обраної додаткової послуги
		String SQLGetServiceID = "SELECT Service_code FROM Additional_services WHERE Service_title = :Service_title";
		ADOQuery1->SQL->Text = SQLGetServiceID;
		ADOQuery1->Parameters->ParamByName("Service_title")->Value = SelectedService;
		ADOQuery1->Open();

		if (ADOQuery1->RecordCount == 0)
			throw Exception("The selected additional service does not exist in the Additional_services table.");

		int ServiceID = ADOQuery1->FieldByName("Service_code")->AsInteger;
		ADOQuery1->Close();

		// Формуємо SQL-запит для вставки даних у таблицю Clients
		String SQLInsertClient = "INSERT INTO Clients (FN_client, Phone_number, Serial_number, Country, Birth_date) VALUES (:FN_client, :Phone_number, :Serial_number, :Country, :Birth_date)";
		ADOQuery1->SQL->Text = SQLInsertClient;

		ADOQuery1->Parameters->ParamByName("FN_client")->Value = FullName;
		ADOQuery1->Parameters->ParamByName("Phone_number")->Value = PhoneNumber;
		ADOQuery1->Parameters->ParamByName("Serial_number")->Value = SN;
		ADOQuery1->Parameters->ParamByName("Country")->Value = Country;
		ADOQuery1->Parameters->ParamByName("Birth_date")->DataType = ftDate;
		ADOQuery1->Parameters->ParamByName("Birth_date")->Value = BirthDate;

		// Виконуємо запит
		ADOQuery1->ExecSQL();

		// Отримуємо останній вставлений ID клієнта
		ADOQuery1->SQL->Text = "SELECT @@IDENTITY AS LastID";
		ADOQuery1->Open();
		int ClientID = ADOQuery1->FieldByName("LastID")->AsInteger;

		// Закриваємо запит
		ADOQuery1->Close();

		// Формуємо SQL-запит для вставки даних у таблицю Information
		String SQLInsertInfo = "INSERT INTO Information (Client, Room_number, Arrival_data, Eviction_data, Additional_service) VALUES (:Client, :Room_number, :Arrival_data, :Eviction_data, :Additional_service)";
		ADOQuery1->SQL->Text = SQLInsertInfo;
		ADOQuery1->Parameters->ParamByName("Client")->Value = ClientID;
		ADOQuery1->Parameters->ParamByName("Room_number")->Value = RoomID;
		ADOQuery1->Parameters->ParamByName("Arrival_data")->DataType = ftDateTime;
		ADOQuery1->Parameters->ParamByName("Arrival_data")->Value = ArrivalDate;
		ADOQuery1->Parameters->ParamByName("Eviction_data")->DataType = ftDateTime;
		ADOQuery1->Parameters->ParamByName("Eviction_data")->Value = EvictionDate;
		ADOQuery1->Parameters->ParamByName("Additional_service")->Value = ServiceID;

		ADOQuery1->ExecSQL();

		ADOConnection1->CommitTrans();

		ShowMessage("Succeed.");
	}
	catch (const Exception &e)
	{
		ADOConnection1->RollbackTrans();
		ShowMessage("Exception: " + e.Message);
	}
}


//---------------------------------------------------------------------------
void __fastcall TFRegister::FillNumberBox()
{
	try
	{
		ADOQuery1->Close();
		ADOQuery1->SQL->Clear();
		ADOQuery1->SQL->Add("SELECT Number FROM Rooms");
		ADOQuery1->Open();

		NumberBox->Items->Clear();
		while (!ADOQuery1->Eof)
		{
			NumberBox->Items->Add(ADOQuery1->FieldByName("Number")->AsString);
			ADOQuery1->Next();
		}
	}
	catch (Exception &e)
	{
		ShowMessage("Помилка при заповненні NumberBox: " + e.Message);
	}
}

void __fastcall TFRegister::FillServiceBox()
{
	try
	{
		ADOQuery1->Close();
		ADOQuery1->SQL->Clear();
		ADOQuery1->SQL->Add("SELECT Service_title FROM Additional_services");
		ADOQuery1->Open();

		ServiceBox->Items->Clear();
		while (!ADOQuery1->Eof)
		{
			ServiceBox->Items->Add(ADOQuery1->FieldByName("Service_title")->AsString);
			ADOQuery1->Next();
		}
	}
	catch (Exception &e)
	{
		ShowMessage("Помилка при заповненні ServiceBox: " + e.Message);
	}
}
