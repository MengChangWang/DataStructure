#include"GraphAdjList.h"

int main()
{
	vector<int> vertices{ 1,2,3,4,5 };
	vector<vector<int>> edges{ {1,2},{1,3},{1,4},{3,10},{3,4},{4,5},{5,7},{7,10} };
	GraphAdjList<int> graph(vertices, edges);
	graph.print();
	graph.removeEdge(4, 5);
	graph.print();
	graph.removeVertex(3);
	graph.print();

	return 0;
}