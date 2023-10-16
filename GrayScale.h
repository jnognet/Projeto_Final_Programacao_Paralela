#pragma once

#include <string>
#include <iostream>
#include <chrono>
#include <stdio.h> 
#include <stdlib.h>
#include <thread>
#include <filesystem>

#include <opencv2/core.hpp>
#include <opencv2/video.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>

#include "Pixel.h"
#include "FilterCuda.h"
#include "FilterHalide.h"

namespace GrayScale {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace std;
	
	void thread_obj(Pixel_t* image, int i, int pixels_to_process, int chunk_size);
			
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
	private: System::Windows::Forms::Button^ clearbutton;


	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(GrayScale::typeid));
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
			this->clearbutton = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->outputpicturebox))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->inputpicturebox))->BeginInit();
			this->SuspendLayout();
			// 
			// filterhalidegpubutton
			// 
			this->filterhalidegpubutton->Enabled = false;
			this->filterhalidegpubutton->Location = System::Drawing::Point(430, 324);
			this->filterhalidegpubutton->Name = L"filterhalidegpubutton";
			this->filterhalidegpubutton->Size = System::Drawing::Size(143, 41);
			this->filterhalidegpubutton->TabIndex = 6;
			this->filterhalidegpubutton->Text = L"Filter with Halide (GPU)";
			this->filterhalidegpubutton->UseVisualStyleBackColor = true;
			this->filterhalidegpubutton->Click += gcnew System::EventHandler(this, &GrayScale::filterhalidegpubutton_Click);
			// 
			// filterhalidecpubutton
			// 
			this->filterhalidecpubutton->Enabled = false;
			this->filterhalidecpubutton->Location = System::Drawing::Point(430, 266);
			this->filterhalidecpubutton->Name = L"filterhalidecpubutton";
			this->filterhalidecpubutton->Size = System::Drawing::Size(143, 41);
			this->filterhalidecpubutton->TabIndex = 5;
			this->filterhalidecpubutton->Text = L"Filter with Halide (CPU)";
			this->filterhalidecpubutton->UseVisualStyleBackColor = true;
			this->filterhalidecpubutton->Click += gcnew System::EventHandler(this, &GrayScale::filterhalidecpubutton_Click);
			// 
			// filtercudabutton
			// 
			this->filtercudabutton->Enabled = false;
			this->filtercudabutton->Location = System::Drawing::Point(430, 205);
			this->filtercudabutton->Name = L"filtercudabutton";
			this->filtercudabutton->Size = System::Drawing::Size(143, 41);
			this->filtercudabutton->TabIndex = 4;
			this->filtercudabutton->Text = L"Filter with CUDA";
			this->filtercudabutton->UseVisualStyleBackColor = true;
			this->filtercudabutton->Click += gcnew System::EventHandler(this, &GrayScale::filtercudabutton_Click);
			// 
			// filtercpumultithreadbutton
			// 
			this->filtercpumultithreadbutton->Enabled = false;
			this->filtercpumultithreadbutton->Location = System::Drawing::Point(430, 145);
			this->filtercpumultithreadbutton->Name = L"filtercpumultithreadbutton";
			this->filtercpumultithreadbutton->Size = System::Drawing::Size(143, 41);
			this->filtercpumultithreadbutton->TabIndex = 3;
			this->filtercpumultithreadbutton->Text = L"Filter with CPU (multithread)";
			this->filtercpumultithreadbutton->UseVisualStyleBackColor = true;
			this->filtercpumultithreadbutton->Click += gcnew System::EventHandler(this, &GrayScale::filtercpumultithreadbutton_Click);
			// 
			// savebutton
			// 
			this->savebutton->Enabled = false;
			this->savebutton->Location = System::Drawing::Point(687, 9);
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
			this->filtercpubutton->Location = System::Drawing::Point(430, 86);
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
			this->outputpicturebox->Location = System::Drawing::Point(592, 73);
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
			this->inputpicturebox->Location = System::Drawing::Point(11, 73);
			this->inputpicturebox->Name = L"inputpicturebox";
			this->inputpicturebox->Size = System::Drawing::Size(398, 310);
			this->inputpicturebox->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->inputpicturebox->TabIndex = 10;
			this->inputpicturebox->TabStop = false;
			// 
			// loadbutton
			// 
			this->loadbutton->Location = System::Drawing::Point(110, 9);
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
			this->textBox->Location = System::Drawing::Point(11, 389);
			this->textBox->Multiline = true;
			this->textBox->Name = L"textBox";
			this->textBox->ReadOnly = true;
			this->textBox->ScrollBars = System::Windows::Forms::ScrollBars::Both;
			this->textBox->Size = System::Drawing::Size(977, 90);
			this->textBox->TabIndex = 8;
			// 
			// clearbutton
			// 
			this->clearbutton->Location = System::Drawing::Point(12, 9);
			this->clearbutton->Name = L"clearbutton";
			this->clearbutton->Size = System::Drawing::Size(51, 50);
			this->clearbutton->TabIndex = 12;
			this->clearbutton->Text = L"Clear";
			this->clearbutton->UseVisualStyleBackColor = true;
			this->clearbutton->Click += gcnew System::EventHandler(this, &GrayScale::clearbutton_Click);
			// 
			// GrayScale
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1000, 491);
			this->Controls->Add(this->clearbutton);
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
			// this->Icon = gcnew System::Drawing::Icon(L"filter.ico");
			this->Icon = gcnew System::Drawing::Icon(L"filter.ico");
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
			openFileDialog->Filter = "All supported graphics|*.jpg;*.jpeg;|" +
				"JPEG (*.jpg;*.jpeg)|*.jpg;*.jpeg";
			if (openFileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK)
			{
				Bitmap^ image = gcnew Bitmap(openFileDialog->FileName);
				inputpicturebox->Image = image;
				if (inputpicturebox->Image != nullptr) {
					String^ msg = gcnew String("");
					msg += image->Width + " w, ";
					msg += image->Height + " h, ";
					msg += image->HorizontalResolution + " ppi h, ";
					msg += image->VerticalResolution + " ppi v, ";
					msg += image->PixelFormat.ToString() + ", ";
					msg += Image::GetPixelFormatSize(image->PixelFormat) + " bits";
					textBox->Text = textBox->Text + "Image loaded: " + 
						openFileDialog->FileName + " (" +
							msg +
						")\r\n";
					textBox->SelectionStart = textBox->TextLength;
					textBox->ScrollToCaret();

					outputpicturebox->Image = nullptr;
					enableFilters();
				}
			}
			loadbutton->Enabled = true;
		}

		private: System::Void disableFilters()
		{
			filtercpubutton->Enabled = false;
			filtercpumultithreadbutton->Enabled = false;
			filtercudabutton->Enabled = false;
			filterhalidecpubutton->Enabled = false;
			filterhalidegpubutton->Enabled = false;
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
			disableFilters();
			Bitmap^ input = dynamic_cast<Bitmap^>(inputpicturebox->Image->Clone());
			if (input->GetPixelFormatSize(input->PixelFormat) != 24) {
				MessageBox::Show("Filter expecting 3 channels", "Warning!", MessageBoxButtons::OK);
			}
			else
			{
				std::chrono::high_resolution_clock::time_point t1 = std::chrono::high_resolution_clock::now();

				// https://support.ptc.com/help/mathcad/r9.0/en/index.html#page/PTC_Mathcad_Help/example_grayscale_and_color_in_images.html

				System::Drawing::Rectangle rec = System::Drawing::Rectangle(0, 0, input->Width, input->Height);
				System::Drawing::Imaging::BitmapData^ bmpData = input->LockBits(rec, System::Drawing::Imaging::ImageLockMode::ReadWrite,
					input->PixelFormat);

				IntPtr^ pbm = bmpData->Scan0;
				Byte* imagePointer1 = (Byte*)pbm->ToPointer();

				for (int i = 0; i < input->Height * input->Width; i++)
				{
					unsigned char value = (0.299 * imagePointer1[2]) + (0.587 * imagePointer1[1]) + (0.114 * imagePointer1[0]);
					imagePointer1[0] = value;
					imagePointer1[1] = value;
					imagePointer1[2] = value;
					imagePointer1 += 3;
				}
				input->UnlockBits(bmpData);

				outputpicturebox->Image = input;
				std::chrono::high_resolution_clock::time_point t2 = std::chrono::high_resolution_clock::now();
				std::chrono::duration<double> time_span = std::chrono::duration_cast<std::chrono::duration<double>>(t2 - t1);
				textBox->Text = textBox->Text + "Filtered using CPU in " + time_span.count() + " seconds.\r\n";
				textBox->SelectionStart = textBox->TextLength;
				textBox->ScrollToCaret();
				savebutton->Enabled = true;
			}
			enableFilters();
		}

		private: System::Void savebutton_Click(System::Object^ sender, System::EventArgs^ e) {
			savebutton->Enabled = false;
			SaveFileDialog^ saveFileDialog = gcnew SaveFileDialog();
			saveFileDialog->Filter = "All supported graphics|*.jpg;*.jpeg;|" +
				"JPEG (*.jpg;*.jpeg)|*.jpg;*.jpeg";
			if (saveFileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK)
			{
				Bitmap^ bmp = dynamic_cast<Bitmap^>(outputpicturebox->Image->Clone());
				bmp->Save(saveFileDialog->FileName, Imaging::ImageFormat::Jpeg);
				outputpicturebox->Image = nullptr;
				textBox->Text = textBox->Text + "File saved: " + saveFileDialog->FileName + ".\r\n";
				textBox->SelectionStart = textBox->TextLength;
				textBox->ScrollToCaret();
			}
			else
			{
				savebutton->Enabled = true;
			}
		}

		private: System::Void filtercpumultithreadbutton_Click(System::Object^ sender, System::EventArgs^ e) {
			disableFilters();
			Bitmap^ input = dynamic_cast<Bitmap^>(inputpicturebox->Image->Clone());
			if (input->GetPixelFormatSize(input->PixelFormat) != 24)
			{
				MessageBox::Show("Filter expecting 3 channels", "Warning!", MessageBoxButtons::OK);
			}
			else
			{
				std::chrono::high_resolution_clock::time_point t1 = std::chrono::high_resolution_clock::now();

				System::Drawing::Rectangle rec = System::Drawing::Rectangle(0, 0, input->Width, input->Height);
				System::Drawing::Imaging::BitmapData^ bmpData = input->LockBits(rec, System::Drawing::Imaging::ImageLockMode::ReadOnly,
					input->PixelFormat);
				IntPtr^ pbm = bmpData->Scan0;
				Byte* imagePointer1 = (Byte*)pbm->ToPointer();

				Pixel_t* image = (Pixel_t*) malloc(input->Width * input->Height * sizeof(Pixel_t));
				if (image != NULL) {
					int pointer = 0;
					for (int y = 0; y < input->Height; y++) {
						for (int x = 0; x < input->Width; x++) {
							Pixel_t outpixel = { imagePointer1[2], imagePointer1[1], imagePointer1[0] };
							*(image + pointer++) = outpixel;
							imagePointer1 += 3;
						}
						imagePointer1 += (bmpData->Stride - (bmpData->Width * 3));
					}
				}
				input->UnlockBits(bmpData);

				const int num_threads = thread::hardware_concurrency();
				vector<thread> threads(num_threads);
				int chunk_size = static_cast<int>(ceil(static_cast<double>(input->Width * input->Height) / num_threads));
				int remaining_pixels = input->Width * input->Height;

				for (int i = 0; i < num_threads; i++) {
					int pixels_to_process = min(chunk_size, static_cast<int>(remaining_pixels));
					threads[i] = thread(thread_obj, image, i, pixels_to_process, chunk_size);
					remaining_pixels -= pixels_to_process;
					if (remaining_pixels <= 0) {
						break;
					}
				}

				for (auto& thread : threads) {
					thread.join();
				}

				rec = System::Drawing::Rectangle(0, 0, input->Width, input->Height);
				bmpData = input->LockBits(rec, System::Drawing::Imaging::ImageLockMode::WriteOnly, input->PixelFormat);
				pbm = bmpData->Scan0;
				imagePointer1 = (Byte*)pbm->ToPointer();

				if (image != NULL) {
					int pointer = 0;
					for (int y = 0; y < input->Height; y++) {
						for (int x = 0; x < input->Width; x++) {
							Pixel_t inpixel = *(image + pointer++);
							imagePointer1[2] = inpixel.R;
							imagePointer1[1] = inpixel.G;
							imagePointer1[0] = inpixel.B;
							imagePointer1 += 3;
						}
						imagePointer1 += (bmpData->Stride - (bmpData->Width * 3));
					}
					free(image);
				}
				input->UnlockBits(bmpData);

				outputpicturebox->Image = input;
				std::chrono::high_resolution_clock::time_point t2 = std::chrono::high_resolution_clock::now();
				std::chrono::duration<double> time_span = std::chrono::duration_cast<std::chrono::duration<double>>(t2 - t1);
				textBox->Text = textBox->Text + "Filtered using CPU multithread in " + time_span.count() + " seconds.\r\n";
				textBox->SelectionStart = textBox->TextLength;
				textBox->ScrollToCaret();
				savebutton->Enabled = true;
			}
			enableFilters();
		}

		private: System::Void filtercudabutton_Click(System::Object^ sender, System::EventArgs^ e) {
			disableFilters();
			Bitmap^ input = dynamic_cast<Bitmap^>(inputpicturebox->Image->Clone());
			if (input->GetPixelFormatSize(input->PixelFormat) != 24)
			{
				MessageBox::Show("Filter expecting 3 channels", "Warning!", MessageBoxButtons::OK);
			}
			else
			{
				string file_input = filesystem::temp_directory_path().generic_string().append("input_tmp.jpg");
				string file_output = filesystem::temp_directory_path().generic_string().append("output_tmp.jpg");
				input->Save(gcnew String(file_input.c_str()));
				std::chrono::high_resolution_clock::time_point t1 = std::chrono::high_resolution_clock::now();
				if (grayScaleWithCuda(file_input, file_output))
				{
					std::chrono::high_resolution_clock::time_point t2 = std::chrono::high_resolution_clock::now();
					std::chrono::duration<double> time_span = std::chrono::duration_cast<std::chrono::duration<double>>(t2 - t1);
					textBox->Text = textBox->Text + "Filtered using CUDA in " + time_span.count() + " seconds.\r\n";
					textBox->SelectionStart = textBox->TextLength;
					textBox->ScrollToCaret();
					savebutton->Enabled = true;
					outputpicturebox->ImageLocation = gcnew String(file_output.c_str());
				}
				else
				{
					MessageBox::Show("Error running CUDA", "Error!", MessageBoxButtons::OK);
				}
			}
			enableFilters();
		}

		private: System::Void filterhalidecpubutton_Click(System::Object^ sender, System::EventArgs^ e)
		{
			disableFilters();
			Bitmap^ input = dynamic_cast<Bitmap^>(inputpicturebox->Image->Clone());
			if (inputpicturebox->Image->PixelFormat == Drawing::Imaging::PixelFormat::Format8bppIndexed)
			{
				MessageBox::Show("Filter expecting 3 channels", "Warning!", MessageBoxButtons::OK);
			}
			else
			{					
				string file_input = filesystem::temp_directory_path().generic_string().append("input_tmp.jpg");
				string file_output = filesystem::temp_directory_path().generic_string().append("output_tmp.jpg");
				input->Save(gcnew String(file_input.c_str()));
				std::chrono::high_resolution_clock::time_point t1 = std::chrono::high_resolution_clock::now();
				if (grayScaleWithHalideCPU(file_input, file_output))
				{
					std::chrono::high_resolution_clock::time_point t2 = std::chrono::high_resolution_clock::now();
					std::chrono::duration<double> time_span = std::chrono::duration_cast<std::chrono::duration<double>>(t2 - t1);
					textBox->Text = textBox->Text + "Filtered using Halide with CPU in " + time_span.count() + " seconds.\r\n";
					textBox->SelectionStart = textBox->TextLength;
					textBox->ScrollToCaret();
					savebutton->Enabled = true;
					outputpicturebox->ImageLocation = gcnew String(file_output.c_str());
				}
				else
				{
					MessageBox::Show("Error running Halide", "Error!", MessageBoxButtons::OK);
				}
			}
			enableFilters();
		}

		private: System::Void clearbutton_Click(System::Object^ sender, System::EventArgs^ e) {
			disableFilters();
			savebutton->Enabled = false;
			inputpicturebox->Image = nullptr;
			outputpicturebox->Image = nullptr;
			textBox->Text = "";
		}

		private: System::Void filterhalidegpubutton_Click(System::Object^ sender, System::EventArgs^ e) {
			disableFilters();
			Bitmap^ input = dynamic_cast<Bitmap^>(inputpicturebox->Image->Clone());
			if (inputpicturebox->Image->PixelFormat == Drawing::Imaging::PixelFormat::Format8bppIndexed)
			{
				MessageBox::Show("Filter expecting 3 channels", "Warning!", MessageBoxButtons::OK);
			}
			else
			{
				string file_input = filesystem::temp_directory_path().generic_string().append("input_tmp.jpg");
				string file_output = filesystem::temp_directory_path().generic_string().append("output_tmp.jpg");
				input->Save(gcnew String(file_input.c_str()));
				std::chrono::high_resolution_clock::time_point t1 = std::chrono::high_resolution_clock::now();
				if (grayScaleWithHalideGPU(file_input, file_output))
				{
					std::chrono::high_resolution_clock::time_point t2 = std::chrono::high_resolution_clock::now();
					std::chrono::duration<double> time_span = std::chrono::duration_cast<std::chrono::duration<double>>(t2 - t1);
					textBox->Text = textBox->Text + "Filtered using Halide with GPU in " + time_span.count() + " seconds.\r\n";
					textBox->SelectionStart = textBox->TextLength;
					textBox->ScrollToCaret();
					savebutton->Enabled = true;
					outputpicturebox->ImageLocation = gcnew String(file_output.c_str());
				}
				else
				{
					MessageBox::Show("Error running Halide", "Error!", MessageBoxButtons::OK);
				}
			}
			enableFilters();
		}

};

	void thread_obj(Pixel_t* image, int i, int pixels_to_process, int chunk_size)
	{
		int start = i * chunk_size;
		for (int j = start; j < start + pixels_to_process; j++) {
			Pixel_t inpixel = *(image + j);
			int value = (0.299 * inpixel.R) + (0.587 * inpixel.G) + (0.114 * inpixel.B);
			inpixel.R = value;
			inpixel.G = value;
			inpixel.B = value;
			*(image + j) = inpixel;
		}
	};

}
