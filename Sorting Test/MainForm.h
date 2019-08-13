#pragma once
#include "SortingAlgorithms.h"
#include "Drawer.h"


namespace SortingTest {



	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace DataVisualization::Charting;



	/// <summary>
	/// Summary for MainForm
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{
	public:
		Sorter* s;

		short ArraySize;
		short*TestArray;
		short*ResultArray;

	private: System::Windows::Forms::ComboBox^ comboBox1;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::Label^ label2;
	public:
		Drawer^ d;
		MainForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//

			s = new Sorter(new BubbleSort());
			d = gcnew Drawer(chart1);
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^ textBox1;
	protected:
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::DataVisualization::Charting::Chart^ chart1;

	private: System::Windows::Forms::TrackBar^ trackBar1;

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
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea1 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^ legend1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^ series1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->chart1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->trackBar1 = (gcnew System::Windows::Forms::TrackBar());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar1))->BeginInit();
			this->SuspendLayout();
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(25, 35);
			this->textBox1->Multiline = true;
			this->textBox1->Name = L"textBox1";
			this->textBox1->ScrollBars = System::Windows::Forms::ScrollBars::Horizontal;
			this->textBox1->Size = System::Drawing::Size(389, 133);
			this->textBox1->TabIndex = 0;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(468, 476);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 1;
			this->button1->Text = L"Sort";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MainForm::Button1_Click);
			// 
			// chart1
			// 
			chartArea1->Name = L"ChartArea1";
			this->chart1->ChartAreas->Add(chartArea1);
			legend1->Name = L"Legend1";
			this->chart1->Legends->Add(legend1);
			this->chart1->Location = System::Drawing::Point(468, 1);
			this->chart1->Name = L"chart1";
			series1->ChartArea = L"ChartArea1";
			series1->Legend = L"Legend1";
			series1->Name = L"Series1";
			this->chart1->Series->Add(series1);
			this->chart1->Size = System::Drawing::Size(719, 417);
			this->chart1->TabIndex = 2;
			this->chart1->Text = L"chart1";
			// 
			// trackBar1
			// 
			this->trackBar1->Location = System::Drawing::Point(468, 425);
			this->trackBar1->Maximum = 20;
			this->trackBar1->Name = L"trackBar1";
			this->trackBar1->Size = System::Drawing::Size(674, 45);
			this->trackBar1->TabIndex = 5;
			this->trackBar1->Scroll += gcnew System::EventHandler(this, &MainForm::TrackBar1_Scroll);
			// 
			// comboBox1
			// 
			this->comboBox1->AllowDrop = true;
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(10) {
				L"Bubble", L"Coctail", L"Comb", L"Heap", L"Insertion",
					L"Merge", L"Quick", L"Selection", L"Shell", L"Tree"
			});
			this->comboBox1->Location = System::Drawing::Point(574, 476);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(178, 21);
			this->comboBox1->TabIndex = 6;
			this->comboBox1->Text = L"Choose sorting algorithm";
			this->comboBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &MainForm::ComboBox1_SelectedIndexChanged);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(280, 184);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(134, 23);
			this->button3->TabIndex = 7;
			this->button3->Text = L"Generate random array";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MainForm::Button3_Click);
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(346, 213);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(68, 20);
			this->textBox2->TabIndex = 8;
			this->textBox2->Text = L"20";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(1149, 436);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(35, 13);
			this->label1->TabIndex = 9;
			this->label1->Text = L"Count";
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(25, 362);
			this->textBox3->Multiline = true;
			this->textBox3->Name = L"textBox3";
			this->textBox3->ScrollBars = System::Windows::Forms::ScrollBars::Horizontal;
			this->textBox3->Size = System::Drawing::Size(397, 114);
			this->textBox3->TabIndex = 10;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(277, 216);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(63, 13);
			this->label2->TabIndex = 11;
			this->label2->Text = L"Array length";
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1232, 512);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->comboBox1);
			this->Controls->Add(this->trackBar1);
			this->Controls->Add(this->chart1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox1);
			this->Name = L"MainForm";
			this->Text = L"MainForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	
	

	private: System::Void Button1_Click(System::Object^ sender, System::EventArgs^ e) {

		array<String^> ^ nums=textBox1->Text->Split(gcnew array<wchar_t> {' ', ','});
		System::Collections::ArrayList ^ ints = gcnew System::Collections::ArrayList();
		for each (String ^ s in nums)
		{
			short ParseResult;
			if (System::Int16::TryParse(s, ParseResult))
			{
				ints->Add(ParseResult);
			}		
			
		}
		ArraySize = ints->Count;
		if (ResultArray)
			delete[] ResultArray;
		ResultArray = new short[ArraySize];
		for (int i = 0; i < ArraySize; i++)
		{
			ResultArray[i] = (short) ints[i];
		}
		s->SortData(ResultArray, ArraySize);
		d->DrawArray(ResultArray, ArraySize);
		textBox3->Clear();
		for (int i = 0; i < ArraySize; i++)
		{
			textBox3->Text += ResultArray[i];
			textBox3->Text += " ";
		}
		
		trackBar1->Maximum = s->Algorithm->States.StatesCount()-1;
		trackBar1->Value = trackBar1->Maximum;
		label1->Text = trackBar1->Value.ToString();
		
		
	}

	


	private: System::Void Button2_Click(System::Object^ sender, System::EventArgs^ e) {
		
		d->DrawArray(ResultArray, ArraySize);
	}
	private: System::Void TrackBar1_Scroll(System::Object^ sender, System::EventArgs^ e) {
		d->DrawArray(s->Algorithm->States.GetState(trackBar1->Value), ArraySize);
		label1->Text = trackBar1->Value.ToString();
		
	}
private: System::Void ComboBox1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
	switch (comboBox1->SelectedIndex)
	{
	case 0:s->ChangeAlgorithm(new BubbleSort()); break;
	case 1:s->ChangeAlgorithm(new CoctailSort()); break;
	case 2:s->ChangeAlgorithm(new CombSort()); break;
	case 3:s->ChangeAlgorithm(new HeapSort()); break;
	case 4:s->ChangeAlgorithm(new InsertionSort()); break;
	case 5:s->ChangeAlgorithm(new MergeSort()); break;
	case 6:s->ChangeAlgorithm(new QuickSort()); break;
	case 7:s->ChangeAlgorithm(new SelectionSort()); break;
	case 8:s->ChangeAlgorithm(new ShellSort()); break;
	case 9:s->ChangeAlgorithm(new TreeSort()); break;
	default:
		s->ChangeAlgorithm(new BubbleSort()); break;
	}
	
}
private: System::Void Button3_Click(System::Object^ sender, System::EventArgs^ e) {
	ArraySize=System::Int32::Parse(textBox2->Text);
	textBox1->Clear();
	for (int i = 0; i < ArraySize; i++)
	{
		textBox1->Text += rand() % 100 + 1;
		textBox1->Text += " ";
	}
}
};

	
}
