#pragma once

namespace Credits {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class Credits : public System::Windows::Forms::Form
	{
	public:
		Credits(void)
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
		~Credits()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::GroupBox^ groupBox1;
	protected:
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label6;

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Credits::typeid));
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->groupBox1->SuspendLayout();
			this->SuspendLayout();
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->label6);
			this->groupBox1->Controls->Add(this->label5);
			this->groupBox1->Controls->Add(this->label4);
			this->groupBox1->Controls->Add(this->label3);
			this->groupBox1->Controls->Add(this->label2);
			this->groupBox1->Controls->Add(this->label1);
			this->groupBox1->Location = System::Drawing::Point(12, 9);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(480, 232);
			this->groupBox1->TabIndex = 0;
			this->groupBox1->TabStop = false;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(81, 33);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(313, 13);
			this->label6->TabIndex = 5;
			this->label6->Text = L"Alexandre dos Santos Dantas (alexandredantas07@hotmail.com)";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(104, 91);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(275, 13);
			this->label5->TabIndex = 4;
			this->label5->Text = L"Isaac Dayan Bastos da Silva (isaacdayanbs@gmail.com)";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(116, 121);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(250, 13);
			this->label4->TabIndex = 3;
			this->label4->Text = L"Jo�o Gabriel Pires Cordovil (gabrielriery@gmail.com)";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(100, 182);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(270, 13);
			this->label3->TabIndex = 2;
			this->label3->Text = L"Lorraina Vit�ria Costa dos Santos (qlorraina@gmail.com)";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(91, 62);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(293, 13);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Gustavo Moreira Oliveira de Castro (gkmocastro@gmail.com)";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(112, 152);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(248, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Jos� Nogueira da Costa Neto (jnognet@gmail.com)";
			// 
			// Credits
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(504, 253);
			this->Controls->Add(this->groupBox1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			// this->Icon = gcnew System::Drawing::Icon(L"credits.ico");
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"Credits";
			this->Icon = gcnew System::Drawing::Icon(L"credits.ico");
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Cr�ditos";
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	};
}
