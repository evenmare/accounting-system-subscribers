#include "searchForm.h"
// ���������
using namespace System;
using namespace System::Windows::Forms;

System::Void codeproj::searchForm::successButton_Click(System::Object^ sender, System::EventArgs^ e)
{
    if (SurnameBox->Text->ToString() != "������� �������" ||
        SurnameBox->Text->ToString() != nullptr ||
        nameBox->Text->ToString() != "������� ���" ||
        nameBox->Text->ToString() != nullptr)
    {
        input_surname = SurnameBox->Text->ToString();
        input_name = nameBox->Text->ToString();
   
        if (dateCheckBox->Checked) {
            input_date = dateBox->Value.ToShortDateString();
        }
        success = true;
        this->Close();
    }
    else
        MessageBox::Show("������ ��� ������ ������������", "������!");
    return System::Void();
}

