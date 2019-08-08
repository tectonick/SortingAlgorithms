#include "SortingAlgorithms.h"


Sorter::Sorter(SortingAlgorithm* alg) :Algorithm(alg)
{
}


Sorter::~Sorter()
{
}

void Sorter::SortData(int* data, int size)
{
	Algorithm->Sort(data, size);
}


void BubbleSort::Sort(int* data, int size)
{
	bool SwapHappened;
	do {
		SwapHappened = false;
		for (int i = 0; i < size - 1; i++)
		{
			int tmp;
			if (data[i + 1] < data[i])
			{
				tmp = data[i + 1];
				data[i + 1] = data[i];
				data[i] = tmp;
				SwapHappened = true;
			}
		}
	} while (SwapHappened);
}

void SelectionSort::Sort(int* data, int size)
{
	for (size_t i = 0; i < size; i++)
	{
		int indexOfMin = i;
		for (size_t j = i; j < size; j++)
		{
			if (data[j]<data[indexOfMin])
			{
				indexOfMin = j;
			}
		}

		int tmp=data[indexOfMin];
		data[indexOfMin] = data[i];
		data[i] = tmp;
	}
}
