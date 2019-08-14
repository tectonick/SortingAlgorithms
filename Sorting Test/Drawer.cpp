#include "Drawer.h"

Drawer::~Drawer()
{
}

void Drawer::DrawArray(char* data, int size)
{
	Chart->Series[0]->Points->Clear();
	for (int i = 0; i < size; i++)
	{
		Chart->Series[0]->Points->Add(data[i]);
	}

}