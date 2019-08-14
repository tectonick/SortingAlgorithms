#include "SortingAlgorithms.h"

void swap(char* a, char* b) {
	char tmp = *a;
	*a = *b;
	*b = tmp;
}

class BinaryTree
{
public:
	BinaryTree();
	~BinaryTree();
	void AddNode(char key);
	void Linearize(char* result);
private:
	int Size;
	
	struct Node
	{
		Node * left, * right; 
		char key;
	};
	void RecursiveLinearize(Node* node, int* pos, char* result);
	void RecursiveAdd(char key, Node* node);
	void RecursiveDelete(Node* node);

	Node* Root;
};

BinaryTree::BinaryTree()
{
	Root = 0;
	Size = 0;
}

BinaryTree::~BinaryTree()
{
	RecursiveDelete(Root);
}

void BinaryTree::AddNode(char key)
{
	if (!Root)
	{
		Root = new Node();
		Root->key = key;
		Root->left = 0;
		Root->right = 0;
		Size++;
	}
	else
	{
		RecursiveAdd(key, Root);
	}
}

void BinaryTree::Linearize(char* result)
{
	int position = 0;
	RecursiveLinearize(Root, &position, result);
}

void BinaryTree::RecursiveLinearize(Node* node, int* pos, char* result)
{
	if (node)
	{
		RecursiveLinearize(node->left, pos, result);
		result[*pos] = node->key;
		(*pos)++;
		RecursiveLinearize(node->right, pos, result);
		
	}
}


void BinaryTree::RecursiveDelete(Node* node)
{
	if (node)
	{
		RecursiveDelete(node->left);
		RecursiveDelete(node->right);
		delete node;
	}
}



void BinaryTree::RecursiveAdd(char key, Node* node)
{
	Node* tmp;
	bool left;
	if (key < node->key)
	{
		tmp =node->left;
		left = true;
	}
	else
	{
		tmp = node->right;
		left = false;
	}
	if (!tmp)
	{
		Size++;
		tmp = new Node();
		tmp->key = key;
		tmp->left = 0;
		tmp->right = 0;
		if (left)
		{
			node->left = tmp;
		}
		else
		{
			node->right = tmp;
		}
	}
	else
	{
		RecursiveAdd(key,tmp);
	}

}



Sorter::Sorter(SortingAlgorithm* alg) :Algorithm(alg)
{
}


Sorter::~Sorter()
{
}

void Sorter::SortData(char* data, int size)
{
	Algorithm->States.ClearStates();
	Algorithm->States.ClearTimer();
	Algorithm->States.StartTimer();
	Algorithm->Sort(data, size);
	Algorithm->States.PauseTimer();
}

void Sorter::ChangeAlgorithm(SortingAlgorithm* alg)
{
	if (Algorithm)
	{
		delete Algorithm;
	}
	Algorithm = alg;
}


void BubbleSort::Sort(char* data, int size)
{
	States.SaveCurrentState(data, size);
	bool SwapHappened;
	do {
		SwapHappened = false;
		for (int i = 0; i < size - 1; i++)
		{
			if (data[i + 1] < data[i])
			{
				swap(&data[i], &data[i+1]);
				SwapHappened = true;
				States.SaveCurrentState(data, size);
			}
		}
	} while (SwapHappened);
}

void SelectionSort::Sort(char* data, int size)
{
	States.SaveCurrentState(data, size);
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
		States.SaveCurrentState(data, size);
	}
}

void InsertionSort::Sort(char* data, int size)
{
	States.SaveCurrentState(data, size);
	for (size_t i = 1; i < size; i++)
	{
		char current = data[i];
		int j = i - 1;
		while ((j>=0)&&(current<data[j]))
		{
			data[j + 1] = data[j];
			j--;
		}
		data[j + 1] = current;
		States.SaveCurrentState(data, size);
	}
}

void ShellSort::Sort(char* data, int size)
{
	States.SaveCurrentState(data, size);
	int step = size/2;
	while (step > 0)
	{
		for (size_t i = 1; i < size; i++)
		{
			char current = data[i];
			int j = i - 1;
			while ((j >= 0) && (current < data[j]))
			{
				data[j + 1] = data[j];
				States.SaveCurrentState(data, size);
				j--;
			}
			data[j + 1] = current;
			

		}
		step = step / 2;
	}
}



void QuickSort::Sort(char* data, int size)
{
	States.SaveCurrentState(data, size);
	RecursiveSort(data, size, 0, size-1);
}

void QuickSort::RecursiveSort(char* data, int size, int begin, int end)
{

	int i = begin, j = end;
	int center = data[(begin + end) / 2];

	do {
		while (data[i] < center)
			i++;
		while (data[j] > center)
			j--;

		if (i <= j)
		{
			if (i < j)
			{
				swap(&data[i], &data[j]);
				States.SaveCurrentState(data, size);
			}
			i++;
			j--;
		}
	} while (i <= j);

	if (i < end)
		RecursiveSort(data, size,	i, end);
	if (begin < j)
		RecursiveSort(data, size, begin, j);
}

void CoctailSort::Sort(char* data, int size)
{
	States.SaveCurrentState(data, size);
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
				States.SaveCurrentState(data, size);
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
				States.SaveCurrentState(data, size);
			}
		}
		begin++;
	} while (SwapHappened);
}

void CombSort::Sort(char* data, int size)
{
	States.SaveCurrentState(data, size);
	double decreaseFactor = 1.247;
	int step = size / decreaseFactor;

	while (step>1)
	{
		for (int i = 0; i < size - step; i++)
		{
			if (data[i +step] < data[i])
			{
				swap(&data[i], &data[i + step]);
				States.SaveCurrentState(data, size);
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
				States.SaveCurrentState(data, size);
				SwapHappened = true;
			}
		}
	} while (SwapHappened);

}

void TreeSort::Sort(char* data, int size)
{
	States.SaveCurrentState(data, size);
	BinaryTree tree;
	for (int i = 0; i < size; i++)
	{
		tree.AddNode(data[i]);
	}
	tree.Linearize(data);
	States.SaveCurrentState(data, size);

}

void HeapSort::Sort(char* data, int size)
{
	States.SaveCurrentState(data, size);
	for (int i = size/2; i >= 0; i--)
	{
		SiftDown(data,size, i, size-1);
		
	}

	int end = size-1;
	while (end > 0) {
		swap(&data[0], &data[end]);
		States.SaveCurrentState(data, size);
		SiftDown(data,size, 0, end-1);
		end--;
	}

}

void HeapSort::SiftDown(char* data, int size, int begin, int end)
{
	int current = begin;
	while (current<=end/2)
	{
		if (current * 2 + 2 <= end)
		{
			int maxi = current * 2 + 1;
			if (data[current * 2 + 1] < data[2 * current + 2])
			{
				maxi = 2 * current + 2;
			}

			if ((data[current] < data[maxi]))
			{
				swap(&data[current], &data[maxi]);
				current = maxi;
			}
			else { break; }
			States.SaveCurrentState(data, size);
		}
		else if(current * 2 + 1 <= end)
		{
			if ((data[current] < data[current * 2 + 1]))
			{
				swap(&data[current], &data[current * 2 + 1]);
				current = current * 2 + 1;
				States.SaveCurrentState(data, size);
			}
			else break;
		}
		else {
			break;
		}

	}

}

void MergeSort::Sort(char* data, int size)
{
	States.SaveCurrentState(data, size);
	RecursiveSort(data, size, 0, size - 1);
}

void MergeSort::RecursiveSort(char* data, int size, int begin, int end)
{

	if (begin+1>end)
	{
		return;
	}
	int center = (begin + end) / 2;
	RecursiveSort(data, size,begin, center);
	RecursiveSort(data, size, center+1, end);
	char* result = new char[end - begin+1];


	int current1 = begin;
	int current2 = center + 1;

	for (int i = 0; i < (end-begin+1); i++)
	{
		if (current1<=center && current2 <= end)
		{
			if (data[current1] < data[current2])
			{
				result[i] = data[current1];
				current1++;
			}
			else
			{
				result[i] = data[current2];
				current2++;
			}
		}
		else
		{
			if (current1 > center)
			{
				result[i] = data[current2];
				current2++;
			}
			else
			{
				result[i] = data[current1];
				current1++;
			}
		}
	}

	for (size_t i = 0; i < (end - begin+1); i++)
	{
		data[begin+i] = result[i];
		States.SaveCurrentState(data, size);
	}
	delete[] result;
}
