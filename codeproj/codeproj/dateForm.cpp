#include "dateForm.h"
using namespace System;
using namespace System::Windows::Forms;

System::Void codeproj::dateForm::dateFromPicker_ValueChanged(System::Object^ sender, System::EventArgs^ e)
{
    return System::Void();
}

System::Void codeproj::dateForm::dateToPicker_ValueChanged(System::Object^ sender, System::EventArgs^ e)
{
    return System::Void();
}

System::Void codeproj::dateForm::SuccessButton_Click(System::Object^ sender, System::EventArgs^ e)
{
    if (dateFromPicker->Text->ToString() != nullptr &&
        dateToPicker->Text->ToString() != nullptr) {
        input_dateFrom = dateFromPicker->Value.ToShortDateString();
        input_dateTo = dateToPicker->Value.ToShortDateString();
        success = true;
        this->Close();
    }
    return System::Void();
}
