#pragma once

#include <chrono>

namespace GaussianBlur {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for GaussianBlur
	/// </summary>
	public ref class GaussianBlur : public System::Windows::Forms::Form
	{
	public:
		GaussianBlur(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~GaussianBlur()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ loadbutton;
	protected:

	protected:
	private: System::Windows::Forms::PictureBox^ capturepicturebox;
	private: System::Windows::Forms::PictureBox^ pictureBox2;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ savebutton;

	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::Button^ button5;
	private: System::Windows::Forms::Button^ button6;
	private: System::Windows::Forms::Button^ button7;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->loadbutton = (gcnew System::Windows::Forms::Button());
			this->capturepicturebox = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->savebutton = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->button7 = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->capturepicturebox))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			this->SuspendLayout();
			// 
			// loadbutton
			// 
			this->loadbutton->Location = System::Drawing::Point(126, 25);
			this->loadbutton->Name = L"loadbutton";
			this->loadbutton->Size = System::Drawing::Size(200, 50);
			this->loadbutton->TabIndex = 0;
			this->loadbutton->Text = L"Load";
			this->loadbutton->UseVisualStyleBackColor = true;
			this->loadbutton->Click += gcnew System::EventHandler(this, &GaussianBlur::button1_Click);
			// 
			// capturepicturebox
			// 
			this->capturepicturebox->Location = System::Drawing::Point(26, 100);
			this->capturepicturebox->Name = L"capturepicturebox";
			this->capturepicturebox->Size = System::Drawing::Size(398, 310);
			this->capturepicturebox->TabIndex = 1;
			this->capturepicturebox->TabStop = false;
			// 
			// pictureBox2
			// 
			this->pictureBox2->Location = System::Drawing::Point(607, 100);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(396, 309);
			this->pictureBox2->TabIndex = 2;
			this->pictureBox2->TabStop = false;
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(448, 116);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(143, 42);
			this->button2->TabIndex = 3;
			this->button2->Text = L"Filter with CPU";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &GaussianBlur::button2_Click);
			// 
			// savebutton
			// 
			this->savebutton->Location = System::Drawing::Point(702, 25);
			this->savebutton->Name = L"savebutton";
			this->savebutton->Size = System::Drawing::Size(200, 50);
			this->savebutton->TabIndex = 4;
			this->savebutton->Text = L"Save";
			this->savebutton->UseVisualStyleBackColor = true;
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(448, 175);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(143, 41);
			this->button4->TabIndex = 5;
			this->button4->Text = L"Filter with CPU (multithread)";
			this->button4->UseVisualStyleBackColor = true;
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(448, 235);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(143, 41);
			this->button5->TabIndex = 6;
			this->button5->Text = L"Filter with CUDA";
			this->button5->UseVisualStyleBackColor = true;
			// 
			// button6
			// 
			this->button6->Location = System::Drawing::Point(448, 296);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(143, 41);
			this->button6->TabIndex = 7;
			this->button6->Text = L"Filter with Halide (CPU)";
			this->button6->UseVisualStyleBackColor = true;
			// 
			// button7
			// 
			this->button7->Location = System::Drawing::Point(448, 354);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(143, 41);
			this->button7->TabIndex = 8;
			this->button7->Text = L"Filter with Halide (GPU)";
			this->button7->UseVisualStyleBackColor = true;
			// 
			// GaussianBlur
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1027, 455);
			this->Controls->Add(this->button7);
			this->Controls->Add(this->button6);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->savebutton);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->pictureBox2);
			this->Controls->Add(this->capturepicturebox);
			this->Controls->Add(this->loadbutton);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"GaussianBlur";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Image GaussianBlur Filter";
			this->Load += gcnew System::EventHandler(this, &GaussianBlur::GaussianBlur_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->capturepicturebox))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		auto start = std::chrono::high_resolution_clock::now();
		
		auto stop = std::chrono::high_resolution_clock::now();
		auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
	}
private: System::Void GaussianBlur_Load(System::Object^ sender, System::EventArgs^ e) {
}
};
}
