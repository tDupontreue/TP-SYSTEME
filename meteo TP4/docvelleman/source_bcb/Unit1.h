//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <Buttons.hpp>
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TGroupBox *GroupBox1;
        TCheckBox *CheckBox1;
        TCheckBox *CheckBox2;
  TButton *Connect1;
        TLabel *Label1;
        TGroupBox *GroupBox2;
        TLabel *Label2;
  TTrackBar *DAC1;
        TGroupBox *GroupBox3;
        TLabel *Label3;
  TTrackBar *DAC2;
        TGroupBox *GroupBox4;
        TLabel *Label4;
  TProgressBar *AD1;
  TSpeedButton *OutputTest1;
  TButton *SetAllDigital1;
  TButton *ClearAllDigital1;
  TButton *SetAllAnalog1;
        TButton *ClearAllAnalog1;
        TGroupBox *GroupBox5;
        TLabel *Label5;
  TProgressBar *AD2;
        TGroupBox *GroupBox6;
        TGroupBox *GroupBox7;
        TGroupBox *GroupBox8;
  TEdit *Counter1;
  TButton *ResetCounter1;
  TRadioGroup *DebounceTime1;
        TGroupBox *GroupBox9;
  TEdit *Counter2;
  TButton *ResetCounter2;
  TRadioGroup *DebounceTime2;
        TTimer *Timer1;
        TTimer *Timer2;
  TCheckBox *CheckBox3;
  TCheckBox *CheckBox4;
  TCheckBox *CheckBox5;
  TCheckBox *CheckBox6;
  TCheckBox *CheckBox7;
        void __fastcall Connect1Click(TObject *Sender);
  void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
  void __fastcall SetAllDigital1Click(TObject *Sender);
  void __fastcall OutBoxClick(TObject *Sender);
  void __fastcall ClearAllDigital1Click(TObject *Sender);
  void __fastcall SetAllAnalog1Click(TObject *Sender);
  void __fastcall DAC1Change(TObject *Sender);
  void __fastcall DAC2Change(TObject *Sender);
  void __fastcall ClearAllAnalog1Click(TObject *Sender);
  void __fastcall FormCreate(TObject *Sender);
  void __fastcall Timer1Timer(TObject *Sender);
  void __fastcall ResetCounter1Click(TObject *Sender);
  void __fastcall ResetCounter2Click(TObject *Sender);
  void __fastcall DebounceTime1Click(TObject *Sender);
  void __fastcall DebounceTime2Click(TObject *Sender);
  void __fastcall OutputTest1Click(TObject *Sender);
  void __fastcall Timer2Timer(TObject *Sender);
private:	// User declarations
  TCheckBox* op[8];
  TCheckBox* ip[5];
public:		// User declarations
        __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
