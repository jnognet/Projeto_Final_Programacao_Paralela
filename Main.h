#pragma once

#include "Credits.h"
#include "Webcam.h"
#include "GrayScale.h"

namespace Main {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Form1
	/// </summary>
	public ref class Main : public System::Windows::Forms::Form
	{
	public:
		Main(void)
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
		~Main()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ creditsbutton;
	private: System::Windows::Forms::Button^ webcambutton;
	private: System::Windows::Forms::Button^ grayscalebutton;
	protected:

	private: System::Windows::Forms::Button^ sobelbutton;

	private: System::Windows::Forms::Button^ gaussianbutton;

	private: System::Windows::Forms::PictureBox^ ufacpicturebox;

	private: System::Windows::Forms::PictureBox^ motorolapicturebox;
	private: System::Windows::Forms::PictureBox^ pavicpicturebox;

	protected:

	protected:

	protected:

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
			this->creditsbutton = (gcnew System::Windows::Forms::Button());
			this->webcambutton = (gcnew System::Windows::Forms::Button());
			this->grayscalebutton = (gcnew System::Windows::Forms::Button());
			this->sobelbutton = (gcnew System::Windows::Forms::Button());
			this->gaussianbutton = (gcnew System::Windows::Forms::Button());
			this->ufacpicturebox = (gcnew System::Windows::Forms::PictureBox());
			this->motorolapicturebox = (gcnew System::Windows::Forms::PictureBox());
			this->pavicpicturebox = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ufacpicturebox))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->motorolapicturebox))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pavicpicturebox))->BeginInit();
			this->SuspendLayout();
			// 
			// creditsbutton
			// 
			this->creditsbutton->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
			this->creditsbutton->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->creditsbutton->Location = System::Drawing::Point(32, 404);
			this->creditsbutton->Name = L"creditsbutton";
			this->creditsbutton->Size = System::Drawing::Size(771, 45);
			this->creditsbutton->TabIndex = 5;
			this->creditsbutton->Text = L"Créditos";
			this->creditsbutton->UseVisualStyleBackColor = true;
			this->creditsbutton->Click += gcnew System::EventHandler(this, &Main::creaditsbutton_Click);
			// 
			// webcambutton
			// 
			this->webcambutton->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
			this->webcambutton->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->webcambutton->Location = System::Drawing::Point(34, 340);
			this->webcambutton->Name = L"webcambutton";
			this->webcambutton->Size = System::Drawing::Size(771, 53);
			this->webcambutton->TabIndex = 4;
			this->webcambutton->Text = L"Webcam";
			this->webcambutton->UseVisualStyleBackColor = true;
			this->webcambutton->Click += gcnew System::EventHandler(this, &Main::webcambutton_Click);
			// 
			// grayscalebutton
			// 
			this->grayscalebutton->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
			this->grayscalebutton->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->grayscalebutton->Location = System::Drawing::Point(34, 141);
			this->grayscalebutton->Name = L"grayscalebutton";
			this->grayscalebutton->Size = System::Drawing::Size(771, 53);
			this->grayscalebutton->TabIndex = 0;
			this->grayscalebutton->Text = L"Grayscale Filter";
			this->grayscalebutton->UseVisualStyleBackColor = true;
			this->grayscalebutton->Click += gcnew System::EventHandler(this, &Main::grayscalebutton_Click);
			// 
			// sobelbutton
			// 
			this->sobelbutton->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
			this->sobelbutton->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->sobelbutton->Location = System::Drawing::Point(34, 207);
			this->sobelbutton->Name = L"sobelbutton";
			this->sobelbutton->Size = System::Drawing::Size(771, 53);
			this->sobelbutton->TabIndex = 1;
			this->sobelbutton->Text = L"Sobel Filter";
			this->sobelbutton->UseVisualStyleBackColor = true;
			this->sobelbutton->Click += gcnew System::EventHandler(this, &Main::sobelbutton_Click);
			// 
			// gaussianbutton
			// 
			this->gaussianbutton->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
			this->gaussianbutton->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->gaussianbutton->Location = System::Drawing::Point(34, 274);
			this->gaussianbutton->Name = L"gaussianbutton";
			this->gaussianbutton->Size = System::Drawing::Size(771, 53);
			this->gaussianbutton->TabIndex = 3;
			this->gaussianbutton->Text = L"Gaussian Blur Filter";
			this->gaussianbutton->UseVisualStyleBackColor = true;
			this->gaussianbutton->Click += gcnew System::EventHandler(this, &Main::gaussianbutton_Click);
			// 
			// ufacpicturebox
			// 
			this->ufacpicturebox->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->ufacpicturebox->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->ufacpicturebox->Cursor = System::Windows::Forms::Cursors::Default;
			this->ufacpicturebox->ImageLocation = L"ufac.png";
			this->ufacpicturebox->Location = System::Drawing::Point(105, 24);
			this->ufacpicturebox->Name = L"ufacpicturebox";
			this->ufacpicturebox->Size = System::Drawing::Size(98, 102);
			this->ufacpicturebox->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->ufacpicturebox->TabIndex = 5;
			this->ufacpicturebox->TabStop = false;
			// 
			// motorolapicturebox
			// 
			this->motorolapicturebox->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->motorolapicturebox->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->motorolapicturebox->ImageLocation = L"motorola.png";
			this->motorolapicturebox->Location = System::Drawing::Point(609, 31);
			this->motorolapicturebox->Name = L"motorolapicturebox";
			this->motorolapicturebox->Size = System::Drawing::Size(148, 95);
			this->motorolapicturebox->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->motorolapicturebox->TabIndex = 6;
			this->motorolapicturebox->TabStop = false;
			// 
			// pavicpicturebox
			// 
			this->pavicpicturebox->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->pavicpicturebox->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->pavicpicturebox->ImageLocation = L"pavic.png";
			this->pavicpicturebox->Location = System::Drawing::Point(291, 31);
			this->pavicpicturebox->Name = L"pavicpicturebox";
			this->pavicpicturebox->Size = System::Drawing::Size(241, 95);
			this->pavicpicturebox->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pavicpicturebox->TabIndex = 7;
			this->pavicpicturebox->TabStop = false;
			// 
			// Main
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(845, 468);
			this->Controls->Add(this->pavicpicturebox);
			this->Controls->Add(this->motorolapicturebox);
			this->Controls->Add(this->ufacpicturebox);
			this->Controls->Add(this->gaussianbutton);
			this->Controls->Add(this->sobelbutton);
			this->Controls->Add(this->grayscalebutton);
			this->Controls->Add(this->webcambutton);
			this->Controls->Add(this->creditsbutton);
			this->MinimumSize = System::Drawing::Size(861, 507);
			this->Name = L"Main";
			this->Icon = gcnew System::Drawing::Icon(L"main.ico");
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Projeto Final - Programação Paralela - Grupo 1 - PAVIC LAB/UFAC - v1.0";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ufacpicturebox))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->motorolapicturebox))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pavicpicturebox))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion	
	
	private: System::Void grayscalebutton_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		GrayScale::GrayScale^ grayscale = gcnew GrayScale::GrayScale;
		grayscale->ShowDialog();
	}
	private: System::Void sobelbutton_Click(System::Object^ sender, System::EventArgs^ e) 
	{
	}
	private: System::Void gaussianbutton_Click(System::Object^ sender, System::EventArgs^ e) 
	{
	}
	private: System::Void webcambutton_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		Webcam::Webcam^ webcam = gcnew Webcam::Webcam;
		webcam->ShowDialog();
	}
	private: System::Void creaditsbutton_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		Credits::Credits^ credits = gcnew Credits::Credits;
		credits->ShowDialog();
	}
};
}
