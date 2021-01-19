#pragma once

namespace codeproj {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// —водка дл€ openForm
	/// </summary>
	public ref class searchForm : public System::Windows::Forms::Form
	{
	public:
		searchForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~searchForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^ SurnameBox;
	private: System::Windows::Forms::TextBox^ nameBox;
	private: System::Windows::Forms::DateTimePicker^ dateBox;
	private: System::Windows::Forms::Button^ successButton;
	private: System::ComponentModel::BackgroundWorker^ backgroundWorker1;
	private: System::Windows::Forms::CheckBox^ dateCheckBox;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;

	protected:

	protected:


	private:
		/// <summary>
		/// ќб€зательна€ переменна€ конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// “ребуемый метод дл€ поддержки конструктора Ч не измен€йте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->SurnameBox = (gcnew System::Windows::Forms::TextBox());
			this->nameBox = (gcnew System::Windows::Forms::TextBox());
			this->dateBox = (gcnew System::Windows::Forms::DateTimePicker());
			this->successButton = (gcnew System::Windows::Forms::Button());
			this->backgroundWorker1 = (gcnew System::ComponentModel::BackgroundWorker());
			this->dateCheckBox = (gcnew System::Windows::Forms::CheckBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// SurnameBox
			// 
			this->SurnameBox->Location = System::Drawing::Point(9, 36);
			this->SurnameBox->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->SurnameBox->Name = L"SurnameBox";
			this->SurnameBox->Size = System::Drawing::Size(138, 20);
			this->SurnameBox->TabIndex = 0;
			this->SurnameBox->Text = L"¬ведите фамилию";
			this->SurnameBox->TextChanged += gcnew System::EventHandler(this, &searchForm::surnameBox_TextChanged);
			// 
			// nameBox
			// 
			this->nameBox->Location = System::Drawing::Point(9, 78);
			this->nameBox->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->nameBox->Name = L"nameBox";
			this->nameBox->Size = System::Drawing::Size(138, 20);
			this->nameBox->TabIndex = 1;
			this->nameBox->Text = L"¬ведите им€";
			this->nameBox->TextChanged += gcnew System::EventHandler(this, &searchForm::nameBox_TextChanged);
			// 
			// dateBox
			// 
			this->dateBox->Location = System::Drawing::Point(181, 41);
			this->dateBox->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->dateBox->Name = L"dateBox";
			this->dateBox->Size = System::Drawing::Size(138, 20);
			this->dateBox->TabIndex = 2;
			this->dateBox->ValueChanged += gcnew System::EventHandler(this, &searchForm::dateBox_ValueChanged);
			// 
			// successButton
			// 
			this->successButton->Location = System::Drawing::Point(181, 73);
			this->successButton->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->successButton->Name = L"successButton";
			this->successButton->Size = System::Drawing::Size(138, 28);
			this->successButton->TabIndex = 3;
			this->successButton->Text = L"OK";
			this->successButton->UseVisualStyleBackColor = true;
			this->successButton->Click += gcnew System::EventHandler(this, &searchForm::successButton_Click);
			// 
			// dateCheckBox
			// 
			this->dateCheckBox->AutoSize = true;
			this->dateCheckBox->Location = System::Drawing::Point(181, 21);
			this->dateCheckBox->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->dateCheckBox->Name = L"dateCheckBox";
			this->dateCheckBox->Size = System::Drawing::Size(93, 17);
			this->dateCheckBox->TabIndex = 4;
			this->dateCheckBox->Text = L"¬водить дату";
			this->dateCheckBox->UseVisualStyleBackColor = true;
			this->dateCheckBox->CheckedChanged += gcnew System::EventHandler(this, &searchForm::dateCheckBox_CheckedChanged);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(6, 21);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(56, 13);
			this->label1->TabIndex = 6;
			this->label1->Text = L"‘амили€";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(8, 63);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(29, 13);
			this->label2->TabIndex = 7;
			this->label2->Text = L"»м€";
			// 
			// searchForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(330, 118);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->dateCheckBox);
			this->Controls->Add(this->successButton);
			this->Controls->Add(this->dateBox);
			this->Controls->Add(this->nameBox);
			this->Controls->Add(this->SurnameBox);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->MaximizeBox = false;
			this->Name = L"searchForm";
			this->Text = L"¬ведите данные дл€ поиска";
			this->Load += gcnew System::EventHandler(this, &searchForm::searchFormForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void searchFormForm_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void surnameBox_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	};
	private: System::Void nameBox_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	};
	private: System::Void dateBox_ValueChanged(System::Object^ sender, System::EventArgs^ e) {
	};
	private: System::Void successButton_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void dateCheckBox_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	};
	public: String^ input_surname;
	public: String^ input_name;
	public: String^ input_date;
	public: Boolean success = false;
	private: System::Void searchForm_FormClosing(System::Object^ sender, FormClosingEventArgs^ e) {
		MessageBox::Show("Closed");
	}

};
}
