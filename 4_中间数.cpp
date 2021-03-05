/*
给定两个⼤⼩为 m 和 n 的有序数组 nums1 和 nums2。
请你找出这两个有序数组的中位数，并且要求算法的时间复杂度为 O(log(m + n))。
你可以假设 nums1 和 nums2 不会同时为空。
*/
#include <iostream>
#include <vector>
using namespace std;

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
{
	//假设第一参数长度小
	if (nums1.size() > nums2.size())
	{
		return findMedianSortedArrays(nums2, nums1);
	}
	int low = 0;
	int high = nums1.size();
	int k = (nums1.size() + nums2.size() + 1) / 2;//中位数的位置
	int nums1Mid = 0, nums2Mid = 0;
	while (low <= high)
	{
		//交叉判断，直到确定两个mid位置
		// nums1: ……………… nums1[nums1Mid-1] | nums1[nums1Mid] ……………………
		// nums2: ……………… nums2[nums2Mid-1] | nums2[nums2Mid] ……………………
		nums1Mid = low + (high - low) / 2;
		nums2Mid = k - nums1Mid;
		if (nums1Mid > 0 && nums1[nums1Mid - 1] > nums2[nums2Mid])
		{
			//nums1的分界线划多了，需要向左移动
			high = nums1Mid - 1;
		}
		else if (nums1Mid != nums1.size() && nums1[nums1Mid] < nums2[nums2Mid - 1])
		{
			//nums1的分界线划少了，需要向右移动
			low = nums1Mid + 1;
		}
		else
		{
			break;//找到合适的划分，推出循环
		}
	}
	double midLeft = 0, midRight = 0;
	if (nums1Mid == 0)
		midLeft = nums2[nums2Mid - 1];
	else if (nums2Mid == 0)
		midLeft = nums1[nums1Mid - 1];
	else
		midLeft = max(nums1[nums1Mid - 1], nums2[nums2Mid - 1]);
	
	if (((nums1.size() + nums2.size()) & 1) == 1)
		return midLeft;//两个列表总长为奇数，返回中间值

	if (nums1Mid == nums1.size())
		midRight = nums2[nums2Mid];
	else if (nums2Mid == nums2.size())
		midRight = nums1[nums1Mid];
	else
		midRight = min(nums1[nums1Mid], nums2[nums2Mid]);

	return (midRight + midLeft) / 2;//总长为偶数，返回两个中间值的平均值
}

int main()
{
	vector<int> a{ 1, 2 };
	vector<int> b{ 3, 4 };
	cout << findMedianSortedArrays(a, b) << endl;
}