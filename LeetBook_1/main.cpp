#include<iostream>
#include"quickSort.h"
#include "Solution.h"
#include "kmp.h"
using namespace std;

int main() {
	KMP<char> kmp;
	vector<char> demo{ 'a','b','a','b','d','a','c' };
	kmp.createNext(demo);
	kmp.printNext();


}

