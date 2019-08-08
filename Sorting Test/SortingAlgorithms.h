#pragma once


class SortingAlgorithm
{
public:
	void virtual Sort(int* data, int size) = 0;
};

class BubbleSort :public SortingAlgorithm
{
public:
	void Sort(int * data, int size);
};

class CoctailSort :public SortingAlgorithm
{
public:
	void Sort(int* data, int size);
};


class CombSort :public SortingAlgorithm
{
public:
	void Sort(int* data, int size);
};

class SelectionSort :public SortingAlgorithm
{
public:
	void Sort(int* data, int size);
};

class InsertionSort :public SortingAlgorithm
{
public:
	void Sort(int* data, int size);
};

class ShellSort :public SortingAlgorithm
{
public:
	void Sort(int* data, int size);
};

class QuickSort :public SortingAlgorithm
{
public:
	void Sort(int* data, int size);
private:
	void RecursiveSort(int* data,int begin, int end);
};

class TreeSort :public SortingAlgorithm
{
public:
	void Sort(int* data, int size);
};

class HeapSort :public SortingAlgorithm
{
public:
	void Sort(int* data, int size);
private:
	void SiftDown(int* data, int begin, int end);
};

class MergeSort :public SortingAlgorithm
{
public:
	void Sort(int* data, int size);
private:
	void RecursiveSort(int* data, int begin, int end);
};

class Sorter
{
public:
	Sorter(SortingAlgorithm* alg);
	~Sorter();
	void SortData(int * data, int size);
private:
	SortingAlgorithm * Algorithm;
};





