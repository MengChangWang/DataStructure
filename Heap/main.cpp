#include "Heap.h"

int main()
{
	//MinHeap min_heap = { 2,3,5,46,54,56,3,34,64,6,7,8 };
	vector<int> test{ 2,3,5,46,54,56,3,34,64,6,7,8 };

	MinHeap Top_K;
	vector<int> result = Top_K.solve_Top_K(test, 4);
	for (auto a : result)
	{
		cout << a << " ";
	}
	return 0;
}
