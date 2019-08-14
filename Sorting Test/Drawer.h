#pragma once

using namespace System::Windows::Forms::DataVisualization::Charting;

public ref class Drawer
{
public:
	Drawer(Chart^ chart):Chart(chart) {}
	~Drawer();
	void DrawArray(char* data, int size);

private:
	Chart^ Chart;
};




