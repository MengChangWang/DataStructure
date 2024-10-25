#include"GraphAdjMat.h"

int main()
{
	vector<int> vertices{ 1,2,3,4,5 };
	vector<vector<int>> edges{ {1,3},{1,5},{2,3},{2,5},{4,5},{4,2} };
	GraphAdjMat graph(vertices, edges);
	graph.print();
	return 0;
}