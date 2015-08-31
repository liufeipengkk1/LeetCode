#pragma once
#include <string>
#include <vector>>
#include <iostream>
using namespace std;
class Solution
{
public:
	Solution();
	~Solution();

	int removeDuplicates(int a[],int n);
	int removeDuplicates2(int a[], int n);
	int search(int a[],int n ,int target);
	int searchRotateArray(int a[], int n, int target);

	// leet code 3:longest substring without repeating characters
	//this problem actully means finding the charaters thar appears once
	int lengthOfLongestSubstring(string s);

	//leetcode 4:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2);
private:
	double findKthSmallValue_1(vector<int>& nums1, vector<int>& nums2,int k);
};

