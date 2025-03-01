#pragma once
#include<iostream>
#include<vector>
#include<unordered_set>
#include"quickSort.h"

using namespace std;

class Solution {
public:
    unordered_set<string> makeSub(string s) {
        unordered_set<string> subInfo;
        for (int i = 1; i < s.size(); i += 2) {
            string temp;
            for (int j = i - 1; j <= i; j++) temp += s[j];
            subInfo.insert(temp);
        }
        return subInfo;
    }
    bool isSubstringPresent(string s) {
        string s_reverse(s.rbegin(), s.rend());
        unordered_set<string> subInfo_s;
        unordered_set<string> subInfo_re;

        bool flag = false;

        subInfo_s = makeSub(s);
        subInfo_re = makeSub(s_reverse);

        for (auto it : subInfo_s) {
            if (subInfo_re.find(it) != subInfo_re.end()) {
                flag = true;
                break;
            }
        }

        return flag;
    }
};

