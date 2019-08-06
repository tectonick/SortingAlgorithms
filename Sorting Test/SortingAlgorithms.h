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


class Sorter
{
public:
	Sorter(SortingAlgorithm* alg);
	~Sorter();
	void SortData(int * data, int size);
private:
	SortingAlgorithm * Algorithm;
};

Sorter::Sorter(SortingAlgorithm* alg):Algorithm(alg)
{
}


Sorter::~Sorter()
{
}

void Sorter::SortData(int* data, int size)
{
	Algorithm->Sort(data, size);
}




