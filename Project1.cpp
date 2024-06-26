//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <tchar.h>
#include <memory>
#include "Unit1.h"
//---------------------------------------------------------------------------
#include <Vcl.Styles.hpp>
#include <Vcl.Themes.hpp>
USEFORM("Unit5.cpp", FServices);
USEFORM("Unit4.cpp", FRegister);
USEFORM("Unit7.cpp", FClients);
USEFORM("Unit6.cpp", FEditInfo);
USEFORM("Unit1.cpp", FLogin);
USEFORM("Unit3.cpp", FInformation);
USEFORM("Unit2.cpp", FMain);
USEFORM("Unit8.cpp", FRoomTypes);
USEFORM("Unit9.cpp", FRooms);
USEFORM("Unit10.cpp", FRoomsEdit);
//---------------------------------------------------------------------------
extern String username;
//---------------------------------------------------------------------------
int WINAPI _tWinMain(HINSTANCE, HINSTANCE, LPTSTR, int)
{
	try
	{
		Application->Initialize();
		Application->MainFormOnTaskBar = true;

		TStyleManager::TrySetStyle("Aqua Light Slate");

        std::unique_ptr<TFLogin> FLogin(new TFLogin(NULL));
        if (FLogin->ShowModal() == mrOk)
		{
			Application->CreateForm(__classid(TFMain), &FMain);
			Application->CreateForm(__classid(TFInformation), &FInformation);
			Application->CreateForm(__classid(TFRegister), &FRegister);
			Application->CreateForm(__classid(TFServices), &FServices);
			Application->CreateForm(__classid(TFEditInfo), &FEditInfo);
			Application->CreateForm(__classid(TFClients), &FClients);
			Application->CreateForm(__classid(TFRoomTypes), &FRoomTypes);
			Application->CreateForm(__classid(TFRooms), &FRooms);
			Application->CreateForm(__classid(TFRoomsEdit), &FRoomsEdit);


            Application->Run();
		}
	}
	catch (Exception &exception)
	{
		Application->ShowException(&exception);
	}
	catch (...)
	{
		try
		{
			throw Exception("");
		}
		catch (Exception &exception)
		{
			Application->ShowException(&exception);
		}
	}
	return 0;
}
//---------------------------------------------------------------------------
