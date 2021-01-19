#include "mainForm.h"
#include "searchForm.h"

// Системное
using namespace System;
using namespace System::Windows::Forms;
using namespace System::Data::OleDb; 

[STAThread]
int main(array<String^>^ arg) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	codeproj::mainForm form;
	Application::Run(% form);
}
System::Void codeproj::mainForm::UpdateBase(System::EventArgs^ e, String^ query)
{
	if (fileName != nullptr)
	{
		if (query == "")
			query = "SELECT Person.*, [Connection].ID_Publisher, Publisher.P_Name FROM(([Connection] INNER JOIN Person ON[Connection].ID_Person = Person.ID) INNER JOIN Publisher ON[Connection].ID_Publisher = Publisher.ID) ORDER BY[Connection].ID_Publisher";

		dataGridView1->Rows->Clear();

		// соединяемся с БД
		OleDbConnection^ dbConnection = gcnew OleDbConnection(directory);
		dbConnection->Open();

		// выполняем запрос
		OleDbCommand^ dbCommand = gcnew OleDbCommand(query, dbConnection);
		OleDbDataReader^ dbReader = dbCommand->ExecuteReader();
		if (dbReader->HasRows == false) // проверка на существование таблиц в БД
			MessageBox::Show("Ошибка!");
		else {
			dbReader->Close();
			dbReader = dbCommand->ExecuteReader();
			while (dbReader->Read()) {
				// выводим в dataGrid наш запрос
				dataGridView1->Rows->Add(dbReader["ID"], dbReader["Surname"], dbReader["Name"], dbReader["Date"], dbReader["ID_Publisher"], dbReader["P_Name"]);
			}
		}
		dbReader->Close();
		dbConnection->Close();
	}
	else
		MessageBox::Show("Файл БД не выбран", "Ошибка");

	return System::Void();
}

// Открытие файла
System::Void codeproj::mainForm::button1_Click(System::Object^ sender, System::EventArgs^ e)
{
	// поднимаем Open File
	OpenFileDialog^ openDlg = gcnew OpenFileDialog();
	openDlg->InitialDirectory = "C:\Users\fuzzyfaLL\OneDrive\Desktop\Курсач_КП"; // подумать над путем
	openDlg->Filter = "Database File (*.mdb)|*.mdb|All files (*.*)|*.*";
	openDlg->FilterIndex = 1;
	openDlg->RestoreDirectory = true;

	if (openDlg->ShowDialog() == System::Windows::Forms::DialogResult::OK)
	{
		fileName = openDlg->FileName;
		directory = connectionString + fileName;

		UpdateBase(e, "");

		return System::Void();
	}
}

// Поиск [searchForm]
System::Void codeproj::mainForm::button2_Click(System::Object^ sender, System::EventArgs^ e)
{
	searchForm^ searchWindow = gcnew searchForm;
	searchWindow->FormClosed += gcnew FormClosedEventHandler(searchWindow_FormClosed);

	searchWindow->Show();
	
	return System::Void();
}

System::Void codeproj::mainForm::searchWindow_FormClosed(Object^ sender, FormClosedEventArgs^ e)
{
	return System::Void();
}

// Поиск по дате [dateForm]
System::Void codeproj::mainForm::button3_Click(System::Object^ sender, System::EventArgs^ e)
{
	return System::Void();
}

// Максимальное число подписок
System::Void codeproj::mainForm::button4_Click(System::Object^ sender, System::EventArgs^ e)
{
	OleDbConnection^ dbConnection = gcnew OleDbConnection(directory);
	dbConnection->Open();
	OleDbCommand^ dbCommand = gcnew OleDbCommand("SELECT TOP 1 [ID_Person], COUNT([ID_Person]) AS Clown FROM[Connection] GROUP BY [ID_Person] ORDER BY COUNT(ID_Person) DESC", dbConnection);
	OleDbDataReader^ dbReader = dbCommand->ExecuteReader();
	dbReader->Read();
	dbReader->Close();
	dbReader = dbCommand->ExecuteReader();
	int counter = 0;
	OleDbCommand^ bbCommand;
	OleDbDataReader^ bbReader;
	String^ id_number;

	dataGridView1->Rows->Clear();
	while (dbReader->Read())
	{
		// MessageBox::Show(dbReader["ID_Person"]->ToString());
		bbCommand = gcnew OleDbCommand("SELECT Person.*, [Connection].ID_Publisher, Publisher.P_Name FROM(([Connection] INNER JOIN Person ON[Connection].ID_Person = Person.ID) INNER JOIN Publisher ON[Connection].ID_Publisher = Publisher.ID) WHERE ([Person].ID = @number)", dbConnection);
		id_number = dbReader["ID_Person"]->ToString();
		bbCommand->Parameters->AddWithValue("number", id_number);
		bbReader = bbCommand->ExecuteReader();
		bbReader->Read(); bbReader->Close(); bbReader = bbCommand->ExecuteReader();
		while (bbReader->Read())
			dataGridView1->Rows->Add(bbReader["ID"], bbReader["Surname"], bbReader["Name"], bbReader["Date"], bbReader["ID_Publisher"], bbReader["P_Name"]);
	}
	return System::Void();
}

// Удалить запись
System::Void codeproj::mainForm::button5_Click(System::Object^ sender, System::EventArgs^ e)
{
	return System::Void();
}

// Обновить запись
System::Void codeproj::mainForm::button6_Click(System::Object^ sender, System::EventArgs^ e)
{
	return System::Void();
}

// Вставить запись
System::Void codeproj::mainForm::button7_Click(System::Object^ sender, System::EventArgs^ e)
{
	// Проверка на выбор строки
	if (dataGridView1->SelectedRows->Count != 1) {
		MessageBox::Show("Для добавления записи выберите одну строку.", "Внимание");
		return;
	}
	int index = dataGridView1->SelectedRows[0]->Index;

	//  Проверка на введённые данные
	if (dataGridView1->Rows[index]->Cells[1]->Value == nullptr ||
		dataGridView1->Rows[index]->Cells[2]->Value == nullptr ||
		dataGridView1->Rows[index]->Cells[3]->Value == nullptr ||
		dataGridView1->Rows[index]->Cells[4]->Value == nullptr) {
		MessageBox::Show("Не все данные были введены!", "Ошибка");
		return;
	}
	else
	{
		bool^ isvalid = true;
		String^ perid = "";
		String^ surname = dataGridView1->Rows[index]->Cells[1]->Value->ToString();
		String^ name = dataGridView1->Rows[index]->Cells[2]->Value->ToString();
		String^ date = dataGridView1->Rows[index]->Cells[3]->Value->ToString();
		String^ pubid = "";
		String^ publisher = "";

		if (dataGridView1->Rows[index]->Cells[4]->Value != nullptr)
			pubid = dataGridView1->Rows[index]->Cells[4]->Value->ToString();
		if (dataGridView1->Rows[index]->Cells[5]->Value != nullptr)
			publisher = dataGridView1->Rows[index]->Cells[5]->Value->ToString();

		// Соединяемся с базой
		OleDbConnection^ dbConnection = gcnew OleDbConnection(directory);
		dbConnection->Open();

		// Проверка на наличие данных о человеке в Person
		OleDbCommand^ dbCommand = gcnew OleDbCommand("SELECT [ID], [Surname], [Name] FROM [Person] WHERE([Surname] = @Surname) AND ([Name] = @Name)", dbConnection);
		dbCommand->Parameters->AddWithValue("Surname", surname);
		dbCommand->Parameters->AddWithValue("Name", name);
		OleDbDataReader^ dbReader = dbCommand->ExecuteReader();
		dbReader->Read(); dbReader->Close(); dbReader = dbCommand->ExecuteReader(); dbReader->Read();
		if (dbReader->HasRows == true)
			MessageBox::Show("Данные о клиенте уже имеются в таблице", "Уведомление");
		if (dbReader->HasRows == false) {
			dbReader->Close();
			// Запрос на добавление в Person
			dbCommand = gcnew OleDbCommand("INSERT INTO [Person] ([Surname], [Name], [Date]) VALUES (@Surname, @Name, @Date)", dbConnection);
			dbCommand->Parameters->AddWithValue("Surname", surname);
			dbCommand->Parameters->AddWithValue("Name", name);
			dbCommand->Parameters->AddWithValue("Date", date);
			if (dbCommand->ExecuteNonQuery() != 1) {
				MessageBox::Show("Ошибка выполнения запроса в таблице Person!", "Ошибка");
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
		perid = dbReader["ID"]->ToString();

		dbReader->Close();

		// Проверка на нового издателя
		if (dataGridView1->Rows[index]->Cells[5]->Value != nullptr)
		{
			dbCommand = gcnew OleDbCommand("SELECT ID, P_Name FROM [Publisher] WHERE(P_Name = @Publishers)", dbConnection);
			dbCommand->Parameters->AddWithValue("Publishers", publisher);
			dbReader = dbCommand->ExecuteReader();
			dbReader->Read(); dbReader->Close(); dbReader = dbCommand->ExecuteReader(); dbReader->Read();
			if (dbReader->HasRows == true)
				MessageBox::Show("Данные об издателе уже есть в таблице", "Уведомление");
			if (dbReader->HasRows == false) {
				// Запрос на добавление в Publisher
				dbCommand = gcnew OleDbCommand("INSERT INTO [Publisher] (P_Name) VALUES (@Publishers)", dbConnection);
				dbCommand->Parameters->AddWithValue("Publishers", publisher);
				if (dbCommand->ExecuteNonQuery() != 1) {
					MessageBox::Show("Ошибка выполнения запроса в таблице Publishers!", "Ошибка");
					isvalid = false;
				}
				else {
					dbReader->Close();
					dbCommand = gcnew OleDbCommand("SELECT ID, P_Name FROM [Publisher] WHERE(P_Name = @Publishers)", dbConnection);
					dbCommand->Parameters->AddWithValue("Publishers", publisher);
					dbReader = dbCommand->ExecuteReader();
					dbReader->Read(); dbReader->Close(); dbReader = dbCommand->ExecuteReader(); dbReader->Read();
				}
			}
			pubid = dbReader["ID"]->ToString();
			dbReader->Close();
		}


		// Проверка на наличие связи
		dbCommand = gcnew OleDbCommand("SELECT [ID_Person], [ID_Publisher] FROM [Connection] WHERE([ID_Person] = @id_person) AND ([ID_Publisher] = @id_pub)", dbConnection);
		dbCommand->Parameters->AddWithValue("id_person", perid);
		dbCommand->Parameters->AddWithValue("id_pub", pubid);
		dbReader = dbCommand->ExecuteReader();
		dbReader->Read(); dbReader->Close(); dbReader = dbCommand->ExecuteReader(); dbReader->Read();
		if (dbReader->HasRows == true)
			MessageBox::Show("Вы ввели повторную запись! Изменения не будут сохренены", "Уведомление");
		//// Запрос на добавление в Connection
		if (dbReader->HasRows == false) {
			dbReader->Close();
			dbCommand = gcnew OleDbCommand("INSERT INTO [Connection] ([ID_Person], [ID_Publisher]) VALUES (@id, @pubID)", dbConnection);
			// MessageBox::Show(perid, pubid);
			dbCommand->Parameters->AddWithValue("id", perid);
			dbCommand->Parameters->AddWithValue("pubID", pubid);
			if (dbCommand->ExecuteNonQuery() != 1) {
				MessageBox::Show("Ошибка выполнения запроса Connection!", "Ошибка");
				isvalid = false;
			}
		}
		if (isvalid)
			MessageBox::Show("Добавление прошло успешно!", "Завершено");
		dbConnection->Close();
		UpdateBase(e, "");
	}
	return System::Void();
}

// Обновление
System::Void codeproj::mainForm::saveButton_Click(System::Object^ sender, System::EventArgs^ e)
{
	UpdateBase(e, "");

	return System::Void();
}

