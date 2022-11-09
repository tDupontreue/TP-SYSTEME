//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "K8055D.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
  bool DisableOtherFunctionCall = false;
  int n=8;
//---------------------------------------------------------------------------

__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Connect1Click(TObject *Sender)
{
  int CardAddr = 3 - (int(CheckBox1->Checked) + int(CheckBox2->Checked) * 2);
  int h = OpenDevice(CardAddr);
  switch (h) {
    case  0 :
    case  1 :
    case  2 :
    case  3 :
      Label1->Caption = "Card " + IntToStr(h) + " connected";
      break;
    case  -1 :
      Label1->Caption = "Card " + IntToStr(CardAddr) + " not found";
  }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormClose(TObject *Sender, TCloseAction &Action)
{
  CloseDevice();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormCreate(TObject *Sender)
{
    for (int i=0;i<8;i++)    // Create Output Check Boxes
    {
        op[i] = new TCheckBox(GroupBox7);
        op[i]->Name = "Outbox" + IntToStr(i+1);
        op[i]->Caption = IntToStr(i+1);
        op[i]->Width = 30;
        op[i]->Left = 28 * i + 12;
        op[i]->Top = 20;
        op[i]->Parent = GroupBox7;
        op[i]->OnClick = OutBoxClick;
    }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SetAllDigital1Click(TObject *Sender)
{
  SetAllDigital();
  DisableOtherFunctionCall = true;
  for (int i=0;i<8;i++)
  {
    op[i]->Checked = true;
  }
  DisableOtherFunctionCall = false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::OutBoxClick(TObject *Sender)
{
    int k = 0;
    int n = 1;
    for (int i=0;i<8;i++)
    {
      if (op[i]->Checked == true)
      {
        k = k + n;
      }
      n = n * 2;
    }
    if (DisableOtherFunctionCall == false)
      WriteAllDigital(k);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ClearAllDigital1Click(TObject *Sender)
{
  ClearAllDigital();
  DisableOtherFunctionCall = true;
  for (int i=0;i<8;i++)
  {
    op[i]->Checked = false;
  }
  DisableOtherFunctionCall = false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SetAllAnalog1Click(TObject *Sender)
{
  SetAllAnalog();
  DisableOtherFunctionCall = true;
  DAC1->Position = 0;
  DAC2->Position = 0;
  DisableOtherFunctionCall = false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ClearAllAnalog1Click(TObject *Sender)
{
  ClearAllAnalog();
  DisableOtherFunctionCall = true;
  DAC1->Position = 255;
  DAC2->Position = 255;
  DisableOtherFunctionCall = false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::DAC1Change(TObject *Sender)
{
  if (DisableOtherFunctionCall == false)
    OutputAnalogChannel(1, 255-DAC1->Position);
  Label2->Caption = 255 - DAC1->Position;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::DAC2Change(TObject *Sender)
{
  if (DisableOtherFunctionCall == false)
    OutputAnalogChannel(2, 255-DAC2->Position);
  Label3->Caption = 255 - DAC2->Position;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
  Timer1->Enabled = false;
  long Data1;
  long Data2;
  long i;
  ReadAllAnalog(&Data1, &Data2);
  AD1->Position = Data1;
  AD2->Position = Data2;
  Label4->Caption = IntToStr(Data1);
  Label5->Caption = IntToStr(Data2);
  Counter1->Text = IntToStr(ReadCounter(1));
  Counter2->Text = IntToStr(ReadCounter(2));
  i = ReadAllDigital();
  CheckBox3->Checked = (i & 1)>0;
  CheckBox4->Checked = (i & 2)>0;
  CheckBox5->Checked = (i & 4)>0;
  CheckBox6->Checked = (i & 8)>0;
  CheckBox7->Checked = (i & 16)>0;
  Timer1->Enabled = true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ResetCounter1Click(TObject *Sender)
{
  ResetCounter(1);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ResetCounter2Click(TObject *Sender)
{
  ResetCounter(2);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::DebounceTime1Click(TObject *Sender)
{
  long t1;
   switch (DebounceTime1->ItemIndex) {
    case  0 : t1 = 0;
      break;
    case  1 : t1 = 2;
      break;
    case  2 : t1 = 10;
      break;
    case  3 : t1 = 1000;
   }
  SetCounterDebounceTime(1,t1);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::DebounceTime2Click(TObject *Sender)
{
  long t2;
   switch (DebounceTime2->ItemIndex) {
    case  0 : t2 = 0;
      break;
    case  1 : t2 = 2;
      break;
    case  2 : t2 = 10;
      break;
    case  3 : t2 = 1000;
   }
  SetCounterDebounceTime(2,t2);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::OutputTest1Click(TObject *Sender)
{
    Timer2->Enabled = OutputTest1->Down;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Timer2Timer(TObject *Sender)
{
  ClearDigitalChannel(n);
  op[n-1]->Checked = false;
  n = n +1;
  if (n == 9)
    n = 1;
  SetDigitalChannel(n);
  op[n-1]->Checked = true;
}
//---------------------------------------------------------------------------




