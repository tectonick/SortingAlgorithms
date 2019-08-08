#include "SortingAlgorithms.h"


void swap(int* a, int* b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

class BinaryTree
{
public:
	BinaryTree();
	~BinaryTree();
	void AddNode(int key);
	void Linearize(int * result);
private:
	int Size;
	
	struct Node
	{
		Node * left, * right; 
		int key;
	};
	void RecursiveLinearize(Node* node, int * pos, int * result);
	void RecursiveAdd(int key, Node* node);
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

void BinaryTree::AddNode(int key)
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

void BinaryTree::Linearize(int* result)
{
	int position = 0;
	RecursiveLinearize(Root, &position, result);
}

void BinaryTree::RecursiveLinearize(Node* node, int* pos, int* result)
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



void BinaryTree::RecursiveAdd(int key, Node* node)
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

void TreeSort::Sort(int* data, int size)
{
	BinaryTree tree;
	for (int i = 0; i < size; i++)
	{
		tree.AddNode(data[i]);
	}
	tree.Linearize(data);

}

void HeapSort::Sort(int* data, int size)
{
	for (int i = size/2; i >= 0; i--)
	{
		SiftDown(data, i, size);
	}

	int end = size-1;
	while (end > 0) {
		swap(&data[0], &data[end]);
		SiftDown(data, 0, end);
		end--;
	}

}

void HeapSort::SiftDown(int* data, int begin, int end)
{
	int current = begin;
	while (current<=end/2)
	{
		if ((current * 2 + 1 < end) && (data[current] < data[2 * current + 1]))
		{
			swap(&data[current], &data[2 * current + 1]);
			current = 2 * current + 1;
		} else
		if ((current * 2 + 2 < end) && (data[current] < data[2 * current + 2]))
		{
			swap(&data[current], &data[2 * current + 2]);
			current = 2 * current + 2;
		}
		else {
			break;
		}
	}

}

void MergeSort::Sort(int* data, int size)
{
	RecursiveSort(data, 0, size - 1);
}

void MergeSort::RecursiveSort(int* data, int begin, int end)
{
	if (begin+1>end)
	{
		return;
	}
	int center = (begin + end) / 2;
	RecursiveSort(data, begin, center);
	RecursiveSort(data, center+1, end);
	int* result = new int[end - begin+1];


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
	}
	delete[] result;
}
