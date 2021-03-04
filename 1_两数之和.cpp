/*
题⽬⼤意
在数组中找到2个数之和等于给定值的数字，结果返回2个数字在数组中的下标。

解题思路
这道题最优的做法时间复杂度是 O(n)。
顺序扫描数组，对每⼀个元素，在map中找能组合给定值的另⼀半数字，如果找到了，直接返回2个数字的下标即可。
如果找不到，就把这个数字存⼊map中，等待遍历到“另⼀半”数字的时候，再取出来返回结果。
*/

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

vector<int> twoSum(vector<int>& nums, int target)
{
	//map保存两个数字，key为值，value为index
	//这里使用unordered_map，内部为哈希实现；不使用map，map为红黑树实现，插入耗时大
	unordered_map<int, int> twoNum;
	for (int i = 0; i < nums.size(); i++)
	{
		int another = target - nums[i];
		//查找map中是否已经存在另一半数字
		if (twoNum.find(another) != twoNum.end())
		{
			return vector<int>{twoNum[another], i};
		}
		twoNum[nums[i]] = i;//当前数字无匹配，插入map
	}
	return vector<int>{};
}

int main()
{
	vector<int> nums{ 2, 7, 11, 15 };
	int target{ 9 };
	vector<int> rets = twoSum(nums, target);
	for (auto ret : rets)
	{
		cout << ret << "  ";
	}
	return 0;
}