#pragma once
#include "Tracker.h"




class SortingAlgorithm
{
public:
	void virtual Sort(char* data, short size) = 0;
	Tracker States;

};


class BubbleSort :public SortingAlgorithm
{
public:
	void Sort(char* data, short size);
};

class CoctailSort :public SortingAlgorithm
{
public:
	void Sort(char* data, short size);
};


class CombSort :public SortingAlgorithm
{
public:
	void Sort(char* data, short size);
};

class SelectionSort :public SortingAlgorithm
{
public:
	void Sort(char* data, short size);
};

class InsertionSort :public SortingAlgorithm
{
public:
	void Sort(char* data, short size);
};

class ShellSort :public SortingAlgorithm
{
public:
	void Sort(char* data, short size);
};

class QuickSort :public SortingAlgorithm
{
public:
	void Sort(char* data, short size);
private:
	void RecursiveSort(char* data, short size, short begin, short end);
};

class TreeSort :public SortingAlgorithm
{
public:
	void Sort(char* data, short size);
};

class HeapSort :public SortingAlgorithm
{
public:
	void Sort(char* data, short size);
private:
	void SiftDown(char* data, short size, short begin, short end);
};

class MergeSort :public SortingAlgorithm
{
public:
	void Sort(char* data, short size);
private:
	void RecursiveSort(char* data, short size, short begin, short end);
};

class Sorter
{
public:
	Sorter(SortingAlgorithm* alg);
	~Sorter();
	void SortData(char* data, short size);
	SortingAlgorithm * Algorithm;
	void ChangeAlgorithm(SortingAlgorithm* alg);
};





