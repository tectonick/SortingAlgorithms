#pragma once
#include "SortingAlgorithms.h"
#include "Drawer.h"


namespace SortingTest {

	const int TESTSIZE = 21;
	const int testarraytemplate[TESTSIZE] = { 4,1,6,2,2,35,11,1,3,8,22,12,45,67,21,4,56,100,2,8 ,82};
	int testarray[TESTSIZE] = { 4,1,6,2,2,35,11,1,3,8,22,12,45,67,21,4,56,100,2,8 ,82};


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
	private: System::Windows::Forms::ComboBox^ comboBox1;
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
			d->DrawArray(testarray, TESTSIZE);
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
	private: System::Windows::Forms::Button^ button2;
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
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea3 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^ legend3 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^ series3 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->chart1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->trackBar1 = (gcnew System::Windows::Forms::TrackBar());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar1))->BeginInit();
			this->SuspendLayout();
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(25, 35);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(389, 20);
			this->textBox1->TabIndex = 0;
			this->textBox1->Text = L"Array ";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(262, 189);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 1;
			this->button1->Text = L"Sort";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MainForm::Button1_Click);
			// 
			// chart1
			// 
			chartArea3->Name = L"ChartArea1";
			this->chart1->ChartAreas->Add(chartArea3);
			legend3->Name = L"Legend1";
			this->chart1->Legends->Add(legend3);
			this->chart1->Location = System::Drawing::Point(468, 1);
			this->chart1->Name = L"chart1";
			series3->ChartArea = L"ChartArea1";
			series3->Legend = L"Legend1";
			series3->Name = L"Series1";
			this->chart1->Series->Add(series3);
			this->chart1->Size = System::Drawing::Size(719, 417);
			this->chart1->TabIndex = 2;
			this->chart1->Text = L"chart1";
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(303, 274);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 3;
			this->button2->Text = L"Show";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MainForm::Button2_Click);
			// 
			// trackBar1
			// 
			this->trackBar1->Location = System::Drawing::Point(468, 425);
			this->trackBar1->Maximum = 20;
			this->trackBar1->Name = L"trackBar1";
			this->trackBar1->Size = System::Drawing::Size(719, 45);
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
			this->comboBox1->Location = System::Drawing::Point(78, 191);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(178, 21);
			this->comboBox1->TabIndex = 6;
			this->comboBox1->Text = L"Choose sorting algorithm";
			this->comboBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &MainForm::ComboBox1_SelectedIndexChanged);
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1232, 512);
			this->Controls->Add(this->comboBox1);
			this->Controls->Add(this->trackBar1);
			this->Controls->Add(this->button2);
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
		for (size_t i = 0; i < TESTSIZE; i++)
		{
			testarray[i] = testarraytemplate[i];
		}
		s->SortData(testarray, TESTSIZE);
		for (int i = 0; i < TESTSIZE; i++)
		{
			textBox1->Text += testarray[i];
			textBox1->Text += " ";
		}
		trackBar1->Value = 0;
		trackBar1->Maximum = s->Algorithm->States.StatesCount()-1;
		
		
	}

	


	private: System::Void Button2_Click(System::Object^ sender, System::EventArgs^ e) {
		
		d->DrawArray(testarray, TESTSIZE);
	}
	private: System::Void TrackBar1_Scroll(System::Object^ sender, System::EventArgs^ e) {
		d->DrawArray(s->Algorithm->States.GetState(trackBar1->Value), TESTSIZE);
		
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
};

	
}
