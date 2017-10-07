#pragma once
#include <vector>
#include <string>

namespace GraphCreator {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	std::vector<std::string> time, frame, gt, rt, gpu, content;
	std::string tempNormal;

	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//createArrays(time, frame, gt, rt, gpu, content,"BasicLevelOfficeAgent-FPS-Android.csv");
			clickedF = false;
			clickedG = false;
			clickedR = false;
			framerateMS = "Framerate (ms)";
			gameThreadMS = "GT";
			renderThreadMS = "RT";
			createArrays(time, frame, gt, rt, gpu, content, "test.csv");
			//
		}
		
		void getFoo(int &foo);
		void createArrays(std::vector<std::string>&, std::vector<std::string>&, std::vector<std::string>&, std::vector<std::string>&, std::vector<std::string>&, std::vector<std::string>&, std::string);
		bool drawPoints(std::vector<std::string>,bool, System::String^);

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::DataVisualization::Charting::Chart^  chart2;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Button^  button3;

	private: System::ComponentModel::IContainer^  components;
	protected:

	private:
		/// <summary>
		/// Required designer variable.
		bool clickedF;
		bool clickedR;
		bool clickedG;
		System::String^ framerateMS;
		System::String^ gameThreadMS;
		
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::Button^  button4;
	private: System::Windows::Forms::Label^  label1;
			 System::String^ renderThreadMS;
		/// </summary>




#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::Windows::Forms::DataVisualization::Charting::ChartArea^  chartArea2 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^  legend2 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^  series4 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Series^  series5 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Series^  series6 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Title^  title2 = (gcnew System::Windows::Forms::DataVisualization::Charting::Title());
			this->chart2 = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart2))->BeginInit();
			this->SuspendLayout();
			// 
			// chart2
			// 
			chartArea2->Name = L"ChartArea2";
			this->chart2->ChartAreas->Add(chartArea2);
			legend2->Name = L"Legend1";
			this->chart2->Legends->Add(legend2);
			this->chart2->Location = System::Drawing::Point(2, 49);
			this->chart2->Name = L"chart2";
			series4->ChartArea = L"ChartArea2";
			series4->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Line;
			series4->Legend = L"Legend1";
			series4->Name = L"GT";
			series5->ChartArea = L"ChartArea2";
			series5->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Line;
			series5->Legend = L"Legend1";
			series5->Name = L"RT";
			series6->ChartArea = L"ChartArea2";
			series6->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Line;
			series6->Legend = L"Legend1";
			series6->Name = L"Framerate (ms)";
			this->chart2->Series->Add(series4);
			this->chart2->Series->Add(series5);
			this->chart2->Series->Add(series6);
			this->chart2->Size = System::Drawing::Size(1339, 615);
			this->chart2->TabIndex = 1;
			this->chart2->Text = L"chart2";
			title2->Name = L"Title1";
			title2->Text = L"Agent Graph";
			this->chart2->Titles->Add(title2);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(1196, 281);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(97, 49);
			this->button1->TabIndex = 2;
			this->button1->Text = L"Load ALL";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(1196, 336);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(97, 49);
			this->button2->TabIndex = 3;
			this->button2->Text = L"GT";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click_1);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(1196, 391);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(97, 49);
			this->button3->TabIndex = 4;
			this->button3->Text = L"RT";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(529, 12);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(223, 20);
			this->textBox1->TabIndex = 5;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox1_TextChanged);
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(790, 5);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(83, 33);
			this->button4->TabIndex = 6;
			this->button4->Text = L"Load CSV";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &MyForm::button4_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::SystemColors::MenuHighlight;
			this->label1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->label1->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->label1->Location = System::Drawing::Point(726, 67);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(67, 15);
			this->label1->TabIndex = 7;
			this->label1->Text = L"Default CSV";
			
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1434, 664);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->chart2);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart2))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		
		clickedF=drawPoints(frame, clickedF, framerateMS);	
	}

	
	private: System::Void button2_Click_1(System::Object^  sender, System::EventArgs^  e) {
		
		clickedG = drawPoints(gt, clickedG, gameThreadMS);
		
	}

	private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
		
		clickedR = drawPoints(rt, clickedR, renderThreadMS);
		
	}

	private: System::Void textBox1_TextChanged(System::Object^  sender, System::EventArgs^  e) {
		System::String^ temp;
		
		temp=this->textBox1->Text; 
		
		//change System string to std string
		using namespace Runtime::InteropServices;
		const char* chars =
			(const char*)(Marshal::StringToHGlobalAnsi(temp)).ToPointer();
		tempNormal = chars;
		Marshal::FreeHGlobal(IntPtr((void*)chars));
		

		
	}
	private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) {
		//set label name
		this->label1->Text = this->textBox1->Text;
		//clear arrays
		time.clear();
		frame.clear();
		gt.clear();
		rt.clear();
		gpu.clear();
		content.clear();
		//re create from new loaded csv
		createArrays(time, frame, gt, rt, gpu, content, tempNormal);
		//redraw
		if(clickedF)
			clickedF = drawPoints(frame, clickedF, framerateMS);
		if (clickedG)
			clickedG = drawPoints(gt, clickedG, gameThreadMS);
		if (clickedR)
			clickedR = drawPoints(rt, clickedR, renderThreadMS);
	}

};
}
