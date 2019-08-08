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


class SelectionSort :public SortingAlgorithm
{
public:
	void Sort(int* data, int size);
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





