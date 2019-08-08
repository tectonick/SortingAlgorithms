#include "MainForm.h"
using namespace SortingTest;

using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
int Main(array<String^>^ args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	MainForm form;
	Application::Run(% form);
	return 0;
}

