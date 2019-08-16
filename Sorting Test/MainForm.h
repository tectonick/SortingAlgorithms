#pragma once
#include "SortingAlgorithms.h"
#include "Drawer.h"
#include <String>
#include <sstream>


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
	private: System::Windows::Forms::ComboBox^ AlgorithmComboBox;
	private: System::Windows::Forms::Button^ GenerateArrayButton;
	private: System::Windows::Forms::TextBox^ ArrayLengthBox;
	private: System::Windows::Forms::Label^ CountLabel;
	private: System::Windows::Forms::TextBox^ OutputTextBox;
	private: System::Windows::Forms::Label^ ArrayLengthLabel;
	private: System::Windows::Forms::Label^ SortingAlgorithmLabel;
	private: System::Windows::Forms::FlowLayoutPanel^ flowLayoutPanel1;
	private: System::Windows::Forms::Label^ StatesCountLabel;
	private: System::Windows::Forms::Label^ InputArrayLabel;
	private: System::Windows::Forms::Label^ OutpuLabel;
	private: System::Windows::Forms::FlowLayoutPanel^ flowLayoutPanel2;
	private: System::Windows::Forms::FlowLayoutPanel^ flowLayoutPanel3;
	private: System::Windows::Forms::Label^ VisualizationLabel;
	private: System::Windows::Forms::TextBox^ InputTextBox;
	private: System::Windows::Forms::Button^ SortButton;
	private: System::Windows::Forms::DataVisualization::Charting::Chart^ StatesGraph;
	private: System::Windows::Forms::TrackBar^ StatesTrackBar;

	public:
		Sorter* MySorter; 
		int ArraySize;
		char* ResultArray;
		Drawer^ MyDrawer; // Object for visualizing changing states of array
		MainForm(void)
		{
			InitializeComponent();

			MySorter = new Sorter(new BubbleSort()); //Initialize Sorter with BubbleSort algorithm by default
			MyDrawer = gcnew Drawer(StatesGraph); //Initialize Sorter with StatesGraph component to draw
		}

	protected:
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}


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
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea1 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Series^ series1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			this->InputTextBox = (gcnew System::Windows::Forms::TextBox());
			this->SortButton = (gcnew System::Windows::Forms::Button());
			this->StatesGraph = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->StatesTrackBar = (gcnew System::Windows::Forms::TrackBar());
			this->AlgorithmComboBox = (gcnew System::Windows::Forms::ComboBox());
			this->GenerateArrayButton = (gcnew System::Windows::Forms::Button());
			this->ArrayLengthBox = (gcnew System::Windows::Forms::TextBox());
			this->CountLabel = (gcnew System::Windows::Forms::Label());
			this->OutputTextBox = (gcnew System::Windows::Forms::TextBox());
			this->ArrayLengthLabel = (gcnew System::Windows::Forms::Label());
			this->SortingAlgorithmLabel = (gcnew System::Windows::Forms::Label());
			this->flowLayoutPanel1 = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->InputArrayLabel = (gcnew System::Windows::Forms::Label());
			this->OutpuLabel = (gcnew System::Windows::Forms::Label());
			this->StatesCountLabel = (gcnew System::Windows::Forms::Label());
			this->flowLayoutPanel2 = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->flowLayoutPanel3 = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->VisualizationLabel = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->StatesGraph))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->StatesTrackBar))->BeginInit();
			this->flowLayoutPanel1->SuspendLayout();
			this->flowLayoutPanel2->SuspendLayout();
			this->flowLayoutPanel3->SuspendLayout();
			this->SuspendLayout();
			// 
			// InputTextBox
			// 
			this->InputTextBox->Location = System::Drawing::Point(3, 16);
			this->InputTextBox->MaxLength = 500000;
			this->InputTextBox->Multiline = true;
			this->InputTextBox->Name = L"InputTextBox";
			this->InputTextBox->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->InputTextBox->Size = System::Drawing::Size(389, 175);
			this->InputTextBox->TabIndex = 0;
			// 
			// SortButton
			// 
			this->SortButton->Location = System::Drawing::Point(3, 400);
			this->SortButton->Name = L"SortButton";
			this->SortButton->Size = System::Drawing::Size(200, 23);
			this->SortButton->TabIndex = 1;
			this->SortButton->Text = L"Sort";
			this->SortButton->UseVisualStyleBackColor = true;
			this->SortButton->Click += gcnew System::EventHandler(this, &MainForm::SortButton_Click);
			// 
			// StatesGraph
			// 
			this->StatesGraph->BorderlineColor = System::Drawing::Color::Gray;
			this->StatesGraph->BorderlineDashStyle = System::Windows::Forms::DataVisualization::Charting::ChartDashStyle::Solid;
			chartArea1->Name = L"ChartArea1";
			this->StatesGraph->ChartAreas->Add(chartArea1);
			this->StatesGraph->Location = System::Drawing::Point(3, 16);
			this->StatesGraph->Name = L"StatesGraph";
			series1->ChartArea = L"ChartArea1";
			series1->Name = L"Series1";
			this->StatesGraph->Series->Add(series1);
			this->StatesGraph->Size = System::Drawing::Size(708, 378);
			this->StatesGraph->TabIndex = 2;
			this->StatesGraph->Text = L"chart1";
			// 
			// StatesTrackBar
			// 
			this->StatesTrackBar->Location = System::Drawing::Point(3, 16);
			this->StatesTrackBar->Maximum = 0;
			this->StatesTrackBar->Name = L"StatesTrackBar";
			this->StatesTrackBar->Size = System::Drawing::Size(711, 45);
			this->StatesTrackBar->TabIndex = 5;
			this->StatesTrackBar->Scroll += gcnew System::EventHandler(this, &MainForm::StatesTrackBar_Scroll);
			// 
			// AlgorithmComboBox
			// 
			this->AlgorithmComboBox->AllowDrop = true;
			this->AlgorithmComboBox->FormattingEnabled = true;
			this->AlgorithmComboBox->Items->AddRange(gcnew cli::array< System::Object^  >(10) {
				L"Bubble", L"Coctail", L"Comb", L"Heap",
					L"Insertion", L"Merge", L"Quick", L"Selection", L"Shell", L"Tree"
			});
			this->AlgorithmComboBox->Location = System::Drawing::Point(94, 430);
			this->AlgorithmComboBox->Name = L"AlgorithmComboBox";
			this->AlgorithmComboBox->Size = System::Drawing::Size(109, 21);
			this->AlgorithmComboBox->TabIndex = 6;
			this->AlgorithmComboBox->Text = L"Bubble";
			this->AlgorithmComboBox->SelectedIndexChanged += gcnew System::EventHandler(this, &MainForm::AlgorithmComboBox_SelectedIndexChanged);
			// 
			// GenerateArrayButton
			// 
			this->GenerateArrayButton->Location = System::Drawing::Point(209, 400);
			this->GenerateArrayButton->Name = L"GenerateArrayButton";
			this->GenerateArrayButton->Size = System::Drawing::Size(166, 24);
			this->GenerateArrayButton->TabIndex = 7;
			this->GenerateArrayButton->Text = L"Generate random array";
			this->GenerateArrayButton->UseVisualStyleBackColor = true;
			this->GenerateArrayButton->Click += gcnew System::EventHandler(this, &MainForm::GenerateArrayButton_Click);
			// 
			// ArrayLengthBox
			// 
			this->ArrayLengthBox->Location = System::Drawing::Point(278, 430);
			this->ArrayLengthBox->Name = L"ArrayLengthBox";
			this->ArrayLengthBox->Size = System::Drawing::Size(97, 20);
			this->ArrayLengthBox->TabIndex = 8;
			this->ArrayLengthBox->Text = L"20";
			// 
			// CountLabel
			// 
			this->CountLabel->AutoSize = true;
			this->CountLabel->Location = System::Drawing::Point(76, 0);
			this->CountLabel->Name = L"CountLabel";
			this->CountLabel->Size = System::Drawing::Size(13, 13);
			this->CountLabel->TabIndex = 9;
			this->CountLabel->Text = L"0";
			this->CountLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// OutputTextBox
			// 
			this->OutputTextBox->BackColor = System::Drawing::SystemColors::Window;
			this->OutputTextBox->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->OutputTextBox->Location = System::Drawing::Point(3, 210);
			this->OutputTextBox->Multiline = true;
			this->OutputTextBox->Name = L"OutputTextBox";
			this->OutputTextBox->ReadOnly = true;
			this->OutputTextBox->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->OutputTextBox->Size = System::Drawing::Size(389, 184);
			this->OutputTextBox->TabIndex = 10;
			// 
			// ArrayLengthLabel
			// 
			this->ArrayLengthLabel->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->ArrayLengthLabel->AutoSize = true;
			this->ArrayLengthLabel->Location = System::Drawing::Point(209, 427);
			this->ArrayLengthLabel->Name = L"ArrayLengthLabel";
			this->ArrayLengthLabel->Size = System::Drawing::Size(63, 27);
			this->ArrayLengthLabel->TabIndex = 11;
			this->ArrayLengthLabel->Text = L"Array length";
			// 
			// SortingAlgorithmLabel
			// 
			this->SortingAlgorithmLabel->AutoSize = true;
			this->SortingAlgorithmLabel->Location = System::Drawing::Point(3, 427);
			this->SortingAlgorithmLabel->Name = L"SortingAlgorithmLabel";
			this->SortingAlgorithmLabel->Size = System::Drawing::Size(85, 13);
			this->SortingAlgorithmLabel->TabIndex = 12;
			this->SortingAlgorithmLabel->Text = L"Sorting algorithm";
			// 
			// flowLayoutPanel1
			// 
			this->flowLayoutPanel1->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->flowLayoutPanel1->Controls->Add(this->InputArrayLabel);
			this->flowLayoutPanel1->Controls->Add(this->InputTextBox);
			this->flowLayoutPanel1->Controls->Add(this->OutpuLabel);
			this->flowLayoutPanel1->Controls->Add(this->OutputTextBox);
			this->flowLayoutPanel1->Controls->Add(this->SortButton);
			this->flowLayoutPanel1->Controls->Add(this->GenerateArrayButton);
			this->flowLayoutPanel1->Controls->Add(this->SortingAlgorithmLabel);
			this->flowLayoutPanel1->Controls->Add(this->AlgorithmComboBox);
			this->flowLayoutPanel1->Controls->Add(this->ArrayLengthLabel);
			this->flowLayoutPanel1->Controls->Add(this->ArrayLengthBox);
			this->flowLayoutPanel1->Location = System::Drawing::Point(0, 2);
			this->flowLayoutPanel1->Name = L"flowLayoutPanel1";
			this->flowLayoutPanel1->Size = System::Drawing::Size(392, 477);
			this->flowLayoutPanel1->TabIndex = 14;
			// 
			// InputArrayLabel
			// 
			this->InputArrayLabel->AutoSize = true;
			this->InputArrayLabel->Location = System::Drawing::Point(3, 0);
			this->InputArrayLabel->Name = L"InputArrayLabel";
			this->InputArrayLabel->Size = System::Drawing::Size(57, 13);
			this->InputArrayLabel->TabIndex = 16;
			this->InputArrayLabel->Text = L"Input array";
			// 
			// OutpuLabel
			// 
			this->OutpuLabel->AutoSize = true;
			this->OutpuLabel->Location = System::Drawing::Point(3, 194);
			this->OutpuLabel->Name = L"OutpuLabel";
			this->OutpuLabel->Size = System::Drawing::Size(65, 13);
			this->OutpuLabel->TabIndex = 17;
			this->OutpuLabel->Text = L"Output array";
			// 
			// StatesCountLabel
			// 
			this->StatesCountLabel->AutoSize = true;
			this->StatesCountLabel->Location = System::Drawing::Point(3, 0);
			this->StatesCountLabel->Name = L"StatesCountLabel";
			this->StatesCountLabel->Size = System::Drawing::Size(67, 13);
			this->StatesCountLabel->TabIndex = 15;
			this->StatesCountLabel->Text = L"States count";
			// 
			// flowLayoutPanel2
			// 
			this->flowLayoutPanel2->Controls->Add(this->StatesCountLabel);
			this->flowLayoutPanel2->Controls->Add(this->CountLabel);
			this->flowLayoutPanel2->Controls->Add(this->StatesTrackBar);
			this->flowLayoutPanel2->Location = System::Drawing::Point(3, 400);
			this->flowLayoutPanel2->Name = L"flowLayoutPanel2";
			this->flowLayoutPanel2->Size = System::Drawing::Size(714, 61);
			this->flowLayoutPanel2->TabIndex = 16;
			// 
			// flowLayoutPanel3
			// 
			this->flowLayoutPanel3->Controls->Add(this->VisualizationLabel);
			this->flowLayoutPanel3->Controls->Add(this->StatesGraph);
			this->flowLayoutPanel3->Controls->Add(this->flowLayoutPanel2);
			this->flowLayoutPanel3->Location = System::Drawing::Point(401, 2);
			this->flowLayoutPanel3->Name = L"flowLayoutPanel3";
			this->flowLayoutPanel3->Size = System::Drawing::Size(716, 477);
			this->flowLayoutPanel3->TabIndex = 17;
			// 
			// VisualizationLabel
			// 
			this->VisualizationLabel->AutoSize = true;
			this->VisualizationLabel->Location = System::Drawing::Point(3, 0);
			this->VisualizationLabel->Name = L"VisualizationLabel";
			this->VisualizationLabel->Size = System::Drawing::Size(65, 13);
			this->VisualizationLabel->TabIndex = 18;
			this->VisualizationLabel->Text = L"Visualization";
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1117, 474);
			this->Controls->Add(this->flowLayoutPanel3);
			this->Controls->Add(this->flowLayoutPanel1);
			this->Name = L"MainForm";
			this->Text = L"Sorting Tester";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->StatesGraph))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->StatesTrackBar))->EndInit();
			this->flowLayoutPanel1->ResumeLayout(false);
			this->flowLayoutPanel1->PerformLayout();
			this->flowLayoutPanel2->ResumeLayout(false);
			this->flowLayoutPanel2->PerformLayout();
			this->flowLayoutPanel3->ResumeLayout(false);
			this->flowLayoutPanel3->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion

	private: System::Void SortButton_Click(System::Object^ sender, System::EventArgs^ e) {
		//Getting data from inputbox
		OutputTextBox->Clear();
		if (InputTextBox->Text->Length == 0)
		{
			OutputTextBox->Text = "Nothing to sort";
			return;
		}
		array<String^>^ nums = InputTextBox->Text->Split(gcnew array<wchar_t> {' ', ','});

		//Parsing string data to ints
		System::Collections::Generic::List<char>^ ints = gcnew System::Collections::Generic::List<char>();
		for each (String ^ MySorter in nums)
		{
			int ParseResult;
			if (System::Int32::TryParse(MySorter, ParseResult))
			{
				ints->Add(ParseResult);
			}
		}
		if (ints->Count == 0)
		{
			OutputTextBox->Text = "Haven`t found any numbers";
			return;
		}

		//Preparing an array to sort
		ArraySize = ints->Count;
		if (ResultArray)
			delete[] ResultArray;
		ResultArray = new char[ArraySize];
		for (int i = 0; i < ArraySize; i++)
		{
			ResultArray[i] = (char)ints[i];
		}

		//Sort and draw results if enabled
		MySorter->Algorithm->AlgorithmTracker.Visualizing = (ArraySize > 1000) ? false : true;
		MySorter->SortData(ResultArray, ArraySize);
		MyDrawer->DrawArray(ResultArray, ArraySize);

		//Result output
		std::string str = "";
		std::stringstream ss;
		for (size_t i = 0; i < ArraySize; i++)
		{
			ss << (short)ResultArray[i] << " ";
		}
		str = ss.str();
		OutputTextBox->Text = gcnew String(str.c_str());
		//OutputTextBox->Text += " (" + MySorter->Algorithm->AlgorithmTracker.GetTime().ToString() + " CPU cycles)";
		StatesTrackBar->Maximum = MySorter->Algorithm->AlgorithmTracker.StatesCount() - 1;
		StatesTrackBar->Value = StatesTrackBar->Maximum;
		CountLabel->Text = (ArraySize > 1000) ? "Visualization of states is disabled for arrays of size>1000" : StatesTrackBar->Value.ToString();
		CountLabel->Text += " (" + MySorter->Algorithm->AlgorithmTracker.GetTime().ToString() + " CPU cycles)";
	}


	private: System::Void StatesTrackBar_Scroll(System::Object^ sender, System::EventArgs^ e) {
		MyDrawer->DrawArray(MySorter->Algorithm->AlgorithmTracker.GetState(StatesTrackBar->Value), ArraySize);
		CountLabel->Text = StatesTrackBar->Value.ToString();

	}
	private: System::Void AlgorithmComboBox_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
		switch (AlgorithmComboBox->SelectedIndex)
		{
		case 0:MySorter->ChangeAlgorithm(new BubbleSort()); break;
		case 1:MySorter->ChangeAlgorithm(new CoctailSort()); break;
		case 2:MySorter->ChangeAlgorithm(new CombSort()); break;
		case 3:MySorter->ChangeAlgorithm(new HeapSort()); break;
		case 4:MySorter->ChangeAlgorithm(new InsertionSort()); break;
		case 5:MySorter->ChangeAlgorithm(new MergeSort()); break;
		case 6:MySorter->ChangeAlgorithm(new QuickSort()); break;
		case 7:MySorter->ChangeAlgorithm(new SelectionSort()); break;
		case 8:MySorter->ChangeAlgorithm(new ShellSort()); break;
		case 9:MySorter->ChangeAlgorithm(new TreeSort()); break;
		default:
			MySorter->ChangeAlgorithm(new BubbleSort()); break;
		}

	}
	private: System::Void GenerateArrayButton_Click(System::Object^ sender, System::EventArgs^ e) {
		ArraySize = System::Int32::Parse(ArrayLengthBox->Text); //Getting size of an array from input
		InputTextBox->Clear();

		//Generating random numbers
		System::Collections::Generic::List<char>^ rands = gcnew System::Collections::Generic::List<char>(ArraySize);
		for (int i = 0; i < ArraySize; i++)
		{
			rands->Add(rand() % 100 + 1);
		}

		// Printing generated numbers to inputbox
		std::string str = "";
		std::stringstream ss;
		for (size_t i = 0; i < ArraySize; i++)
		{
			ss << (short)rands[i] << " ";
		}
		str = ss.str();
		InputTextBox->Text = gcnew String(str.c_str());
	}
	};
}
