#pragma once
#include<iostream>
#include<vector>
#include<initializer_list>
#include<unordered_set>

using namespace std;

class GraphAdjMat {
private:
	vector<int> vertices;
	vector<vector<int>> adjMat;
public:
	GraphAdjMat(const vector<int>&, const vector<vector<int>>&);
	//GraphAdjMat(const initializer_list<int>&);
	int size();
	void addVertex(int);//添加顶点
	void addEdge(int, int);//添加边(联系) 以顶点的索引作为key 01作为value
	void removeEdge(int, int);
	void removeVertex(int);
	void print();
};





int GraphAdjMat::size()
{
	return vertices.size();
}

GraphAdjMat::GraphAdjMat(const vector<int>& vertices, const vector<vector<int>>& edges)
{
	for (int vertex : vertices)
	{
		addVertex(vertex);
	}
	for (vector<int> edge : edges)
	{
		auto it_x = find(this->vertices.begin(), this->vertices.end(), edge[0]);
		auto it_y = find(this->vertices.begin(), this->vertices.end(), edge[1]);

		int index_x = distance(this->vertices.begin(), it_x);
		int index_y = distance(this->vertices.begin(), it_y);

		addEdge(index_x, index_y);
	}
}

void GraphAdjMat::addEdge(int i, int j)
{
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

void GraphAdjMat::removeEdge(int x,int y)
{
	if (count(vertices.begin(), vertices.end(), x) == 0) {cout << "顶点不存在" << endl; return;}
	if (count(vertices.begin(), vertices.end(), y) == 0) { cout << "顶点不存在" << endl; return; }

	auto it_i = find(vertices.begin(),vertices.end(),x);
	auto it_j = find(vertices.begin(),vertices.end(),y);

	int i = distance(vertices.begin(), it_i);
	int j = distance(vertices.begin(), it_j);

	if (i < 0 || j < 0 || i >= size() || j >= size() || i == j) {
		cout << "顶点不存在" << endl;
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

void GraphAdjMat::print()
{
	cout << "vertices:";
	for (auto val : this->vertices)
	{
		cout << val << " ";
	}
	cout << endl;

	int n = this->adjMat.size();
	vector<pair<int, int>> pair;
	for (int i = 0; i < n; i++)
	{
		for (int j = i; j < n; j++)
		{
			if (adjMat[i][j] == 1)
			{
				pair.push_back({ i,j });
			}
		}
	}
	cout << "edges:";
	for (auto p : pair)
	{
		cout << "{" << vertices[p.first] << "," << vertices[p.second] << "}" << " ";
	}
	cout << endl;
}