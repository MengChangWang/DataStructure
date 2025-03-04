#pragma once
#include<iostream>
#include<unordered_map>
#include<vector>
#include<queue>
#include<unordered_set>
using namespace std;
//目前尚不支持自定义类型
template <typename T>
class GraphAdjList {
	struct PairHash {
		size_t operator()(const pair<T, T>& pair) const {
			return hash<T>()(std::min(pair.first, pair.second)) ^
				hash<T>()(std::max(pair.first, pair.second));
		}
	};

	struct PairEqual {
		bool operator()(const pair<T, T>& a, const std::pair<T, T>& b) const {
			return min(a.first, a.second) == min(b.first, b.second) &&
				max(a.first, a.second) == max(b.first, b.second);
		}
	};
private:
	unordered_map<T, vector<T>> graph;
public:
	GraphAdjList(const vector<T>&, const vector<vector<T>>&);
	int size();
	void addVertex(T);
	void addEdge(T, T);//直接以值作为key
	void removeEdge(T, T);
	void removeVertex(T);
	void print() { this->printVertices(); this->printEdges(); }
	void printEdges();
	void printVertices();
	void BFS();
	void DFS();

private:
	void remove(vector<T>&, T);
	void _dfs(vector<T>&, unordered_set<T>&, T&);
};


template <typename T>
GraphAdjList<T>::GraphAdjList(const vector<T>& vertices, const vector<vector<T>>& edges)
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
	if (this->graph.count(data)) return;

	this->graph[data] = vector<int>{};
}

template <typename T>
void GraphAdjList<T>::addEdge(T x, T y)
{
	if (!this->graph.count(x) || !this->graph.count(y) || x == y)
	{
		cout << "这两个顶点无法建立联系" << endl;
		return;
	}

	this->graph[x].push_back(y);
	this->graph[y].push_back(x);
}

template <typename T>
int GraphAdjList<T>::size()
{
	return graph.size();
}

template <typename T>
void GraphAdjList<T>::remove(vector<T>& list, T x)
{
	auto it = find(list.begin(), list.end(), x);
	int index = distance(list.begin(), it);

	list.erase(it);
}

template <typename T>
void GraphAdjList<T>::removeEdge(T x, T y)
{
	if (this->graph.count(x) == 0 || this->graph.count(y) == 0)
	{
		cout << "所要删除的边不存在!删除失败" << endl;
		return;
	}
	remove(graph[x], y);
	remove(graph[y], x);
}

template <typename T>
void GraphAdjList<T>::removeVertex(T data)
{
	auto it = this->graph.find(data);
	if (it == this->graph.end()) { cout << "该元素不存在" << endl; return; }
	this->graph.erase(it);
	for (auto& temp : this->graph)
	{
		int flag = count(temp.second.begin(), temp.second.end(), data);
		if (flag)
			remove(temp.second, data);
	}
}

template <typename T>
void GraphAdjList<T>::printVertices()
{
	cout << "vertices:";
	for (auto& temp : this->graph)
	{
		cout << temp.first << " ";
	}
	cout << endl;
	cout << "edges";
}

template <typename T>
void GraphAdjList<T>::printEdges()
{
	unordered_set<pair<T, T>, GraphAdjList<T>::PairHash, GraphAdjList<T>::PairEqual> _edges;
	for (auto& temp : this->graph)
	{
		vector<T>& temp_vector = temp.second;
		for (T& x : temp_vector)
		{
			_edges.insert({ temp.first,x });
		}
	}

	for (auto temp : _edges)
	{
		cout << "{" << temp.first << "," << temp.second << "}";
	}
	cout << endl;
}

template <typename T>
void GraphAdjList<T>::BFS()
{
	vector<T> result;
	queue<T> tempStor;
	unordered_set<T> check;

	T start = this->graph.begin()->first;
	tempStor.push(start);
	check.insert(start);
	while (!tempStor.empty())
	{
		T vertex = tempStor.front();
		tempStor.pop();
		result.push_back(vertex);
		for (T v : this->graph[vertex])
		{
			if (check.count(v)) continue;
			tempStor.push(v);
			check.insert(v);
		}
	}
	for (T& r : result)
	{
		cout << r << " ";
	}
	cout << endl;
}

template <typename T>
void GraphAdjList<T>::_dfs(vector<T>& result, unordered_set<T>& check, T& val)
{
	result.push_back(val);
	check.insert(val);
	for (T& t : this->graph[val])
	{
		if (check.count(t)) continue;
		_dfs(result,check,t);
	}
}

template <typename T>
void GraphAdjList<T>::DFS()
{
	unordered_set<T> check;
	vector<T> result;
	T value = this->graph.begin()->first;
	_dfs(result, check, value);

	for (T& t : result)
	{
		cout << t << " ";
	}
}
