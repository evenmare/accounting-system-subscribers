#include "mainForm.h"
#include "searchForm.h"
#include "dateForm.h"
#include "InputForm.h"

// ���������
using namespace System;
using namespace System::Windows::Forms;
using namespace System::Data::OleDb; 

[STAThreadAttribute]
int main(array<String^>^ arg) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	codeproj::mainForm form;
	Application::Run(% form);
}

// ���������� ����
System::Void codeproj::mainForm::UpdateBase(String^ query)
{
	Boolean isvalid = true;
	if (fileName != nullptr)
	{
		System::Boolean error_status = false;

		if (query == "")
			query = "SELECT Person.*, [Connection].ID_Publisher, Publisher.P_Name FROM(([Connection] INNER JOIN Person ON[Connection].ID_Person = Person.ID) INNER JOIN Publisher ON[Connection].ID_Publisher = Publisher.ID) ORDER BY[Connection].ID_Publisher";
		
		OleDbDataReader^ dbReader;
		// ��������� ������
		OleDbCommand^ dbCommand = gcnew OleDbCommand(query, dbConnection);
		try {
			dbReader = dbCommand->ExecuteReader();
		}
		catch (OleDbException^ e) {
			MessageBox::Show("�� �� ������������� ���������� �������!", "������");
			isvalid = false;
		}
		
		if (isvalid == true) {
			OleDbCommand^ pubdbCommand = gcnew OleDbCommand("SELECT Publisher.* FROM Publisher", dbConnection);
			OleDbDataReader^ pubdbReader = pubdbCommand->ExecuteReader();

			if (dbReader->HasRows == false && pubdbReader->HasRows == false) // �������� �� ������������� ������ � ��
				MessageBox::Show("�� �����!", "������");
			else {
				dbReader->Close(); pubdbReader->Close();
				dbReader = dbCommand->ExecuteReader(); pubdbReader = pubdbCommand->ExecuteReader();
				OutputBase(dbReader); OutputPublisherBase(pubdbReader);
			}
		}
	}
	else
		MessageBox::Show("���� �� �� ������", "������");

	return System::Void();
}

// ����� ��
System::Void codeproj::mainForm::OutputBase(OleDbDataReader^ databaseReader)
{
	dbOutput->Rows->Clear();
	String^ date;
	while (databaseReader->Read()) {
		date = databaseReader["Date"]->ToString();
		date = date->Substring(0, 10);
		// ������� � dataGrid ��� ������
		dbOutput->Rows->Add(databaseReader["ID"], databaseReader["Surname"], databaseReader["Name"], date, databaseReader["ID_Publisher"], databaseReader["P_Name"]);
	}
	databaseReader->Close();
	return System::Void();
}

// ����� �� ���������
System::Void codeproj::mainForm::OutputPublisherBase(OleDbDataReader^ databaseReader) {
	publishersGrid->Rows->Clear();
	while (databaseReader->Read()) {
		publishersGrid->Rows->Add(databaseReader["ID"], databaseReader["P_Name"]);
	}
}

// �������� �����
System::Void codeproj::mainForm::openButton_Click(System::Object^ sender, System::EventArgs^ e)
{
	System::Boolean error_status = false;

	// ��������� Open File
	OpenFileDialog^ openDlg = gcnew OpenFileDialog();
	openDlg->InitialDirectory = "C:\\Users"; // \fuzzyfaLL\OneDrive\Desktop\������_�� �������� ��� �����
	openDlg->Filter = "Database File (*.mdb)|*.mdb|All files (*.*)|*.*";
	openDlg->FilterIndex = 1;
	openDlg->RestoreDirectory = true;

	if (openDlg->ShowDialog() == System::Windows::Forms::DialogResult::OK)
	{
		System::Boolean error_status = false;

		fileName = openDlg->FileName;
		directory = connectionString + fileName;

		if (dbConnection != nullptr) {
			try {
				dbConnection->Close();
				MessageBox::Show("�� ���������!", "�����������");
			}
			catch (OleDbException^ e) {
				MessageBox::Show("�� ������� ������� ����������� � ��!", "������");
			}
		}

		dbConnection = gcnew OleDbConnection(directory);

		try {
			dbConnection->Open();
		}
		catch (OleDbException^ e)
		{
			MessageBox::Show("���� �� ���������!", "������ ����������� � ��!");
			error_status = true;
		}
		
		if (error_status == false) {
			UpdateBase("");
		}

		return System::Void();
	}
}

// ����� [searchForm]
System::Void codeproj::mainForm::searchButton_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (directory != nullptr) {
		searchForm^ searchWindow = gcnew searchForm;
		searchWindow->ShowDialog();

		if (searchWindow->success == true) {

			String^ surname = searchWindow->input_surname;
			if (surname == "������� �������") {
				surname = nullptr;
			}
			String^ name = searchWindow->input_name;
			if (name == "������� ���") {
				name = nullptr;
			}
			String^ date = searchWindow->input_date;

			/*OleDbConnection^ dbConnection = gcnew OleDbConnection(directory);
			dbConnection->Open();*/
			String^ requestString = "SELECT Person.*, [Connection].ID_Publisher, Publisher.P_Name FROM(([Connection] INNER JOIN Person ON[Connection].ID_Person = Person.ID) INNER JOIN Publisher ON[Connection].ID_Publisher = Publisher.ID) WHERE (";
			if (surname != nullptr)
				requestString += "[Person].Surname = @surname ";
			if (name != nullptr) {
				if (surname != nullptr)
					requestString += "AND ";
				requestString += "[Person].Name = @name";
			}
			if (date == nullptr)
				requestString += ") ORDER BY[Connection].ID_Publisher";
			else {
				if (name != nullptr || surname != nullptr)
					requestString += " AND ";
				requestString += "[Person].Date = @date) ORDER BY[Connection].ID_Publisher";
			}
			OleDbCommand^ dbCommand = gcnew OleDbCommand(requestString, dbConnection);
			if (surname != nullptr)
				dbCommand->Parameters->AddWithValue("surname", surname);
			if (name != nullptr)
				dbCommand->Parameters->AddWithValue("name", name);
			if (date != nullptr)
				dbCommand->Parameters->AddWithValue("date", date);
			OleDbDataReader^ dbReader = dbCommand->ExecuteReader();
			dbReader->Read(); dbReader->Close(); dbReader = dbCommand->ExecuteReader();
			if (dbReader->HasRows == false)
				MessageBox::Show("�� ������� ������� ������ �� ���� �������!", "������");
			OutputBase(dbReader);
		}
	}
	else
		MessageBox::Show("���� �� �� ������!", "������");
	return System::Void();
}

// ����� �� ���� [dateForm]
System::Void codeproj::mainForm::dateSearchButton_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (directory != nullptr) {
		dateForm^ dateWindow = gcnew dateForm;
		dateWindow->ShowDialog();

		if (dateWindow->success == true) {

			String^ dateFrom = dateWindow->input_dateFrom;
			String^ dateTo = dateWindow->input_dateTo;

			String^ requestString = "SELECT Person.*, [Connection].ID_Publisher, Publisher.P_Name FROM(([Connection] INNER JOIN Person ON[Connection].ID_Person = Person.ID) INNER JOIN Publisher ON[Connection].ID_Publisher = Publisher.ID) WHERE ([Person].Date >= @dateFrom AND [Person].Date <= @dateTo) ORDER BY[Connection].ID_Publisher";
			OleDbCommand^ dbCommand = gcnew OleDbCommand(requestString, dbConnection);
			dbCommand->Parameters->AddWithValue("dateFrom", dateFrom);
			dbCommand->Parameters->AddWithValue("dateTo", dateTo);
			OleDbDataReader^ dbReader = dbCommand->ExecuteReader();
			dbReader->Read(); dbReader->Close(); dbReader = dbCommand->ExecuteReader();
			dbOutput->Rows->Clear();
			if (dbReader->HasRows == false)
				MessageBox::Show("�� ������� ������� ������ �� ���� �������!", "������");
			OutputBase(dbReader);
		}
	}
	else
		MessageBox::Show("���� �� �� ������!", "������");
	return System::Void();
}

// ������������ ����� ��������
System::Void codeproj::mainForm::findmaxButton_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (directory != nullptr)
	{
		OleDbCommand^ dbCommand = gcnew OleDbCommand("SELECT TOP 1 [ID_Person], COUNT([ID_Person]) AS Clown FROM[Connection] GROUP BY [ID_Person] ORDER BY COUNT(ID_Person) DESC", dbConnection);
		OleDbDataReader^ dbReader = dbCommand->ExecuteReader();
		dbReader->Read();
		dbReader->Close();
		dbReader = dbCommand->ExecuteReader();
		int counter = 0;
		OleDbCommand^ bbCommand;
		OleDbDataReader^ bbReader;
		String^ id_number;

		dbOutput->Rows->Clear();
		while (dbReader->Read())
		{
			bbCommand = gcnew OleDbCommand("SELECT Person.*, [Connection].ID_Publisher, Publisher.P_Name FROM(([Connection] INNER JOIN Person ON[Connection].ID_Person = Person.ID) INNER JOIN Publisher ON[Connection].ID_Publisher = Publisher.ID) WHERE ([Person].ID = @number)", dbConnection);
			id_number = dbReader["ID_Person"]->ToString();
			bbCommand->Parameters->AddWithValue("number", id_number);
			bbReader = bbCommand->ExecuteReader();
			bbReader->Read(); bbReader->Close(); bbReader = bbCommand->ExecuteReader();
			OutputBase(bbReader);
		}
	}
	else
		MessageBox::Show("���� �� �� ������!", "������");
	return System::Void();
}

// ������� ������
System::Void codeproj::mainForm::deleteButton_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (directory != nullptr) {
		if (dbOutput->SelectedRows->Count == 1) {
			int index = dbOutput->SelectedRows[0]->Index;
			if (dbOutput->Rows[index]->Cells[0]->Value == nullptr ||
				dbOutput->Rows[index]->Cells[1]->Value == nullptr ||
				dbOutput->Rows[index]->Cells[2]->Value == nullptr ||
				dbOutput->Rows[index]->Cells[3]->Value == nullptr ||
				dbOutput->Rows[index]->Cells[4]->Value == nullptr) {
				MessageBox::Show("�� ��� ������ ���� �������!", "������");
				return;
			}
			else
			{
				Boolean isvalid = true;
				String^ id = dbOutput->Rows[index]->Cells[0]->Value->ToString();
				String^ pubid = dbOutput->Rows[index]->Cells[4]->Value->ToString();

				if (MessageBox::Show("������ �� �� ������� ��� ������ � ��������?", "����������", MessageBoxButtons::YesNo, MessageBoxIcon::Question) == System::Windows::Forms::DialogResult::No) {
					OleDbCommand^ dbCommand = gcnew OleDbCommand("SELECT [ID_Person], [ID_Publisher] FROM [Connection] WHERE([ID_Person] = @id_person AND [ID_Publisher] = @id_pub)", dbConnection);
					dbCommand->Parameters->AddWithValue("id_person", id);
					dbCommand->Parameters->AddWithValue("id_pub", pubid);
					OleDbDataReader^ dbReader = dbCommand->ExecuteReader();
					dbReader->Read(); dbReader->Close(); dbReader = dbCommand->ExecuteReader(); dbReader->Read();

					if (dbReader->HasRows == true) {
						dbReader->Close();
						dbCommand = gcnew OleDbCommand("DELETE FROM [Connection] WHERE (ID_Person = @ID AND ID_Publisher = @pubid)", dbConnection);
						dbCommand->Parameters->AddWithValue("ID", id);
						dbCommand->Parameters->AddWithValue("pubid", pubid);
						if (dbCommand->ExecuteNonQuery() != 1) {
							MessageBox::Show("��� ������� � Connection �������� ������!");
							isvalid = false;
						}
					}
				}
				else {
					OleDbCommand^ dbCommand = gcnew OleDbCommand("SELECT [ID_Person], [ID_Publisher] FROM [Connection] WHERE([ID_Person] = @ID)", dbConnection);
					dbCommand->Parameters->AddWithValue("ID", id);
					OleDbDataReader^ dbReader = dbCommand->ExecuteReader();
					dbReader->Read(); dbReader->Close(); dbReader = dbCommand->ExecuteReader(); dbReader->Read();

					if (dbReader->HasRows == true) {
						dbReader->Close();
						dbCommand = gcnew OleDbCommand("DELETE FROM [Person] WHERE (ID = @ID)", dbConnection);
						dbCommand->Parameters->AddWithValue("ID", id);
						if (dbCommand->ExecuteNonQuery() != 1) {
							MessageBox::Show("��� ������� � Person �������� ������!");
							isvalid = false;
						}
					}
				}
				if (isvalid)
					MessageBox::Show("�������� ������ �������!", "���������");
				UpdateBase("");
			}
		}
	}
	else
		MessageBox::Show("���� �� �� ������!", "������");
	return System::Void();
}

// �������� ������
System::Void codeproj::mainForm::updateButton_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (directory != nullptr) {

		// �������� �� ��������� ������
		if (dbOutput->SelectedRows->Count != 1) {
			MessageBox::Show("��� ���������� ������ �������� ���� ������.", "��������");
			return;
		}

		int index = dbOutput->SelectedRows[0]->Index;

		//  �������� �� �������� ������
		if (dbOutput->Rows[index]->Cells[0]->Value == nullptr ||
			dbOutput->Rows[index]->Cells[1]->Value == nullptr ||
			dbOutput->Rows[index]->Cells[2]->Value == nullptr ||
			dbOutput->Rows[index]->Cells[3]->Value == nullptr ||
			dbOutput->Rows[index]->Cells[4]->Value == nullptr) {
			MessageBox::Show("�� ��� ������ ���� �������!", "������");
			return;
		}

		else
		{
			Boolean isvalid = true;
			String^ perId = dbOutput->Rows[index]->Cells[0]->Value->ToString();
			String^ surname = dbOutput->Rows[index]->Cells[1]->Value->ToString();
			String^ name = dbOutput->Rows[index]->Cells[2]->Value->ToString();
			String^ date = dbOutput->Rows[index]->Cells[3]->Value->ToString();
			String^ start_pubId = dbOutput->Rows[index]->Cells[4]->Value->ToString();
			String^ pubId;
			String^ publisher = dbOutput->Rows[index]->Cells[5]->Value->ToString();
			OleDbCommand^ dbCommand;
			OleDbDataReader^ dbReader;

			// ��������� ������ ���������
			int count = publishersGrid->RowCount - 1;
			array<String^>^ publishersList = gcnew array<String^>(count);
			for (int i = 0; i < count; i++) {
				publishersList[i] = publishersGrid->Rows[i]->Cells[1]->Value->ToString();
			}
			InputForm^ inputWindow = gcnew InputForm;
			inputWindow->publisherBox_start(publishersList);
			inputWindow->dateBox_start(date);
			inputWindow->nameBox_start(name);
			inputWindow->surnameBox_start(surname);
			inputWindow->publisherBox_startValue(publisher);

			inputWindow->ShowDialog();

			if (inputWindow->success == true) {

				surname = checkString(inputWindow->input_surname);
				name = checkString(inputWindow->input_name);
				date = inputWindow->input_date;
				publisher = inputWindow->input_publisher;

				// �������� ��������� ������
				if (surname == nullptr || name == nullptr) {
					MessageBox::Show("��������� ������������ ��������� ������! � ������� � ����� �� ������ ���� ����!", "������");
					return;
				}

				// ���������� ID ��������
				dbCommand = gcnew OleDbCommand("SELECT ID FROM [Publisher] WHERE(P_Name = @Publishers)", dbConnection);
				dbCommand->Parameters->AddWithValue("Publishers", publisher);
				dbReader = dbCommand->ExecuteReader();
				dbReader->Read(); dbReader->Close(); dbReader = dbCommand->ExecuteReader(); dbReader->Read();
				pubId = dbReader["ID"]->ToString();

				dbCommand = gcnew OleDbCommand("UPDATE [Person] SET [Surname] = @Surname, [Name] = @Name, [Date] = @Date WHERE ([ID] = @ID)", dbConnection);
				dbCommand->Parameters->AddWithValue("Surname", surname);
				dbCommand->Parameters->AddWithValue("Name", name);
				dbCommand->Parameters->AddWithValue("Date", date);
				dbCommand->Parameters->AddWithValue("ID", perId);
				if (dbCommand->ExecuteNonQuery() != 1) {
					MessageBox::Show("������ ���������� ������� � ������� Person!", "������");
					isvalid = false;
				}

				if (isvalid != false)
				{
					dbCommand = gcnew OleDbCommand("SELECT [ID_Person], [ID_Publisher] FROM [Connection] WHERE([ID_Person] = @id_person) AND ([ID_Publisher] = @id_pub)", dbConnection);
					dbCommand->Parameters->AddWithValue("id_person", perId);
					dbCommand->Parameters->AddWithValue("id_pub", start_pubId);
					dbReader = dbCommand->ExecuteReader();
					dbReader->Read(); dbReader->Close(); dbReader = dbCommand->ExecuteReader(); dbReader->Read();
					//// ������ �� ���������� � Connection
					if (dbReader->HasRows == true) {
						dbCommand = gcnew OleDbCommand("UPDATE [Connection] SET [ID_Publisher] = @idpub WHERE ([ID_Person] = @ID)", dbConnection);
						dbCommand->Parameters->AddWithValue("idpub", pubId);
						dbCommand->Parameters->AddWithValue("ID", perId);
						if (dbCommand->ExecuteNonQuery() != 1) {
							MessageBox::Show("������ ���������� ������� Connection!", "������");
							isvalid = false;
						}
					}
					else {
						MessageBox::Show("������ � ������� Connection ��������!", "������");
					}
				}
				if (isvalid)
					MessageBox::Show("���������� ������ �������!", "���������");
				//dbConnection->Close();
				UpdateBase("");
			}
		}
	}
	else
		MessageBox::Show("���� �� �� ������!", "������");
}

// �������� ������
System::Void codeproj::mainForm::insertButton_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (directory != nullptr) {

		int index;
		Boolean switcher = false;
		Boolean isvalid = true;
		String^ perId;
		String^ surname;
		String^ name;
		String^ date;
		String^ pubId;
		String^ publisher;
		OleDbCommand^ dbCommand;
		OleDbDataReader^ dbReader;

		// ��������� ������ ���������
		int count = publishersGrid->RowCount - 1;
		array<String^>^ publishersList = gcnew array<String^>(count);
		for (int i = 0; i < count; i++) {
			publishersList[i] = publishersGrid->Rows[i]->Cells[1]->Value->ToString();
		}

		// �������� �� ����� ������
		if (dbOutput->SelectedRows->Count != 1) {
			switcher = true;
		}
		else {
			index = dbOutput->SelectedRows[0]->Index;
			if (dbOutput->Rows[index]->Cells[0]->Value == nullptr ||
				dbOutput->Rows[index]->Cells[1]->Value == nullptr ||
				dbOutput->Rows[index]->Cells[2]->Value == nullptr ||
				dbOutput->Rows[index]->Cells[3]->Value == nullptr ||
				dbOutput->Rows[index]->Cells[4]->Value == nullptr)
				switcher = true;
		}

		InputForm^ inputWindow = gcnew InputForm;
		inputWindow->publisherBox_start(publishersList);

		if (switcher == false)
		{
			surname = dbOutput->Rows[index]->Cells[1]->Value->ToString();
			name = dbOutput->Rows[index]->Cells[2]->Value->ToString();
			date = dbOutput->Rows[index]->Cells[3]->Value->ToString();

			inputWindow->dateBox_start(date);
			inputWindow->nameBox_start(name);
			inputWindow->surnameBox_start(surname);
		}

		inputWindow->ShowDialog();

		if (inputWindow->success == true) {
			surname = checkString(inputWindow->input_surname->ToString());
			name = checkString(inputWindow->input_name->ToString());
			date = inputWindow->input_date;
			publisher = inputWindow->input_publisher;

			// �������� �� ������������ ������� � �����
			if (surname == nullptr || name == nullptr) {
				MessageBox::Show("��������� ������������ ��������� ������! � ������� � ����� �� ������ ���� ����!", "������");
				return;
			}

			// ���������� ID ��������
			dbCommand = gcnew OleDbCommand("SELECT ID FROM [Publisher] WHERE(P_Name = @Publishers)", dbConnection);
			dbCommand->Parameters->AddWithValue("Publishers", publisher);
			dbReader = dbCommand->ExecuteReader();
			dbReader->Read(); dbReader->Close(); dbReader = dbCommand->ExecuteReader(); dbReader->Read();
			pubId = dbReader["ID"]->ToString();

			// �������� �� ��������
			dbCommand = gcnew OleDbCommand("SELECT [ID], [Surname], [Name] FROM [Person] WHERE([Surname] = @Surname) AND ([Name] = @Name)", dbConnection);
			dbCommand->Parameters->AddWithValue("Surname", surname);
			dbCommand->Parameters->AddWithValue("Name", name);
			dbReader = dbCommand->ExecuteReader();
			dbReader->Read(); dbReader->Close(); dbReader = dbCommand->ExecuteReader(); dbReader->Read();
			if (dbReader->HasRows == true)
				MessageBox::Show("������ � ������� ��� ������� � �������", "�����������");
			if (dbReader->HasRows == false) {
				dbReader->Close();
				// ������ �� ���������� � Person
				dbCommand = gcnew OleDbCommand("INSERT INTO [Person] ([Surname], [Name], [Date]) VALUES (@Surname, @Name, @Date)", dbConnection);
				dbCommand->Parameters->AddWithValue("Surname", surname);
				dbCommand->Parameters->AddWithValue("Name", name);
				dbCommand->Parameters->AddWithValue("Date", date);
				if (dbCommand->ExecuteNonQuery() != 1) {
					MessageBox::Show("������ ���������� ������� � ������� Person!", "������");
					isvalid = false;
				}
				else {
					dbReader->Close();
					dbCommand = gcnew OleDbCommand("SELECT [ID], [Surname], [Name] FROM [Person] WHERE([Surname] = @Surname) AND ([Name] = @Name)", dbConnection);
					dbCommand->Parameters->AddWithValue("Surname", surname);
					dbCommand->Parameters->AddWithValue("Name", name);
					dbReader = dbCommand->ExecuteReader();
					dbReader->Read(); dbReader->Close(); dbReader = dbCommand->ExecuteReader(); dbReader->Read();
				}
			}
			perId = dbReader["ID"]->ToString();
			dbReader->Close();

			// �������� �� ������� �����
			dbCommand = gcnew OleDbCommand("SELECT [ID_Person], [ID_Publisher] FROM [Connection] WHERE([ID_Person] = @id_person) AND ([ID_Publisher] = @id_pub)", dbConnection);
			dbCommand->Parameters->AddWithValue("id_person", perId);
			dbCommand->Parameters->AddWithValue("id_pub", pubId);
			dbReader = dbCommand->ExecuteReader();
			dbReader->Read(); dbReader->Close(); dbReader = dbCommand->ExecuteReader(); dbReader->Read();
			if (dbReader->HasRows == true)
				MessageBox::Show("�� ����� ��������� ������.", "�����������");
			//// ������ �� ���������� � Connection
			if (dbReader->HasRows == false) {
				dbReader->Close();
				dbCommand = gcnew OleDbCommand("INSERT INTO [Connection] ([ID_Person], [ID_Publisher]) VALUES (@id, @pubID)", dbConnection);
				dbCommand->Parameters->AddWithValue("id", perId);
				dbCommand->Parameters->AddWithValue("pubID", pubId);
				if (dbCommand->ExecuteNonQuery() != 1) {
					MessageBox::Show("������ ���������� ������� Connection!", "������");
					isvalid = false;
				}
			}
			if (isvalid)
				MessageBox::Show("���������� ������ �������!", "���������");
			UpdateBase("");
		}
	}
	else
		MessageBox::Show("���� �� �� ������!", "������");
	return System::Void();
}

// �������� ������ Publisher
System::Void codeproj::mainForm::insertPubButton_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (directory != nullptr) {
		if (publishersGrid->SelectedRows->Count != 1) {
			MessageBox::Show("��� ���������� ������ �������� ���� ������.", "��������");
			return;
		}
		int index = publishersGrid->SelectedRows[0]->Index;

		//  �������� �� �������� ������
		if (publishersGrid->Rows[index]->Cells[1]->Value == nullptr) {
			MessageBox::Show("�� ��� ������ ���� �������!", "������");
			return;
		}
		else {
			Boolean isvalid = true;
			String^ publisher = publishersGrid->Rows[index]->Cells[1]->Value->ToString();
			OleDbCommand^ dbCommand = gcnew OleDbCommand("SELECT ID, P_Name FROM [Publisher] WHERE(P_Name = @Publishers)", dbConnection);
			dbCommand->Parameters->AddWithValue("Publishers", publisher);
			OleDbDataReader^ dbReader = dbCommand->ExecuteReader();
			dbReader->Read(); dbReader->Close(); dbReader = dbCommand->ExecuteReader(); dbReader->Read();
			if (dbReader->HasRows == true)
				MessageBox::Show("������ �� �������� ��� ���� � �������", "�����������");
			if (dbReader->HasRows == false) {
				// ������ �� ���������� � Publisher
				dbCommand = gcnew OleDbCommand("INSERT INTO [Publisher] (P_Name) VALUES (@Publishers)", dbConnection);
				dbCommand->Parameters->AddWithValue("Publishers", publisher);
				if (dbCommand->ExecuteNonQuery() != 1) {
					MessageBox::Show("������ ���������� ������� � ������� ���������!", "������");
					isvalid = false;
				}
				if (isvalid == true)
					MessageBox::Show("���������� ������ �������!", "����������");
				UpdateBase("");
			}
		}
	}
	else
		MessageBox::Show("���� �� �� ������!", "������");


	return System::Void();
}

// �������� ������ Publisher
System::Void codeproj::mainForm::updatePubButton_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (directory != nullptr) {
		if (publishersGrid->SelectedRows->Count != 1) {
			MessageBox::Show("��� ���������� ������ �������� ���� ������.", "��������");
			return;
		}
		int index = publishersGrid->SelectedRows[0]->Index;

		//  �������� �� �������� ������
		if (publishersGrid->Rows[index]->Cells[1]->Value == nullptr ||
			publishersGrid->Rows[index]->Cells[0]->Value == nullptr) {
			MessageBox::Show("�� ��� ������ ���� �������!", "������");
			return;
		}
		else {
			Boolean isvalid = true;
			String^ pubid = publishersGrid->Rows[index]->Cells[0]->Value->ToString();
			String^ publisher = publishersGrid->Rows[index]->Cells[1]->Value->ToString();
			OleDbCommand^ dbCommand = gcnew OleDbCommand("SELECT [P_Name] FROM [Publisher] WHERE([ID] = @pubid)", dbConnection);
			dbCommand->Parameters->AddWithValue("pubid", pubid);
			OleDbDataReader^ dbReader = dbCommand->ExecuteReader();
			dbReader->Read(); dbReader->Close(); dbReader = dbCommand->ExecuteReader(); dbReader->Read();
			if (dbReader->HasRows == false){
				MessageBox::Show("������ � ������ ID � Publisher �� �������!", "������");
			}
			else {
				dbCommand = gcnew OleDbCommand("UPDATE [Publisher] SET [P_Name] = @publisher WHERE ([ID] = @pubid)", dbConnection);
				dbCommand->Parameters->AddWithValue("publisher", publisher);
				dbCommand->Parameters->AddWithValue("pubid", pubid);
				if (dbCommand->ExecuteNonQuery() != 1) {
					MessageBox::Show("������ ���������� ������� � ������� ���������!", "������");
					isvalid = false;
				}
			}
			if (isvalid == true)
				MessageBox::Show("���������� ������ �������!", "����������");
			UpdateBase("");
		}
	}
	else
		MessageBox::Show("���� �� �� ������!", "������");
	return System::Void();
}

// ������� ������ Publisher
System::Void codeproj::mainForm::deletePubButton_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (directory != nullptr) {
		if (publishersGrid->SelectedRows->Count != 1) {
			MessageBox::Show("��� ���������� ������ �������� ���� ������.", "��������");
			return;
		}
		Boolean isvalid = true;
		int index = publishersGrid->SelectedRows[0]->Index;
		String^ pubid = publishersGrid->SelectedRows[0]->Cells[0]->Value->ToString();
		OleDbCommand^ dbCommand = gcnew OleDbCommand("DELETE FROM [Publisher] WHERE (ID = @ID)", dbConnection);
		dbCommand->Parameters->AddWithValue("ID", pubid);
		try {
			dbCommand->ExecuteNonQuery();
		}
		catch (OleDbException^ e) {
			isvalid = false;
		}
		if (isvalid)
			MessageBox::Show("�������� ������ �������!", "���������");
		UpdateBase("");
		
	}
	else
		MessageBox::Show("���� �� �� ������!", "������");
	return System::Void();
}

// ����������
System::Void codeproj::mainForm::saveButton_Click(System::Object^ sender, System::EventArgs^ e)
{
	UpdateBase("");

	return System::Void();
}

// �������� �����
System::String^ codeproj::mainForm::checkString(String^ checkingString)
{
	int len = checkingString->ToString()->Length;
	String^ upperCheckingString = checkingString->ToUpper();
	String^ lowerCheckingString = checkingString->ToLower();
	if (lowerCheckingString[0] == checkingString[0]) {
		checkingString = upperCheckingString[0] + lowerCheckingString->Substring(1, len - 1);
		for (int i = 0; i < len; i++)
		{
			if (checkingString[i] >= '0' && checkingString[i] <= '9') {
				checkingString = nullptr;
				break;
			}
		}
	}
	return checkingString;
}

// �������� ����������� � ��
System::Void codeproj::mainForm::mainFormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e)
{
	if (dbConnection != nullptr) {
		try {
			dbConnection->Close(); MessageBox::Show("�� ���������", "�� �����!");
		}
		catch (OleDbException^ e)
		{
			true;
		}
	}
	return System::Void();
}