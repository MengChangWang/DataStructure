#pragma once
#include<iostream>
#include<vector>

using namespace std;

class GraphAdjMat {
private:
	vector<int> vertices;
	vector<vector<int>> adjMat;
public:
	GraphAdjMat(const vector<int>&, const vector<vector<int>>&);
	int size();
	void addVertex(int);
	void addEdge(int, int);
	void removeEdge(int, int);
	void removeVertex(int);
	void print();
};

GraphAdjMat::GraphAdjMat(const vector<int>& vertices, const vector<vector<int>>& edges)
{
	for (int vertex : vertices)
	{
		addVertex(vertex);
	}
	for (vector<int> edge : edges)
	{
		addEdge(edge[0], edge[1]);
	}
}

void GraphAdjMat::addEdge(int i, int j)
{
	if (i < 0 || j < 0 || i >= size() || j >= size() || i == j) {
		throw out_of_range("顶点不存在");
	}
	adjMat[i][j] = 1;
	adjMat[j][i] = 1;
}

void GraphAdjMat::addVertex(int x)
{
	int n = this->size();
	this->vertices.push_back(x);

	this->adjMat.emplace_back(vector<int>(n,0));
	for (auto& row : adjMat)
	{
		row.push_back(0);
	}
}

void GraphAdjMat::removeEdge(int i,int j)
{
	if (i < 0 || j < 0 || i >= size() || j >= size() || i == j) {
		throw out_of_range("顶点不存在");
	}
	adjMat[i][j] = 0;
	adjMat[j][i] = 0;
}

void GraphAdjMat::removeVertex(int x)
{
	auto it = find(this->vertices.begin(), this->vertices.end(), x);
	if (it == this->vertices.end()) return;
	int index = distance(this->vertices.begin(), it);

	this->vertices.erase(it);
	this->adjMat.erase(this->adjMat.begin()+index);

	for (auto vertex : this->adjMat)
	{
		vertex.erase(vertex.begin() + index);
	}
}