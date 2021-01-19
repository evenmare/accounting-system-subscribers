#pragma once

namespace codeproj {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Data::OleDb;

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

	protected:

	private: System::Windows::Forms::Button^ openButton;
	private: System::Windows::Forms::Button^ searchButton;
	private: System::Windows::Forms::Button^ dateSearchButton;
	private: System::Windows::Forms::Button^ findmaxButton;
	private: System::Windows::Forms::Button^ deleteButton;
	protected:





	private: System::Windows::Forms::Button^ updateButton;

	private: System::Windows::Forms::Button^ insertButton;

	private: System::Windows::Forms::OpenFileDialog^ openFileDialog1;






	private: System::Windows::Forms::Button^ saveButton;






	private: System::Windows::Forms::GroupBox^ groupBox1;






	private: System::Windows::Forms::Button^ deletePubButton;
	private: System::Windows::Forms::Button^ updatePubButton;
	private: System::Windows::Forms::Button^ insertPubButton;
	private: System::Windows::Forms::DataGridView^ publishersGrid;






	private: System::Windows::Forms::DataGridViewTextBoxColumn^ pub_ID;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ pub_Name;
	private: System::Windows::Forms::DataGridView^ dbOutput;






	private: System::Windows::Forms::ContextMenuStrip^ contextMenuStrip1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ id;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Surname;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Name;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Date;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ pubID;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Publishers;






























	private: System::ComponentModel::IContainer^ components;


























	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->openButton = (gcnew System::Windows::Forms::Button());
			this->searchButton = (gcnew System::Windows::Forms::Button());
			this->dateSearchButton = (gcnew System::Windows::Forms::Button());
			this->findmaxButton = (gcnew System::Windows::Forms::Button());
			this->deleteButton = (gcnew System::Windows::Forms::Button());
			this->updateButton = (gcnew System::Windows::Forms::Button());
			this->insertButton = (gcnew System::Windows::Forms::Button());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->saveButton = (gcnew System::Windows::Forms::Button());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->deletePubButton = (gcnew System::Windows::Forms::Button());
			this->updatePubButton = (gcnew System::Windows::Forms::Button());
			this->insertPubButton = (gcnew System::Windows::Forms::Button());
			this->publishersGrid = (gcnew System::Windows::Forms::DataGridView());
			this->pub_ID = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->pub_Name = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dbOutput = (gcnew System::Windows::Forms::DataGridView());
			this->id = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Surname = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Name = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Date = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->pubID = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Publishers = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->contextMenuStrip1 = (gcnew System::Windows::Forms::ContextMenuStrip(this->components));
			this->groupBox1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->publishersGrid))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dbOutput))->BeginInit();
			this->SuspendLayout();
			// 
			// openButton
			// 
			this->openButton->Location = System::Drawing::Point(12, 25);
			this->openButton->Name = L"openButton";
			this->openButton->Size = System::Drawing::Size(155, 45);
			this->openButton->TabIndex = 1;
			this->openButton->Text = L"Открыть";
			this->openButton->UseVisualStyleBackColor = true;
			this->openButton->Click += gcnew System::EventHandler(this, &mainForm::openButton_Click);
			// 
			// searchButton
			// 
			this->searchButton->Location = System::Drawing::Point(11, 111);
			this->searchButton->Name = L"searchButton";
			this->searchButton->Size = System::Drawing::Size(155, 45);
			this->searchButton->TabIndex = 2;
			this->searchButton->Text = L"Поиск";
			this->searchButton->UseVisualStyleBackColor = true;
			this->searchButton->Click += gcnew System::EventHandler(this, &mainForm::searchButton_Click);
			// 
			// dateSearchButton
			// 
			this->dateSearchButton->Location = System::Drawing::Point(11, 162);
			this->dateSearchButton->Name = L"dateSearchButton";
			this->dateSearchButton->Size = System::Drawing::Size(155, 45);
			this->dateSearchButton->TabIndex = 3;
			this->dateSearchButton->Text = L"Поиск по дате";
			this->dateSearchButton->UseVisualStyleBackColor = true;
			this->dateSearchButton->Click += gcnew System::EventHandler(this, &mainForm::dateSearchButton_Click);
			// 
			// findmaxButton
			// 
			this->findmaxButton->Location = System::Drawing::Point(11, 213);
			this->findmaxButton->Name = L"findmaxButton";
			this->findmaxButton->Size = System::Drawing::Size(155, 45);
			this->findmaxButton->TabIndex = 4;
			this->findmaxButton->Text = L"Поиск \"максимального\" подписчика";
			this->findmaxButton->UseVisualStyleBackColor = true;
			this->findmaxButton->Click += gcnew System::EventHandler(this, &mainForm::findmaxButton_Click);
			// 
			// deleteButton
			// 
			this->deleteButton->Location = System::Drawing::Point(12, 406);
			this->deleteButton->Name = L"deleteButton";
			this->deleteButton->Size = System::Drawing::Size(155, 45);
			this->deleteButton->TabIndex = 5;
			this->deleteButton->Text = L"Удалить запись";
			this->deleteButton->UseVisualStyleBackColor = true;
			this->deleteButton->Click += gcnew System::EventHandler(this, &mainForm::deleteButton_Click);
			// 
			// updateButton
			// 
			this->updateButton->Location = System::Drawing::Point(12, 355);
			this->updateButton->Name = L"updateButton";
			this->updateButton->Size = System::Drawing::Size(155, 45);
			this->updateButton->TabIndex = 6;
			this->updateButton->Text = L"Обновить запись";
			this->updateButton->UseVisualStyleBackColor = true;
			this->updateButton->Click += gcnew System::EventHandler(this, &mainForm::updateButton_Click);
			// 
			// insertButton
			// 
			this->insertButton->Location = System::Drawing::Point(12, 304);
			this->insertButton->Name = L"insertButton";
			this->insertButton->Size = System::Drawing::Size(154, 45);
			this->insertButton->TabIndex = 7;
			this->insertButton->Text = L"Добавить запись";
			this->insertButton->UseVisualStyleBackColor = true;
			this->insertButton->Click += gcnew System::EventHandler(this, &mainForm::insertButton_Click);
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
			// groupBox1
			// 
			this->groupBox1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Right));
			this->groupBox1->Controls->Add(this->deletePubButton);
			this->groupBox1->Controls->Add(this->updatePubButton);
			this->groupBox1->Controls->Add(this->insertPubButton);
			this->groupBox1->Controls->Add(this->publishersGrid);
			this->groupBox1->Location = System::Drawing::Point(957, 25);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(245, 505);
			this->groupBox1->TabIndex = 10;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Издательства";
			this->groupBox1->Enter += gcnew System::EventHandler(this, &mainForm::groupBox1_Enter);
			// 
			// deletePubButton
			// 
			this->deletePubButton->Location = System::Drawing::Point(47, 126);
			this->deletePubButton->Name = L"deletePubButton";
			this->deletePubButton->Size = System::Drawing::Size(156, 45);
			this->deletePubButton->TabIndex = 14;
			this->deletePubButton->Text = L"Удалить";
			this->deletePubButton->UseVisualStyleBackColor = true;
			this->deletePubButton->Click += gcnew System::EventHandler(this, &mainForm::deletePubButton_Click);
			// 
			// updatePubButton
			// 
			this->updatePubButton->Location = System::Drawing::Point(47, 75);
			this->updatePubButton->Name = L"updatePubButton";
			this->updatePubButton->Size = System::Drawing::Size(156, 45);
			this->updatePubButton->TabIndex = 13;
			this->updatePubButton->Text = L"Обновить";
			this->updatePubButton->UseVisualStyleBackColor = true;
			this->updatePubButton->Click += gcnew System::EventHandler(this, &mainForm::updatePubButton_Click);
			// 
			// insertPubButton
			// 
			this->insertPubButton->Location = System::Drawing::Point(47, 24);
			this->insertPubButton->Name = L"insertPubButton";
			this->insertPubButton->Size = System::Drawing::Size(156, 45);
			this->insertPubButton->TabIndex = 12;
			this->insertPubButton->Text = L"Добавить";
			this->insertPubButton->UseVisualStyleBackColor = true;
			this->insertPubButton->Click += gcnew System::EventHandler(this, &mainForm::insertPubButton_Click);
			// 
			// publishersGrid
			// 
			this->publishersGrid->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Right));
			this->publishersGrid->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->publishersGrid->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(2) {
				this->pub_ID,
					this->pub_Name
			});
			this->publishersGrid->Location = System::Drawing::Point(6, 188);
			this->publishersGrid->Name = L"publishersGrid";
			this->publishersGrid->Size = System::Drawing::Size(234, 311);
			this->publishersGrid->TabIndex = 11;
			this->publishersGrid->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &mainForm::publishersGrid_CellContentClick);
			// 
			// pub_ID
			// 
			this->pub_ID->HeaderText = L"ID";
			this->pub_ID->Name = L"pub_ID";
			this->pub_ID->Width = 30;
			// 
			// pub_Name
			// 
			this->pub_Name->HeaderText = L"Наименование";
			this->pub_Name->Name = L"pub_Name";
			this->pub_Name->Width = 161;
			// 
			// dbOutput
			// 
			this->dbOutput->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->dbOutput->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dbOutput->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(6) {
				this->id, this->Surname,
					this->Name, this->Date, this->pubID, this->Publishers
			});
			this->dbOutput->Location = System::Drawing::Point(190, 25);
			this->dbOutput->Name = L"dbOutput";
			this->dbOutput->RowHeadersWidth = 51;
			this->dbOutput->Size = System::Drawing::Size(745, 505);
			this->dbOutput->TabIndex = 0;
			this->dbOutput->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &mainForm::dbOutput_CellContentClick);
			// 
			// id
			// 
			this->id->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::None;
			this->id->FillWeight = 30;
			this->id->HeaderText = L"ID";
			this->id->MinimumWidth = 6;
			this->id->Name = L"id";
			this->id->ReadOnly = true;
			this->id->Width = 30;
			// 
			// Surname
			// 
			this->Surname->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
			this->Surname->HeaderText = L"Фамилия";
			this->Surname->MinimumWidth = 6;
			this->Surname->Name = L"Surname";
			this->Surname->ReadOnly = true;
			// 
			// Name
			// 
			this->Name->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
			this->Name->HeaderText = L"Имя";
			this->Name->MinimumWidth = 6;
			this->Name->Name = L"Name";
			this->Name->ReadOnly = true;
			// 
			// Date
			// 
			this->Date->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
			this->Date->FillWeight = 50;
			this->Date->HeaderText = L"Дата";
			this->Date->MinimumWidth = 6;
			this->Date->Name = L"Date";
			this->Date->ReadOnly = true;
			// 
			// pubID
			// 
			this->pubID->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::None;
			this->pubID->HeaderText = L"ID изд.";
			this->pubID->MinimumWidth = 6;
			this->pubID->Name = L"pubID";
			this->pubID->ReadOnly = true;
			this->pubID->Width = 30;
			// 
			// Publishers
			// 
			this->Publishers->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
			this->Publishers->HeaderText = L"Издательство";
			this->Publishers->MinimumWidth = 6;
			this->Publishers->Name = L"Publishers";
			this->Publishers->ReadOnly = true;
			// 
			// contextMenuStrip1
			// 
			this->contextMenuStrip1->Name = L"contextMenuStrip1";
			this->contextMenuStrip1->Size = System::Drawing::Size(61, 4);
			// 
			// mainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(96, 96);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Dpi;
			this->ClientSize = System::Drawing::Size(1215, 554);
			this->Controls->Add(this->dbOutput);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->findmaxButton);
			this->Controls->Add(this->saveButton);
			this->Controls->Add(this->insertButton);
			this->Controls->Add(this->updateButton);
			this->Controls->Add(this->deleteButton);
			this->Controls->Add(this->dateSearchButton);
			this->Controls->Add(this->searchButton);
			this->Controls->Add(this->openButton);
			this->Text = L"Наши подписчики";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &mainForm::mainFormClosing);
			this->Load += gcnew System::EventHandler(this, &mainForm::mainForm_Load);
			this->groupBox1->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->publishersGrid))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dbOutput))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void openButton_Click(System::Object^ sender, System::EventArgs^ e); // Open
	private: System::Void searchButton_Click(System::Object^ sender, System::EventArgs^ e); // Search
	private: System::Void dateSearchButton_Click(System::Object^ sender, System::EventArgs^ e); // Date Search
	private: System::Void findmaxButton_Click(System::Object^ sender, System::EventArgs^ e); // Max
	private: System::Void deleteButton_Click(System::Object^ sender, System::EventArgs^ e); // Delete
	private: System::Void updateButton_Click(System::Object^ sender, System::EventArgs^ e); // Update
	private: System::Void insertButton_Click(System::Object^ sender, System::EventArgs^ e); // Insert
	private: System::Void dbOutput_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e){ // Grid
		return System::Void();
	}
	private: System::Void openFileDialog1_FileOk(System::Object^ sender, System::ComponentModel::CancelEventArgs^ e) { // Open File Component 
		return System::Void();
	}
	private: System::Void saveButton_Click(System::Object^ sender, System::EventArgs^ e); // Save
	public: String^ connectionString = "provider = Microsoft.Jet.OLEDB.4.0; Data Source=";
	public: String^ fileName;
	public: String^ directory;
	public: OleDbConnection^ dbConnection;
	public: System::Void UpdateBase(String^ query);
	public: System::Void OutputPublisherBase(OleDbDataReader^ databaseReader);
	public: System::Void OutputBase(OleDbDataReader^ databaseReader);
	private: System::Void mainForm_Load(System::Object^ sender, System::EventArgs^ e) {
}
	private: System::Void insertPubButton_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void updatePubButton_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void deletePubButton_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void publishersGrid_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
		return System::Void();
	}
		   private: System::Void mainFormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e);
	public: System::String^ checkString(String^ checkingString);
	private: System::Void groupBox1_Enter(System::Object^ sender, System::EventArgs^ e) {
	}
};
}
