#pragma once

#include <opencv2/core.hpp>
#include <opencv2/video.hpp>
#include <opencv2/highgui.hpp>

using namespace cv;

namespace Webcam {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

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
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::PictureBox^ pictureBox1;


	private: System::Windows::Forms::Button^ button3;
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
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->button3 = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(78, 9);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(259, 68);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Capture";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Webcam::button1_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->pictureBox1->Location = System::Drawing::Point(44, 94);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(328, 231);
			this->pictureBox1->TabIndex = 1;
			this->pictureBox1->TabStop = false;
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(78, 350);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(259, 68);
			this->button3->TabIndex = 4;
			this->button3->Text = L"Save to File";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Visible = false;
			this->button3->Click += gcnew System::EventHandler(this, &Webcam::button3_Click);
			// 
			// Webcam
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(415, 435);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->button1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"Webcam";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Webcam";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
		private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) 
		{			
			VideoCapture cap;
			Mat frame;

			int deviceID = 0; 
			int apiID = cv::CAP_ANY;
			cap.open(deviceID, apiID);
			if (cap.isOpened())
			{
				cap.read((frame));
				if (! frame.empty())
				{
					System::Drawing::Graphics^ graphics = pictureBox1->CreateGraphics();
					System::IntPtr ptr(frame.ptr());
					System::Drawing::Bitmap^ b = gcnew System::Drawing::Bitmap(frame.cols, frame.rows, frame.step, System::Drawing::Imaging::PixelFormat::Format24bppRgb, ptr);
					System::Drawing::RectangleF rect(0, 0, pictureBox1->Width, pictureBox1->Height);
					graphics->DrawImage(b, rect);
					
					b->Save("C:\\temp\\test.png", System::Drawing::Imaging::ImageFormat::Png);

					button3->Visible = true;
				}
			}
			else 
			{
				MessageBox::Show("Webcam error", "Error !", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
			frame.release();
			cap.release();			
		}
	private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
		/* System::Drawing::Bitmap^ bitmap = gcnew System::Drawing::Bitmap(pictureBox1->Width, pictureBox1->Height);
		System::Drawing::Graphics^ graphics = System::Drawing::Graphics::FromImage(bitmap);
		graphics->Clear(System::Drawing::Color::Transparent);
		graphics->DrawImage(pictureBox1->Image, (bitmap->Width - pictureBox1->Image->Width) / 2, (bitmap->Height - pictureBox1->Image->Height) / 2);
		bitmap->Save(L"C:\tmp\test.png", System::Drawing::Imaging::ImageFormat::Png); */
	}
};
}
