#include "stdafx.h"
#include "Solution.h"

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
	int length = s.length();
	int  ar[256];
	
	memset(ar,-1,sizeof(ar));

	int max = 0, index = 0;
	for (int i = 0; i < length; i++)
	{
		if (ar[s[i]] != -1)
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