#pragma once
#include <string>
#include <vector>>
#include <iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
	Solution();
	~Solution();

	int removeDuplicates(int a[],int n);
	int removeDuplicates2(int a[], int n);
	int search(int a[],int n ,int target);
	int searchRotateArray(int a[], int n, int target);

	//Leet code 1:
	/*
	The function twoSum should return indices of the two numbers such that they add up to the target,
	where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.

	You may assume that each input would have exactly one solution.
	Input: numbers={2, 7, 11, 15}, target=9
	Output: index1=1, index2=2
	*/
	vector<int> twoSum(vector<int>& nums, int target);

	//LeetCode2:addTwoNumbers
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2);

	// leet code 3:longest substring without repeating characters
	int lengthOfLongestSubstring(string s);

	//leetcode 4:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2);
	
	
private:
	double findKthSmallValue_1(vector<int>& nums1, vector<int>& nums2,int k);
	double findKthSmallValue_2(int a[],int m,int b[],int n,int k);
};

