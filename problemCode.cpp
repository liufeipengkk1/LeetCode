// o(n)
// 两个已经排序好的数组，寻找两个数组合并后第K小的数
//问题：边界
double findKthSmallValue_1(vector<int>& nums1, vector<int>& nums2,int k)
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

	while (pa + pb != k)
	{
		//问题语句：当到达较短一组nums的size边界的时候，假设AI size()较小，则到达边界之后if语句将会一直成立，导致结果出错
		int ai = (nums1.size() == pa) ? nums1[nums1.size() - 1] : nums1[pa];
		int bi = (nums2.size() == pb) ? nums2[nums2.size() - 1] : nums2[pb];

		if (ai < bi)
		{
			pa++;
			kthVal = ai;
		}
		else
		{
			pb++;
			kthVal = bi;
		}
	}

	return kthVal;
}

