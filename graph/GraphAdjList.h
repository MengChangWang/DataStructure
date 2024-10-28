#pragma once
#include<iostream>
#include<unordered_map>
#include<vector>

using namespace std;
//Ŀǰ�в�֧���Զ�������
template <typename T>
class GraphAdjList {
private:
	unordered_map<T, vector<T>> graph;
public:
	GraphAdjList(const vector<T>&, const vector<vector<T>>&);
	int size();
	void addVertex(T);
	void addEdge(T, T);//ֱ����ֵ��Ϊkey
	void removeEdge(T,T);
	void removeVertex(T);
	void print();
};

template <typename T>
GraphAdjList<T>::GraphAdjList(const vector<T>& vertices, const vector<vector<T>> &edges)
{
	for (T vertex : vertices)
	{
		addVertex(vertex);
	}
	for (auto edge : edges)
	{
		addEdge(edge[0], edge[1]);
	}
}

template <typename T>
void GraphAdjList<T>::addVertex(T data)
{
	this->graph[data]
}

template <typename T>
void GraphAdjList<T>::addEdge(T x,T y)
{
	if (this->graph.count(x) == 0 || this->graph.count(y) == 0) return;

	this->graph[x].push_back(y);
	this->graph[y].push_back(x);
}

template <typename T>
int GraphAdjList<T>::size()
{
	return graph.size();
}

template <typename T>
void GraphAdjList<T>::removeEdge(T x, T y)
{
	if (this->graph.count(x) == 0 || this->graph.count(y) == 0)
	{
		cout << "��Ҫɾ���ı߲�����!ɾ��ʧ��" << endl;
		return;
	}
	auto temp_vector = graph[x]; temp_vector.erase(y);
	temp_vector = graph[y]; temp_vector.erase(x);
}

template <typename T>
void GraphAdjList<T>::removeVertex(T data)
{
	if (this->graph.count(x) == 0 || this->graph.count(y) == 0)
	{
		cout << "��Ҫɾ���Ķ��㲻����!ɾ��ʧ��" << endl;
		return;
	}
	this->graph.erase(data);
	for (vector<T> temp_vector : this->graph)
	{
		if(count(temp_vector.begin(),temp_vector.end(),data))
		temp_vector.erase(data);
	}
}

template <typename T>
void GraphAdjList<T>::print()
{

}