//---------------------------------------------------------------------------

#ifndef Unit4H
#define Unit4H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Data.DB.hpp>
#include <Data.Win.ADODB.hpp>
#include <Vcl.ComCtrls.hpp>
//---------------------------------------------------------------------------
class TFRegister : public TForm
{
__published:	// IDE-managed Components
	TLabel *Label1;
	TEdit *FNEdit;
	TLabel *Label2;
	TButton *ButtonBackReg;
	TButton *ButtonCloseReg;
	TEdit *PhoneEdit;
	TLabel *Label3;
	TEdit *SNEdit;
	TLabel *Label4;
	TEdit *CountryEdit;
	TLabel *Label5;
	TLabel *Label6;
	TLabel *Label7;
	TLabel *Label8;
	TLabel *Label9;
	TComboBox *NumberBox;
	TComboBox *ServiceBox;
	TButton *ButtonRegister;
	TADOConnection *ADOConnection1;
	TADOQuery *ADOQuery1;
	TDateTimePicker *BirthPicker;
	TDateTimePicker *EvictDataPicker;
	TDateTimePicker *ArrDataPicker;
	void __fastcall ButtonBackRegClick(TObject *Sender);
	void __fastcall ButtonCloseRegClick(TObject *Sender);
	void __fastcall ButtonRegisterClick(TObject *Sender);
private:	// User declarations
	void __fastcall FillNumberBox();
	void __fastcall FillServiceBox();
public:		// User declarations
	__fastcall TFRegister(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFRegister *FRegister;
//---------------------------------------------------------------------------
#endif
