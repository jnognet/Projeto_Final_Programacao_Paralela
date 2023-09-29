#pragma once

#include <opencv2/core.hpp>
#include <opencv2/video.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>

#include <string>
#include <iostream>

namespace Webcam {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace std;

	/// <summary>
	/// Summary for Webcam
	/// </summary>
	public ref class Webcam : public System::Windows::Forms::Form
	{
	public:
		Webcam(void)
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
		~Webcam()
		{
			delete pframe;
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ capturebutton;
	private: System::Windows::Forms::PictureBox^ capturepicturebox;
	private: System::Windows::Forms::Button^ savebutton;
	private: cv::Mat* pframe;
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
			this->capturebutton = (gcnew System::Windows::Forms::Button());
			this->capturepicturebox = (gcnew System::Windows::Forms::PictureBox());
			this->savebutton = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->capturepicturebox))->BeginInit();
			this->SuspendLayout();
			// 
			// capturebutton
			// 
			this->capturebutton->Location = System::Drawing::Point(78, 12);
			this->capturebutton->Name = L"capturebutton";
			this->capturebutton->Size = System::Drawing::Size(259, 68);
			this->capturebutton->TabIndex = 0;
			this->capturebutton->Text = L"Capture";
			this->capturebutton->UseVisualStyleBackColor = true;
			this->capturebutton->Click += gcnew System::EventHandler(this, &Webcam::capture_Click);
			// 
			// capturepicturebox
			// 
			this->capturepicturebox->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->capturepicturebox->Location = System::Drawing::Point(44, 94);
			this->capturepicturebox->Name = L"capturepicturebox";
			this->capturepicturebox->Size = System::Drawing::Size(328, 231);
			this->capturepicturebox->TabIndex = 1;
			this->capturepicturebox->TabStop = false;
			// 
			// savebutton
			// 
			this->savebutton->Enabled = false;
			this->savebutton->Location = System::Drawing::Point(78, 344);
			this->savebutton->Name = L"savebutton";
			this->savebutton->Size = System::Drawing::Size(259, 68);
			this->savebutton->TabIndex = 4;
			this->savebutton->Text = L"Save to File";
			this->savebutton->UseVisualStyleBackColor = true;
			this->savebutton->Click += gcnew System::EventHandler(this, &Webcam::save_Click);
			// 
			// Webcam
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(415, 427);
			this->Controls->Add(this->savebutton);
			this->Controls->Add(this->capturepicturebox);
			this->Controls->Add(this->capturebutton);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"Webcam";
			this->Icon = gcnew System::Drawing::Icon(L"webcam.ico");
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Webcam";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->capturepicturebox))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
		private: System::Void capture_Click(System::Object^ sender, System::EventArgs^ e) 
		{	
			capturebutton->Enabled = false;
			savebutton->Enabled = false;
			cv::VideoCapture cap;
			cv::Mat frame;

			int deviceID = 0; 
			int apiID = cv::CAP_ANY;
			cap.open(deviceID, apiID);
			if (cap.isOpened())
			{
				cap.read( frame );
				if (! frame.empty())
				{
					System::Drawing::Graphics^ graphics = capturepicturebox->CreateGraphics();
					System::IntPtr ptr(frame.ptr());
					System::Drawing::Bitmap^ b = gcnew System::Drawing::Bitmap(frame.cols, frame.rows, frame.step, System::Drawing::Imaging::PixelFormat::Format24bppRgb, ptr);
					System::Drawing::RectangleF rect(0, 0, capturepicturebox->Width, capturepicturebox->Height);
					graphics->DrawImage(b, rect);
					pframe = new cv::Mat(frame.rows, frame.cols, frame.type());
					*pframe = frame.clone();
					savebutton->Enabled = true;
				}
			}
			else 
			{
				MessageBox::Show("Webcam error", "Error !", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
			frame.release();
			cap.release();
			capturebutton->Enabled = true;
		}

		void MarshalString(String^ s, string& os) {
			using namespace Runtime::InteropServices;
			const char* chars =
				(const char*)(Marshal::StringToHGlobalAnsi(s)).ToPointer();
			os = chars;
			Marshal::FreeHGlobal(IntPtr((void*)chars));
		}

		private: System::Void save_Click(System::Object^ sender, System::EventArgs^ e) 
		{
			savebutton->Enabled = false;			
			SaveFileDialog^ saveFileDialog = gcnew SaveFileDialog();
			saveFileDialog->Filter = "All supported graphics|*.jpg;*.jpeg;|" +
				"JPEG (*.jpg;*.jpeg)|*.jpg;*.jpeg";
			if (saveFileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK)
			{
				std::string filename;
				MarshalString(saveFileDialog->FileName, filename);
				imwrite(filename, *pframe);
				MessageBox::Show("File saved", "Success !", MessageBoxButtons::OK);
				capturepicturebox->Image = nullptr;
			}
			else 
			{
				savebutton->Enabled = true;
			}
		}
	};
}
