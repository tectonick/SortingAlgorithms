#pragma once
#include "Tracker.h"




class SortingAlgorithm
{
public:
	void virtual Sort(char* data, int size) = 0;
	Tracker States;

};


class BubbleSort :public SortingAlgorithm
{
public:
	void Sort(char* data, int size);
};

class CoctailSort :public SortingAlgorithm
{
public:
	void Sort(char* data, int size);
};


class CombSort :public SortingAlgorithm
{
public:
	void Sort(char* data, int size);
};

class SelectionSort :public SortingAlgorithm
{
public:
	void Sort(char* data, int size);
};

class InsertionSort :public SortingAlgorithm
{
public:
	void Sort(char* data, int size);
};

class ShellSort :public SortingAlgorithm
{
public:
	void Sort(char* data, int size);
};

class QuickSort :public SortingAlgorithm
{
public:
	void Sort(char* data, int size);
private:
	void RecursiveSort(char* data, int size, int begin, int end);
};

class TreeSort :public SortingAlgorithm
{
public:
	void Sort(char* data, int size);
};

class HeapSort :public SortingAlgorithm
{
public:
	void Sort(char* data, int size);
private:
	void SiftDown(char* data, int size, int begin, int end);
};

class MergeSort :public SortingAlgorithm
{
public:
	void Sort(char* data, int size);
private:
	void RecursiveSort(char* data, int size, int begin, int end);
};

class Sorter
{
public:
	Sorter(SortingAlgorithm* alg);
	~Sorter();
	void SortData(char* data, int size);
	SortingAlgorithm * Algorithm;
	void ChangeAlgorithm(SortingAlgorithm* alg);
};





