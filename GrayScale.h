#pragma once

#include <string>
#include <iostream>
#include <chrono>
#include <stdio.h> 
#include <stdlib.h>

namespace GrayScale {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace std;

	/// <summary>
	/// Summary for GrayScale
	/// </summary>
	public ref class GrayScale : public System::Windows::Forms::Form
	{
	public:
		GrayScale(void)
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
		~GrayScale()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ filterhalidegpubutton;
	protected:

	private: System::Windows::Forms::Button^ filterhalidecpubutton;
	protected:

	private: System::Windows::Forms::Button^ filtercudabutton;
	private: System::Windows::Forms::Button^ filtercpumultithreadbutton;
	private: System::Windows::Forms::Button^ savebutton;
	private: System::Windows::Forms::Button^ filtercpubutton;
	private: System::Windows::Forms::PictureBox^ outputpicturebox;
	private: System::Windows::Forms::PictureBox^ inputpicturebox;
	private: System::Windows::Forms::Button^ loadbutton;	
	private: System::Windows::Forms::TextBox^ textBox;

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
			this->filterhalidegpubutton = (gcnew System::Windows::Forms::Button());
			this->filterhalidecpubutton = (gcnew System::Windows::Forms::Button());
			this->filtercudabutton = (gcnew System::Windows::Forms::Button());
			this->filtercpumultithreadbutton = (gcnew System::Windows::Forms::Button());
			this->savebutton = (gcnew System::Windows::Forms::Button());
			this->filtercpubutton = (gcnew System::Windows::Forms::Button());
			this->outputpicturebox = (gcnew System::Windows::Forms::PictureBox());
			this->inputpicturebox = (gcnew System::Windows::Forms::PictureBox());
			this->loadbutton = (gcnew System::Windows::Forms::Button());
			this->textBox = (gcnew System::Windows::Forms::TextBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->outputpicturebox))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->inputpicturebox))->BeginInit();
			this->SuspendLayout();
			// 
			// filterhalidegpubutton
			// 
			this->filterhalidegpubutton->Enabled = false;
			this->filterhalidegpubutton->Location = System::Drawing::Point(445, 340);
			this->filterhalidegpubutton->Name = L"filterhalidegpubutton";
			this->filterhalidegpubutton->Size = System::Drawing::Size(143, 41);
			this->filterhalidegpubutton->TabIndex = 6;
			this->filterhalidegpubutton->Text = L"Filter with Halide (GPU)";
			this->filterhalidegpubutton->UseVisualStyleBackColor = true;
			// 
			// filterhalidecpubutton
			// 
			this->filterhalidecpubutton->Enabled = false;
			this->filterhalidecpubutton->Location = System::Drawing::Point(445, 282);
			this->filterhalidecpubutton->Name = L"filterhalidecpubutton";
			this->filterhalidecpubutton->Size = System::Drawing::Size(143, 41);
			this->filterhalidecpubutton->TabIndex = 5;
			this->filterhalidecpubutton->Text = L"Filter with Halide (CPU)";
			this->filterhalidecpubutton->UseVisualStyleBackColor = true;
			// 
			// filtercudabutton
			// 
			this->filtercudabutton->Enabled = false;
			this->filtercudabutton->Location = System::Drawing::Point(445, 221);
			this->filtercudabutton->Name = L"filtercudabutton";
			this->filtercudabutton->Size = System::Drawing::Size(143, 41);
			this->filtercudabutton->TabIndex = 4;
			this->filtercudabutton->Text = L"Filter with CUDA";
			this->filtercudabutton->UseVisualStyleBackColor = true;
			// 
			// filtercpumultithreadbutton
			// 
			this->filtercpumultithreadbutton->Enabled = false;
			this->filtercpumultithreadbutton->Location = System::Drawing::Point(445, 161);
			this->filtercpumultithreadbutton->Name = L"filtercpumultithreadbutton";
			this->filtercpumultithreadbutton->Size = System::Drawing::Size(143, 41);
			this->filtercpumultithreadbutton->TabIndex = 3;
			this->filtercpumultithreadbutton->Text = L"Filter with CPU (multithread)";
			this->filtercpumultithreadbutton->UseVisualStyleBackColor = true;
			// 
			// savebutton
			// 
			this->savebutton->Enabled = false;
			this->savebutton->Location = System::Drawing::Point(701, 18);
			this->savebutton->Name = L"savebutton";
			this->savebutton->Size = System::Drawing::Size(200, 50);
			this->savebutton->TabIndex = 7;
			this->savebutton->Text = L"Save";
			this->savebutton->UseVisualStyleBackColor = true;
			this->savebutton->Click += gcnew System::EventHandler(this, &GrayScale::savebutton_Click);
			// 
			// filtercpubutton
			// 
			this->filtercpubutton->Enabled = false;
			this->filtercpubutton->Location = System::Drawing::Point(445, 102);
			this->filtercpubutton->Name = L"filtercpubutton";
			this->filtercpubutton->Size = System::Drawing::Size(143, 42);
			this->filtercpubutton->TabIndex = 2;
			this->filtercpubutton->Text = L"Filter with CPU";
			this->filtercpubutton->UseVisualStyleBackColor = true;
			this->filtercpubutton->Click += gcnew System::EventHandler(this, &GrayScale::filtercpubutton_Click);
			// 
			// outputpicturebox
			// 
			this->outputpicturebox->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->outputpicturebox->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->outputpicturebox->Location = System::Drawing::Point(606, 86);
			this->outputpicturebox->Name = L"outputpicturebox";
			this->outputpicturebox->Size = System::Drawing::Size(396, 309);
			this->outputpicturebox->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->outputpicturebox->TabIndex = 11;
			this->outputpicturebox->TabStop = false;
			// 
			// inputpicturebox
			// 
			this->inputpicturebox->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->inputpicturebox->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->inputpicturebox->Location = System::Drawing::Point(25, 86);
			this->inputpicturebox->Name = L"inputpicturebox";
			this->inputpicturebox->Size = System::Drawing::Size(398, 310);
			this->inputpicturebox->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->inputpicturebox->TabIndex = 10;
			this->inputpicturebox->TabStop = false;
			// 
			// loadbutton
			// 
			this->loadbutton->Location = System::Drawing::Point(124, 18);
			this->loadbutton->Name = L"loadbutton";
			this->loadbutton->Size = System::Drawing::Size(200, 50);
			this->loadbutton->TabIndex = 1;
			this->loadbutton->Text = L"Load";
			this->loadbutton->UseVisualStyleBackColor = true;
			this->loadbutton->Click += gcnew System::EventHandler(this, &GrayScale::loadbutton_Click);
			// 
			// textBox
			// 
			this->textBox->AcceptsReturn = true;
			this->textBox->Location = System::Drawing::Point(25, 416);
			this->textBox->Multiline = true;
			this->textBox->Name = L"textBox";
			this->textBox->ReadOnly = true;
			this->textBox->ScrollBars = System::Windows::Forms::ScrollBars::Both;
			this->textBox->Size = System::Drawing::Size(977, 63);
			this->textBox->TabIndex = 8;
			// 
			// GrayScale
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1027, 491);
			this->Controls->Add(this->textBox);
			this->Controls->Add(this->filterhalidegpubutton);
			this->Controls->Add(this->filterhalidecpubutton);
			this->Controls->Add(this->filtercudabutton);
			this->Controls->Add(this->filtercpumultithreadbutton);
			this->Controls->Add(this->savebutton);
			this->Controls->Add(this->filtercpubutton);
			this->Controls->Add(this->outputpicturebox);
			this->Controls->Add(this->inputpicturebox);
			this->Controls->Add(this->loadbutton);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"GrayScale";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"GrayScale Filter";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->outputpicturebox))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->inputpicturebox))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

		private: System::Void loadbutton_Click(System::Object^ sender, System::EventArgs^ e) 
		{
			loadbutton->Enabled = false;
			savebutton->Enabled = false;
			OpenFileDialog^ openFileDialog = gcnew OpenFileDialog();
			openFileDialog->Filter = "All supported graphics|*.jpg;*.jpeg;*.png|" +
				"JPEG (*.jpg;*.jpeg)|*.jpg;*.jpeg|" +
				"Portable Network Graphic (*.png)|*.png";
			if (openFileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK)
			{
				Bitmap^ image = gcnew Bitmap(openFileDialog->FileName);
				inputpicturebox->Image = image;				
				if (inputpicturebox->Image != nullptr) {
					outputpicturebox->Image = nullptr;
					enableFilters();
				}
			}		
			loadbutton->Enabled = true;
		}

		private: System::Void enableFilters()
		{
			filtercpubutton->Enabled = true;
			filtercpumultithreadbutton->Enabled = true;
			filtercudabutton->Enabled = true;
			filterhalidecpubutton->Enabled = true;
			filterhalidegpubutton->Enabled = true;
		}

		private: System::Void filtercpubutton_Click(System::Object^ sender, System::EventArgs^ e) 
		{
			Bitmap^ bmp = dynamic_cast<Bitmap^>(inputpicturebox->Image->Clone());
			Bitmap^ output = gcnew System::Drawing::Bitmap(bmp->Width, bmp->Height, bmp->PixelFormat);
			output->SetResolution(bmp->HorizontalResolution, bmp->VerticalResolution);
			std::chrono::high_resolution_clock::time_point t1 = std::chrono::high_resolution_clock::now();
			for (int x = 0; x < bmp->Width; x++) {
				for (int y = 0; y < bmp->Height; y++) {
					Color pixelsrc = bmp->GetPixel(x, y);
					int value = (0.299 * pixelsrc.R) + (0.587 * pixelsrc.G) + (0.114 * pixelsrc.B);
					Color c = Color::FromArgb(value, value, value);
					output->SetPixel(x, y, c);
				}
			} 
			outputpicturebox->Image = output;
			std::chrono::high_resolution_clock::time_point t2 = std::chrono::high_resolution_clock::now();
			std::chrono::duration<double> time_span = std::chrono::duration_cast<std::chrono::duration<double>>(t2 - t1);
			textBox->Text = textBox->Text + "Filtered using CPU in " + time_span.count() + " seconds.\r\n";
			textBox->SelectionStart = textBox->Text->Length;
			textBox->ScrollToCaret();
			savebutton->Enabled = true;
		}

		private: System::Void savebutton_Click(System::Object^ sender, System::EventArgs^ e) {
			savebutton->Enabled = false;
			/* 
			OpenFileDialog^ openFileDialog = gcnew OpenFileDialog();
				openFileDialog->Filter = "All supported graphics|*.jpg;*.jpeg;*.png|" +
				"JPEG (*.jpg;*.jpeg)|*.jpg;*.jpeg|" +
				"Portable Network Graphic (*.png)|*.png";
			if (openFileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK)
			{
				outputpicturebox->Image = nullptr;
			}
			*/
			Bitmap^ bmp = dynamic_cast<Bitmap^>(outputpicturebox->Image->Clone());			
			bmp->Save("c:\\temp\\teste.png", Imaging::ImageFormat::Jpeg); 

			outputpicturebox->Image = nullptr;
			textBox->Text = textBox->Text + "File saved.\r\n";
			textBox->SelectionStart = textBox->Text->Length;
			textBox->ScrollToCaret();
		}
	};
}
