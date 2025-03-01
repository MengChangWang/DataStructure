#pragma once
#include<iostream>
#include<vector>

using namespace std;

template <typename T>
class KMP {
private:
	vector<int> next;
	vector<int> nextval;

public:
	KMP(){};
	void createNext(vector<T> model) {
		next.resize(model.size());
		next[0] = -1;
		int i = 1; int j = -1;


		while (i < model.size()-1) {
			if (j == -1 || model[j] == model[i]) {
				next[++i] = ++j;
				if (model[i] == model[next[i]]) {
					next[i] = next[next[i]];
				}
			}
			else {
				j = next[j];
			}
		}
	}



	void printNext() {
		if (this->next.empty()) {
			cout << "next数组为空";
			return;
		}

		cout << "next数组:";
		for (int i : next) {
			cout << i << ",";
		}

	}
};