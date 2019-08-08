#include "Drawer.h"

Drawer::~Drawer()
{
}

void Drawer::DrawArray(int* data, int size)
{
	Chart->Series[0]->Points->Clear();
	for (size_t i = 0; i < size; i++)
	{
		Chart->Series[0]->Points->Add(data[i]);
	}

}