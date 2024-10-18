#pragma once
#include<iostream>
#include<vector>
#include<initializer_list>
#include<cmath>
using namespace std;

class MinHeap {
private:
	vector<int> heap;

private:
	void siftUp(int);
	void siftDown(int);
public:
	MinHeap() {}
	MinHeap(initializer_list<int>);
	int peak() { return heap[0]; }
	int getParent(int index) { return heap[(index - 1) >> 1]; }
	int getLeft(int index) { return heap[(index << 1) + 1]; }
	int getRight(int index) { return heap[(index << 1) + 2]; }
	bool isEmpty() { return heap.empty(); }
	void push(int);
	void print();
	void length() { cout << "the length is:" << heap.size()<<endl; }
	void height() { cout << "the height is:" << round(log2(heap.size() + 1))<<endl; }
	void remove();
	vector<int> solve_Top_K(const vector<int>&,int);
};

void MinHeap::siftUp(int index)
{
	if (this->isEmpty()) { cout << "this heap is empty" << endl; return; }
	if (index >= heap.size()) { cout << "this index is over than heap's size" << endl; return; }
	
	while (true)
	{
		int parent = (index - 1) >> 1;
		if (parent < 0 ) break;

		if (heap[parent] > heap[index])
			swap(heap[parent], heap[index]);
		else break;
		index = parent;
	}
	return;
	//siftUp(index);
}

void MinHeap::push(int x)
{
	heap.push_back(x);
	this->siftUp(heap.size() - 1);
}

void MinHeap::print()
{
	int height = round(log2(heap.size() + 1));//²ãÊý
	for (int i = height; i > 0; i--)
	{
		for (int j = i-1; j > 0; j--)
		{
			cout << "  ";
		}
		int n = height - i + 1;//²ãÊý
		int last_sum = pow(2, n - 1) - 1;
		for (int j = 0; j < pow(2, n - 1); j++)
		{
			if (last_sum + j >= heap.size()) break;
			cout << heap[last_sum + j] << "  ";
		}
		cout << endl;
	}
}

void MinHeap::siftDown(int index)
{
	if (this->isEmpty()) { cout << "this heap is empty" << endl; return; }
	if (index >= heap.size()) { cout << "this index is over than heap's size" << endl; return; }
	if (index < 0) { cout << "error! the index can not less than 0" << endl; return; }

	while (true)
	{
		int left = (index << 1) + 1;
		int right = (index << 1) + 2;
		int min = index;

		if (index >= heap.size()) break;

		if (left < heap.size() && heap[min] > heap[left]) min = left;
		if (right < heap.size() && heap[min] > heap[right]) min = right;

		if (min == index) break;
		swap(heap[index], heap[min]);

		index = min;

	}
	
}

MinHeap::MinHeap(initializer_list<int> list)
{
	for (auto a : list)
	{
		heap.push_back(a);
	}
	for (int i = (heap.size() - 2) >> 1; i >= 0; i--)
	{
		siftDown(i);
	}
}

void MinHeap::remove()
{
	swap(heap[0], heap[heap.size() - 1]);
	heap.erase(heap.end() - 1);
	this->print();

	this->siftDown(0);
}

vector<int> MinHeap::solve_Top_K(const vector<int>& ex,int k)
{
	for (int i = 0; i < k; i++)
	{
		this->push(ex[i]);
	}

	for (int i = k; i < ex.size(); i++)
	{
		if (this->peak() < ex[i])
		{
			this->remove();
			this->push(ex[i]);
		}
	}
	return heap;
}
