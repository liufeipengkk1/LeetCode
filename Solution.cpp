#include "stdafx.h"
#include "Solution.h"
#include <algorithm>

Solution::Solution()
{
}


Solution::~Solution()
{
}

/*
	return the length of sorted array that removed the duplicates
	do not allocate extra space for another array
*/
int Solution::removeDuplicates(int a[],int n )
{
	if (n == 0)
	{
		return 0;
	}
	
	int index = 0;
	for (int i = 1; i < n; i++) 
	{
		if (a[index] != a[i])
			a[++index] = a[i];
	}
	
	return index + 1;
}
/*
	duplicates are allowed to twice at most
*/
int Solution::removeDuplicates2(int a[], int n)
{
	if (n == 0)
	{
		return 0;
	}

	int index = 0;
	unsigned int allowed = 1;
	
	for (int i = 1; i < n; i++)
	{
		if (a[index] == a[i])
		{
			if (allowed < 2)
			{
				allowed++;
				index++;
			}
		}
		else
		{
			a[++index] = a[i];
			allowed = 1;
		}
	}

	return index + 1;
}

/*
	Search a number in sorted array
*/
int Solution::search(int a[],int n ,int target)
{
	int first = 0,last = n;
	while (first != last)
	{
		int mid = (first + last) / 2;
		if (a[mid == target])
			return mid;
		else if (a[mid] > target)
		{
			last = mid - 1;
		}
		else if(a[mid] < target)
		{
			first = mid - 1;
		}
	}

	return -1;
}

/*
	Search a number in array 
	No duplicates
	rotated array
*/
int Solution::searchRotateArray(int a[], int n, int target)
{
	return 0;
}


//leetcode 3
int Solution::lengthOfLongestSubstring(string s)
{
	if (s.length() == 0)
		return 0;
	int length = s.length();
	int  ar[256];
	memset(ar, -1, sizeof(ar));
	
	int max = 0, index = -1;
	for (int i = 0; i < length; i++)
	{
		if (ar[s[i]] >= index)
		{
			index = ar[s[i]] + 1;
		}

		if (i - index > max)
		{
			max = i - index;
		}
		ar[s[i]] = i;
	}

	return max + 1;
}


//leetcode 4
// time complixity : Log(m+n)  --> like binarySearch
double Solution::findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
{
	/*
	//Method 1:merge the arrays and sort ,the we find the median Number
	vector<int> nums(nums1.size() + nums2.size());
	copy(nums1.begin(),nums1.end(),nums.begin());
	copy(nums2.begin(), nums2.end(), nums.begin() + nums1.size());
	sort(nums.begin(), nums.end());
	
	int totalLen = nums1.size() + nums2.size();

	if (totalLen % 2)
	{
		return nums[(totalLen)/2.0];
	}
	else
	{
		return (nums[(totalLen -1 ) / 2.0] + nums[(totalLen + 1) / 2.0]) /2.0;
	}
	*/


	//Method 2:find Kth Small number
	/*int totalLen = nums1.size() + nums2.size();
	if (totalLen % 2)
		return findKthSmallValue_1(nums1, nums2, totalLen/2 + 1);
	else
	{
		int k1 = findKthSmallValue_1(nums1, nums2, (totalLen - 1) / 2 + 1);
		int k2 = findKthSmallValue_1(nums1, nums2, (totalLen + 1) / 2 + 1);
		return (k1 + k2) / 2.0;
	}*/

	//Method 3:find Kth Small number O(Log(N))
	int m = nums1.size();
	int n = nums2.size();
	int * a = new int[m];
	int * b = new int[n];
	
	for (int i = 0; i < nums1.size(); i++)
	{
		a[i] = nums1[i];
	}
	for (int i = 0; i < nums2.size(); i++)
	{
		b[i] = nums2[i];
	}

	if ((m+n) % 2)
		return findKthSmallValue_2(a,m,b,n ,(m+n) / 2 + 1);
	else
	{
		int k1 = findKthSmallValue_2(a, m, b, n, (m + n + 1) / 2 + 1);
		int k2 = findKthSmallValue_2(a, m, b, n, (m + n - 1) / 2 + 1);
		return (k1 + k2) / 2.0;
	}

}

// o(n)
double Solution::findKthSmallValue_1(vector<int>& nums1, vector<int>& nums2,int k)
{
	
	// it's easy to conjecture that k = pa + pb ;
	//pa : before Kth value,there ara pa numbers
	//pb : before Kth value ,there are pb numbers
	int pa = 0;
	int pb = 0;
	int kthVal = 0;

	if (k > (nums1.size() + nums2.size()) || k < 0)
		throw new exception("k --  out of range");

	if (k == 0)
		return (nums1[0] < nums2[0]) ? nums1[0] : nums2[0];

	vector<int>::iterator it1 = nums1.begin();
	vector<int>::iterator it2 = nums2.begin();
	while (pa + pb != k)
	{
		if ((it1 != nums1.end()) && (it2 != nums2.end()))
		{
			if ((*it1) < (*it2))
			{
				pa++;
				kthVal = (*it1);
				it1++;
			}
			else
			{
				pb++;
				kthVal = (*it2);
				it2++;
			}
		}
		else if (it1 == nums1.end())
		{
			pb++;
			kthVal = (*it2);
			it2++;

		}
		else if (it2 == nums2.end())
		{
			pa++;
			kthVal = (*it1);
			it1++;
		}
	}

	return kthVal;
}

//O(Log(N))
double Solution::findKthSmallValue_2(int a[], int m, int b[], int n, int k)
{
	if (k > (m + n) || k < 0)
		throw new exception("K --- Out of Range");
	if(m > n)
		return findKthSmallValue_2(b, n, a, m, k);
	if (m == 0)
		return b[k - 1];
	if (k == 1)
		return min(a[0],b[0]);

	int pa = min(k/2,m),pb = k - pa;
	if (a[pa - 1] > b[pb - 1])
		return findKthSmallValue_2(a, m, b + pb, n - pb, k - pb);
	else if (a[pa - 1] < b[pb - 1])
		return findKthSmallValue_2(a + pa, m - pa, b, n, k - pa);
	else if (a[pa - 1] == b[pb - 1])
	{
		return a[pa-1];
	}
}
