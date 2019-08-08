#pragma once
#include <vector>

using std::vector;


class StateKeeper
{
public:
	vector<short*> * States;
	void SaveCurrentState(short* data, short size);
	short* GetState(short i);
	void ClearStates();
	short StatesCount();
	StateKeeper();
	~StateKeeper();
};

class SortingAlgorithm
{
public:
	void virtual Sort(short* data, short size) = 0;
	StateKeeper States;
};


class BubbleSort :public SortingAlgorithm
{
public:
	void Sort(short * data, short size);
};

class CoctailSort :public SortingAlgorithm
{
public:
	void Sort(short* data, short size);
};


class CombSort :public SortingAlgorithm
{
public:
	void Sort(short* data, short size);
};

class SelectionSort :public SortingAlgorithm
{
public:
	void Sort(short* data, short size);
};

class InsertionSort :public SortingAlgorithm
{
public:
	void Sort(short* data, short size);
};

class ShellSort :public SortingAlgorithm
{
public:
	void Sort(short* data, short size);
};

class QuickSort :public SortingAlgorithm
{
public:
	void Sort(short* data, short size);
private:
	void RecursiveSort(short* data, short size, short begin, short end);
};

class TreeSort :public SortingAlgorithm
{
public:
	void Sort(short* data, short size);
};

class HeapSort :public SortingAlgorithm
{
public:
	void Sort(short* data, short size);
private:
	void SiftDown(short* data, short size, short begin, short end);
};

class MergeSort :public SortingAlgorithm
{
public:
	void Sort(short* data, short size);
private:
	void RecursiveSort(short* data, short size, short begin, short end);
};

class Sorter
{
public:
	Sorter(SortingAlgorithm* alg);
	~Sorter();
	void SortData(short * data, short size);
	SortingAlgorithm * Algorithm;
	void ChangeAlgorithm(SortingAlgorithm* alg);
};





