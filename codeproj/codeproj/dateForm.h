#pragma once

namespace codeproj {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для dateForm
	/// </summary>
	public ref class dateForm : public System::Windows::Forms::Form
	{
	public:
		dateForm(void)
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
		~dateForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::DateTimePicker^ dateFromPicker;
	protected:
	private: System::Windows::Forms::DateTimePicker^ dateToPicker;
	private: System::Windows::Forms::Button^ SuccessButton;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;

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
			this->dateFromPicker = (gcnew System::Windows::Forms::DateTimePicker());
			this->dateToPicker = (gcnew System::Windows::Forms::DateTimePicker());
			this->SuccessButton = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// dateFromPicker
			// 
			this->dateFromPicker->Location = System::Drawing::Point(34, 37);
			this->dateFromPicker->Margin = System::Windows::Forms::Padding(2);
			this->dateFromPicker->Name = L"dateFromPicker";
			this->dateFromPicker->Size = System::Drawing::Size(151, 20);
			this->dateFromPicker->TabIndex = 0;
			this->dateFromPicker->ValueChanged += gcnew System::EventHandler(this, &dateForm::dateFromPicker_ValueChanged);
			// 
			// dateToPicker
			// 
			this->dateToPicker->Location = System::Drawing::Point(222, 37);
			this->dateToPicker->Margin = System::Windows::Forms::Padding(2);
			this->dateToPicker->Name = L"dateToPicker";
			this->dateToPicker->Size = System::Drawing::Size(151, 20);
			this->dateToPicker->TabIndex = 1;
			this->dateToPicker->ValueChanged += gcnew System::EventHandler(this, &dateForm::dateToPicker_ValueChanged);
			// 
			// SuccessButton
			// 
			this->SuccessButton->Location = System::Drawing::Point(159, 82);
			this->SuccessButton->Margin = System::Windows::Forms::Padding(2);
			this->SuccessButton->Name = L"SuccessButton";
			this->SuccessButton->Size = System::Drawing::Size(91, 29);
			this->SuccessButton->TabIndex = 2;
			this->SuccessButton->Text = L"OK";
			this->SuccessButton->UseVisualStyleBackColor = true;
			this->SuccessButton->Click += gcnew System::EventHandler(this, &dateForm::SuccessButton_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(32, 20);
			this->label1->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(45, 13);
			this->label1->TabIndex = 3;
			this->label1->Text = L"С даты:";
			this->label1->Click += gcnew System::EventHandler(this, &dateForm::label1_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(220, 20);
			this->label2->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(49, 13);
			this->label2->TabIndex = 4;
			this->label2->Text = L"По дату:";
			// 
			// dateForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(412, 134);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->SuccessButton);
			this->Controls->Add(this->dateToPicker);
			this->Controls->Add(this->dateFromPicker);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->Name = L"dateForm";
			this->Text = L"Поиск по дате";
			this->Load += gcnew System::EventHandler(this, &dateForm::dateForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void dateForm_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void dateFromPicker_ValueChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void dateToPicker_ValueChanged(System::Object^ sender, System::EventArgs^ e);
	public: System::Void SuccessButton_Click(System::Object^ sender, System::EventArgs^ e);
	public: String^ input_dateFrom;
	public: String^ input_dateTo;
	public: Boolean success = false;
	public: System::Void dateForm_Closed(System::Object^ sender, FormClosedEventArgs^ e) {
		MessageBox::Show("Closed");
	}
};
}
