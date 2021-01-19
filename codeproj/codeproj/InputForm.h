#pragma once

namespace codeproj {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для MaxForm
	/// </summary>
	public ref class InputForm : public System::Windows::Forms::Form
	{
	public:
		InputForm(void)
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
		~InputForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^ surnameBox;
	private: System::Windows::Forms::TextBox^ nameBox;
	private: System::Windows::Forms::DateTimePicker^ dateBox;
	private: System::Windows::Forms::ComboBox^ publisherBox;
	private: System::Windows::Forms::Button^ successButton;
	protected:

	protected:




	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;

	protected:

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
			this->surnameBox = (gcnew System::Windows::Forms::TextBox());
			this->nameBox = (gcnew System::Windows::Forms::TextBox());
			this->dateBox = (gcnew System::Windows::Forms::DateTimePicker());
			this->publisherBox = (gcnew System::Windows::Forms::ComboBox());
			this->successButton = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// surnameBox
			// 
			this->surnameBox->Location = System::Drawing::Point(20, 36);
			this->surnameBox->Name = L"surnameBox";
			this->surnameBox->Size = System::Drawing::Size(195, 20);
			this->surnameBox->TabIndex = 0;
			this->surnameBox->Text = L"Введите фамилию";
			this->surnameBox->TextChanged += gcnew System::EventHandler(this, &InputForm::surnameBox_TextChanged);
			// 
			// nameBox
			// 
			this->nameBox->Location = System::Drawing::Point(244, 36);
			this->nameBox->Name = L"nameBox";
			this->nameBox->Size = System::Drawing::Size(195, 20);
			this->nameBox->TabIndex = 1;
			this->nameBox->Text = L"Введите имя";
			this->nameBox->TextChanged += gcnew System::EventHandler(this, &InputForm::nameBox_TextChanged);
			// 
			// dateBox
			// 
			this->dateBox->Location = System::Drawing::Point(21, 83);
			this->dateBox->Name = L"dateBox";
			this->dateBox->Size = System::Drawing::Size(195, 20);
			this->dateBox->TabIndex = 2;
			this->dateBox->ValueChanged += gcnew System::EventHandler(this, &InputForm::dateBox_ValueChanged);
			// 
			// publisherBox
			// 
			this->publisherBox->FormattingEnabled = true;
			this->publisherBox->Location = System::Drawing::Point(245, 82);
			this->publisherBox->Name = L"publisherBox";
			this->publisherBox->Size = System::Drawing::Size(194, 21);
			this->publisherBox->TabIndex = 3;
			this->publisherBox->Text = L"Выберите издательство";
			this->publisherBox->SelectedIndexChanged += gcnew System::EventHandler(this, &InputForm::publisherBox_SelectedIndexChanged);
			// 
			// successButton
			// 
			this->successButton->Location = System::Drawing::Point(196, 127);
			this->successButton->Name = L"successButton";
			this->successButton->Size = System::Drawing::Size(75, 23);
			this->successButton->TabIndex = 4;
			this->successButton->Text = L"ОК";
			this->successButton->UseVisualStyleBackColor = true;
			this->successButton->Click += gcnew System::EventHandler(this, &InputForm::successButton_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(18, 18);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(56, 13);
			this->label1->TabIndex = 5;
			this->label1->Text = L"Фамилия";
			this->label1->Click += gcnew System::EventHandler(this, &InputForm::label1_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(242, 19);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(29, 13);
			this->label2->TabIndex = 6;
			this->label2->Text = L"Имя";
			this->label2->Click += gcnew System::EventHandler(this, &InputForm::label2_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(19, 66);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(33, 13);
			this->label3->TabIndex = 7;
			this->label3->Text = L"Дата";
			this->label3->Click += gcnew System::EventHandler(this, &InputForm::label3_Click);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(242, 65);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(79, 13);
			this->label4->TabIndex = 8;
			this->label4->Text = L"Издательство";
			this->label4->Click += gcnew System::EventHandler(this, &InputForm::label4_Click);
			// 
			// InputForm
			// 
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::None;
			this->AutoScroll = true;
			this->ClientSize = System::Drawing::Size(459, 162);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->successButton);
			this->Controls->Add(this->publisherBox);
			this->Controls->Add(this->dateBox);
			this->Controls->Add(this->nameBox);
			this->Controls->Add(this->surnameBox);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->MaximizeBox = false;
			this->Name = L"InputForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	
	private: System::Void publisherBox_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void successButton_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void dateBox_ValueChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void nameBox_TextChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void surnameBox_TextChanged(System::Object^ sender, System::EventArgs^ e);
	public: System::Void nameBox_start(String^ nameStart);
	public: System::Void surnameBox_start(String^ surnameStart);
	public: System::Void dateBox_start(String^ dateStart);
	public: System::Void publisherBox_start(array<String^>^ publishers);
	public: System::Void publisherBox_startValue(String^ publisherStart);


	public: String^ input_surname;
	public: String^ input_name;
	public: String^ input_date;
	public: String^ input_publisher;
	public: Boolean success = false;
	public: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	public: System::Void label2_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	public: System::Void label3_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	   public: System::Void label4_Click(System::Object^ sender, System::EventArgs^ e) {
	   }
};
}
