#include "SortingAlgorithms.h"


void swap(int* a, int* b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

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
				swap(&data[i], &data[i+1]);
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
		swap(&data[indexOfMin], &data[i]);
	}
}

void InsertionSort::Sort(int* data, int size)
{
	for (size_t i = 1; i < size; i++)
	{
		int current = data[i];
		for (int j = i-1; j >= 0; j--)
		{			
			if (current <data[j])
			{
				data[j + 1] = data[j];
			}
			else
			{
				data[j+1] = current;
				break;
			}
		}
		
	}
}

void QuickSort::Sort(int* data, int size)
{
	RecursiveSort(data, 0, size);
}

void QuickSort::RecursiveSort(int* data, int begin, int end)
{
	
	if (end>begin)
	{	
		int center = (begin + end) / 2;
		int i = begin-1;
		int j = end+1;
		while (true)
		{
			do
			{
				i++;
			} while (data[i] < data[center]);

			do
			{
				j--;
			} while (data[j] > data[center]);

			if (i>=j)
			{
				break;
			}
			swap(&data[i], &data[j]);
		}

		RecursiveSort(data, begin, center - 1);
		RecursiveSort(data, center + 1, end);
	}
	
}
