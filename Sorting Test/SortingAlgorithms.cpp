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
		int j = i - 1;
		while ((j>=0)&&(current<data[j]))
		{
			data[j + 1] = data[j];
			j--;
		}
		data[j + 1] = current;
		
	}
}

void ShellSort::Sort(int* data, int size)
{
	int step = size/2;
	while (step > 0)
	{
		for (size_t i = 1; i < size; i++)
		{
			int current = data[i];
			int j = i - 1;
			while ((j >= 0) && (current < data[j]))
			{
				data[j + 1] = data[j];
				j--;
			}
			data[j + 1] = current;

		}
		step = step / 2;
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

void CoctailSort::Sort(int* data, int size)
{
	bool SwapHappened;
	int begin = 0;
	int end = size;
	do {
		SwapHappened = false;
		for (int i = begin; i < end - 1; i++)
		{
			if (data[i + 1] < data[i])
			{
				swap(&data[i], &data[i + 1]);
				SwapHappened = true;
			}
		}
		end--;
		if (!SwapHappened)
		{
			break;
		}
		SwapHappened = false;
		for (int i = end-1; i >= 0; i--)
		{
			if (data[i + 1] < data[i])
			{
				swap(&data[i], &data[i + 1]);
				SwapHappened = true;
			}
		}
		begin++;
	} while (SwapHappened);
}

void CombSort::Sort(int* data, int size)
{
	double decreaseFactor = 1.247;
	int step = size / decreaseFactor;

	while (step>1)
	{
		for (int i = 0; i < size - step; i++)
		{
			if (data[i +step] < data[i])
			{
				swap(&data[i], &data[i + step]);
			}
		}
		step = step / decreaseFactor;
	}
	
	bool SwapHappened;
	do {
		SwapHappened = false;
		for (int i = 0; i < size - 1; i++)
		{
			if (data[i + 1] < data[i])
			{
				swap(&data[i], &data[i + 1]);
				SwapHappened = true;
			}
		}
	} while (SwapHappened);

}

