#pragma once
#include<iostream>
#include<vector>

using namespace std;

class quickSort {
public:
    virtual vector<int>& sort(vector<int>&, int, int) = 0;
};

class basicQuickSort :public quickSort {
public:
    int partition(vector<int>& nums, int left, int right) {
        int i = left-1;
        int pivot = nums[right];
        for (int j = left; j <= right - 1; j++) {
            if (nums[j] < pivot) {
                i++;
                swap(nums[i], nums[j]);
            
            }
        }
        swap(nums[i+1], nums[right]);
        return i+1;
    }
    vector<int>& sort(vector<int>& nums, int left, int right) override{
        if (left >= right) return nums;

        int pivot = partition(nums, left, right);

        sort(nums, left, pivot - 1);
        sort(nums, pivot + 1,right);
    }
};
