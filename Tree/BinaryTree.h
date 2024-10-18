#pragma once
#include<iostream>
#include<initializer_list>
#include<vector>
#include<queue>

using namespace std;
class BinaryTree {
public:
	struct Node {
		int data;
		Node* left;
		Node* right;
		Node(int x) :data{ x }, left{nullptr},right{nullptr} {}
	};

public:
	int getHeight(const Node*) const;

	void insert(const int);
	Node* insertRecursive(Node*&, int);

	BinaryTree(){}
	BinaryTree(const initializer_list<int>&);
	void print() const;
	vector<int> BFS() const;
	int treeHeight() { return this->getHeight(this->root_node); }
	void remove(int x);

private:
	Node* root_node = nullptr;
};

void BinaryTree::insert(const int x)
{
	Node* new_node = new Node(x);
	if (this->root_node == nullptr)
	{
		root_node = new_node;
		return;
	}

	Node* cur = this->root_node; Node* pre = nullptr;
	
	while (cur != nullptr)
	{
		pre = cur;
		if (x == cur->data) return;
		else if (x > cur->data)
		{
			cur = cur->right;
		}
		else
			cur = cur->left;
	}
	if (x > pre->data) pre->right = new_node;
	else if (x < pre->data) pre->left = new_node;
}

BinaryTree::Node* BinaryTree::insertRecursive(Node*& target, int data)
{
	if (target == nullptr)
	{
		target = new Node(data);
		return target;
	}

	if (data > target->data) target->right = insertRecursive(target->right, data);
	else if (data < target->data) target->left = insertRecursive(target->left, data);

	return target;
}

BinaryTree::BinaryTree(const initializer_list<int>& input_list) 
{
	for (int x : input_list)
	{
		this->insert(x);
		//this->insertRecursive(this->root_node, x);
	}
}

void BinaryTree::print() const
{
	if (this->root_node == nullptr)
	{
		cout << "Error! the tree is null!" << endl;
		return;
	}
	const vector<int> result = this->BFS();
	

	int height = round(log2(result.size() + 1));//²ãÊý
	for (int i = height; i > 0; i--)
	{
		for (int j = i - 1; j > 0; j--)
		{
			cout << "  ";
		}
		int n = height - i + 1;//²ãÊý
		int last_sum = pow(2, n - 1) - 1;
		for (int j = 0; j < pow(2, n - 1); j++)
		{
			if (last_sum + j >= result.size()) break;
			cout << result[last_sum + j] << "  ";
		}
		cout << endl;
	}
}

vector<int> BinaryTree::BFS() const
{
	if (this->root_node == nullptr)
	{
		cout << "Error! the tree is null!" << endl;
		return {};
	}

	Node* temp = this->root_node;

	queue<Node* > queue;
	queue.push(temp);

	vector<int> result;

	while (!queue.empty())
	{
		temp = queue.front();
		result.push_back(temp->data);
		if (temp->left) queue.push(temp->left);
		if (temp->right) queue.push(temp->right);
		queue.pop();
	}
	return result;
}

int BinaryTree::getHeight(const Node* node) const
{
	if (node == nullptr) return -1; 
	int height = 0;
	int left_height = getHeight(node->left);
	int right_height = getHeight(node->right);

	return height = max(left_height, right_height) + 1;
}

void BinaryTree::remove(int x)
{
	if (this->root_node == nullptr) { cout << "the root node is empty"; return; }

	Node* cur = this->root_node; Node* pre = nullptr;
	while (cur != nullptr)
	{
		if (cur->data == x) break;

		else if (cur->data < x)
		{
			pre = cur;
			cur = cur->right;
		}
		else
		{
			pre = cur;
			cur = cur->left;
		}
	}

	if (cur == nullptr)
	{
		cout << "can not find the value in the tree" << endl;
	}
	if (cur->left == nullptr || cur->right == nullptr)
	{
		Node* temp = cur->left == nullptr ? cur->right : cur->left;
		if (cur != this->root_node)
		{
			if (pre->left == cur)
			{
				pre->left = temp;
			}
			else if (pre->right == cur)
			{
				pre->right = temp;
			}
		}
		else
			this->root_node = temp;
		delete cur;
	}
	else
	{
		Node* temp = cur->right;
		while (temp->left)
		{
			temp = temp->left;
		}
		int temp_value = temp->data;
		this->remove(temp_value);
		cur->data = temp_value;
	}


}