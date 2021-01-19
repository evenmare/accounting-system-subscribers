#include "InputForm.h"

System::Void codeproj::InputForm::publisherBox_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e)
{
	return System::Void();
}

System::Void codeproj::InputForm::dateBox_ValueChanged(System::Object^ sender, System::EventArgs^ e)
{
	return System::Void();
}

System::Void codeproj::InputForm::nameBox_TextChanged(System::Object^ sender, System::EventArgs^ e)
{
	return System::Void();
}

System::Void codeproj::InputForm::surnameBox_TextChanged(System::Object^ sender, System::EventArgs^ e)
{
	return System::Void();
}

System::Void codeproj::InputForm::nameBox_start(String^ nameStart)
{
    nameBox->Text = nameStart;
    return System::Void();
}

System::Void codeproj::InputForm::surnameBox_start(String^ surnameStart)
{
    surnameBox->Text = surnameStart;
    return System::Void();
}

System::Void codeproj::InputForm::dateBox_start(String^ dateStart)
{
    dateBox->Value = Convert::ToDateTime(dateStart);
    return System::Void();
}

System::Void codeproj::InputForm::publisherBox_start(array<String^>^ publishers)
{
    publisherBox->Items->AddRange(publishers);
    return System::Void();
}

System::Void codeproj::InputForm::publisherBox_startValue(String^ publisherStart)
{
    publisherBox->SelectedItem = publisherStart;
    return System::Void();
}

System::Void codeproj::InputForm::successButton_Click(System::Object^ sender, System::EventArgs^ e)
{
    if (surnameBox->Text->ToString() != "Введите фамилию" &&
        surnameBox->Text->ToString() != nullptr &&
        nameBox->Text->ToString() != "Введите имя" &&
        nameBox->Text->ToString() != nullptr &&
        publisherBox->SelectedItem->ToString() != "Выберите издательство")
    {
        input_surname = surnameBox->Text->ToString();
        input_name = nameBox->Text->ToString();
        input_date = dateBox->Value.ToShortDateString();
        input_publisher = publisherBox->SelectedItem->ToString();
        success = true;
        this->Close();
    }
    else
        MessageBox::Show("Данных недостаточно", "Ошибка!");
	return System::Void();
}
