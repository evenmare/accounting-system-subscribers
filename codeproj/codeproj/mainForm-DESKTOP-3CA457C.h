#pragma once

namespace codeproj {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для mainForm
	/// </summary>
	public ref class mainForm : public System::Windows::Forms::Form
	{
	public:
		mainForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~mainForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::DataGridView^ dataGridView1;
	private: System::Windows::Forms::Button^ openButton;
	private: System::Windows::Forms::Button^ searchButton;
	protected:


	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::Button^ button5;
	private: System::Windows::Forms::Button^ button6;
	private: System::Windows::Forms::Button^ button7;
	private: System::Windows::Forms::OpenFileDialog^ openFileDialog1;






	private: System::Windows::Forms::Button^ saveButton;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ id;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Surname;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Name;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Date;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ pubID;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Publishers;


















	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->id = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Surname = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Name = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Date = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->pubID = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Publishers = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->openButton = (gcnew System::Windows::Forms::Button());
			this->searchButton = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->saveButton = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// dataGridView1
			// 
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(6) {
				this->id, this->Surname,
					this->Name, this->Date, this->pubID, this->Publishers
			});
			this->dataGridView1->Location = System::Drawing::Point(186, 25);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->Size = System::Drawing::Size(880, 505);
			this->dataGridView1->TabIndex = 0;
			this->dataGridView1->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &mainForm::dataGridView1_CellContentClick);
			// 
			// id
			// 
			this->id->HeaderText = L"ID";
			this->id->Name = L"id";
			this->id->Width = 50;
			// 
			// Surname
			// 
			this->Surname->HeaderText = L"Фамилия";
			this->Surname->Name = L"Surname";
			this->Surname->Width = 150;
			// 
			// Name
			// 
			this->Name->HeaderText = L"Имя";
			this->Name->Name = L"Name";
			this->Name->Width = 150;
			// 
			// Date
			// 
			this->Date->HeaderText = L"Дата";
			this->Date->Name = L"Date";
			// 
			// pubID
			// 
			this->pubID->HeaderText = L"ID изд.";
			this->pubID->Name = L"pubID";
			this->pubID->Width = 50;
			// 
			// Publishers
			// 
			this->Publishers->HeaderText = L"Издательство";
			this->Publishers->Name = L"Publishers";
			this->Publishers->Width = 335;
			// 
			// openButton
			// 
			this->openButton->Location = System::Drawing::Point(12, 25);
			this->openButton->Name = L"openButton";
			this->openButton->Size = System::Drawing::Size(155, 45);
			this->openButton->TabIndex = 1;
			this->openButton->Text = L"Открыть";
			this->openButton->UseVisualStyleBackColor = true;
			this->openButton->Click += gcnew System::EventHandler(this, &mainForm::button1_Click);
			// 
			// searchButton
			// 
			this->searchButton->Location = System::Drawing::Point(12, 76);
			this->searchButton->Name = L"searchButton";
			this->searchButton->Size = System::Drawing::Size(155, 45);
			this->searchButton->TabIndex = 2;
			this->searchButton->Text = L"Поиск";
			this->searchButton->UseVisualStyleBackColor = true;
			this->searchButton->Click += gcnew System::EventHandler(this, &mainForm::button2_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(12, 127);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(155, 45);
			this->button3->TabIndex = 3;
			this->button3->Text = L"Поиск по дате";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &mainForm::button3_Click);
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(12, 178);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(155, 45);
			this->button4->TabIndex = 4;
			this->button4->Text = L"Максимальное число";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &mainForm::button4_Click);
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(12, 371);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(155, 45);
			this->button5->TabIndex = 5;
			this->button5->Text = L"Удалить запись";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &mainForm::button5_Click);
			// 
			// button6
			// 
			this->button6->Location = System::Drawing::Point(12, 320);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(155, 45);
			this->button6->TabIndex = 6;
			this->button6->Text = L"Обновить запись";
			this->button6->UseVisualStyleBackColor = true;
			this->button6->Click += gcnew System::EventHandler(this, &mainForm::button6_Click);
			// 
			// button7
			// 
			this->button7->Location = System::Drawing::Point(12, 269);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(154, 45);
			this->button7->TabIndex = 7;
			this->button7->Text = L"Вставить запись";
			this->button7->UseVisualStyleBackColor = true;
			this->button7->Click += gcnew System::EventHandler(this, &mainForm::button7_Click);
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			this->openFileDialog1->FileOk += gcnew System::ComponentModel::CancelEventHandler(this, &mainForm::openFileDialog1_FileOk);
			// 
			// saveButton
			// 
			this->saveButton->Location = System::Drawing::Point(12, 485);
			this->saveButton->Name = L"saveButton";
			this->saveButton->Size = System::Drawing::Size(155, 45);
			this->saveButton->TabIndex = 9;
			this->saveButton->Text = L"Обновить";
			this->saveButton->UseVisualStyleBackColor = true;
			this->saveButton->Click += gcnew System::EventHandler(this, &mainForm::saveButton_Click);
			// 
			// mainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1078, 554);
			this->Controls->Add(this->saveButton);
			this->Controls->Add(this->button7);
			this->Controls->Add(this->button6);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->searchButton);
			this->Controls->Add(this->openButton);
			this->Controls->Add(this->dataGridView1);
			this->Load += gcnew System::EventHandler(this, &mainForm::mainForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e); // Open
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e); // Search
	private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e); // Date Search
	private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e); // Max
	private: System::Void button5_Click(System::Object^ sender, System::EventArgs^ e); // Delete
	private: System::Void button6_Click(System::Object^ sender, System::EventArgs^ e); // Update
	private: System::Void button7_Click(System::Object^ sender, System::EventArgs^ e); // Insert
	private: System::Void dataGridView1_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e){ // Grid
		return System::Void();
	}
	private: System::Void openFileDialog1_FileOk(System::Object^ sender, System::ComponentModel::CancelEventArgs^ e) { // Open File Component 
		return System::Void();
	}
	private: System::Void saveButton_Click(System::Object^ sender, System::EventArgs^ e); // Save
	public: String^ connectionString = "provider = Microsoft.Jet.OLEDB.4.0; Data Source=";
	public: String^ fileName;
	public: String^ directory;
	public: System::Void UpdateBase(System::EventArgs^ e, String^ query);
	private: System::Void searchWindow_FormClosed(System::Object^ sender, System::Windows::Forms::FormClosedEventArgs^ e);
	private: System::Void mainForm_Load(System::Object^ sender, System::EventArgs^ e) {
}
};
}
