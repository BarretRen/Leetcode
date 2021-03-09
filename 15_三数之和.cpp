/*
给你一个包含n个整数的数组nums，判断nums中是否存在三个元素a，b，c ，使得a+b+c=0？请你找出所有和为0且不重复的三元组。
注意：答案中不可以包含重复的三元组
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

vector<vector<int>> threeSum1(vector<int> &nums)
{
    vector<vector<int>> ans;
    int n = nums.size();
    if (n < 3)
        return ans;

    sort(nums.begin(), nums.end());
    //遍历得到第一个数a
    for (int first = 0; first < n; ++first)
    {
        // 需要和上一次遍历的数不相同
        if (first > 0 && nums[first] == nums[first - 1])
        {
            continue;
        }
        // c 对应的指针初始指向数组的最右端
        int third = n - 1;
        int target = -nums[first]; //与第一个数和为0
        //遍历得到第二个数b，起始位置大于第一个数
        for (int second = first + 1; second < n; ++second)
        {
            // 需要和上一次枚举的数不相同
            if (second > first + 1 && nums[second] == nums[second - 1])
            {
                continue;
            }
            // 需要保证 b 的指针在 c 的指针的左侧
            while (second < third && nums[second] + nums[third] > target)
            {
                --third;
            }
            // 如果指针重合，随着 b 后续的增加
            // 就不会有满足 a+b+c=0 并且 b<c 的 c 了，可以退出循环
            if (second == third)
            {
                break;
            }
            if (nums[second] + nums[third] == target)
            {
                ans.push_back({nums[first], nums[second], nums[third]});
            }
        }
    }
    return ans;
}

//第二版本效率低，看似有技巧
vector<vector<int>> threeSum2(vector<int> &nums)
{
    vector<vector<int>> ans;
    if (nums.size() < 3)
        return ans;

    map<int, int> m;
    for (auto num : nums)
    {
        m[num]++;
    }
    sort(nums.begin(), nums.end());
    nums.erase(unique(nums.begin(), nums.end()), nums.end());

    for (int i = 0; i < nums.size(); ++i)
    {
        if (nums[i] * 3 == 0 && m[nums[i]] >= 3)
        {
            ans.push_back({nums[i], nums[i], nums[i]});
        }
        for (int j = i + 1; j < nums.size(); ++j)
        {
            if (nums[i] * 2 + nums[j] == 0 && m[nums[i]] >1)
            {
                ans.push_back({nums[i], nums[i], nums[j]});
            }
            if (nums[j] * 2 + nums[i] == 0 && m[nums[j]] > 1)
            {
                ans.push_back({nums[i], nums[j], nums[j]});
            }
            int c = 0 - nums[i] - nums[j];
            if (c > nums[j] && m[c] > 0)
            {
                ans.push_back({nums[i], nums[j], c});
            }
        }
    }
    return ans;
}

int main()
{
    vector<int> nums{-1, 0, 1, 2, -1, -4};
    auto vec1 = threeSum2(nums);
    for (auto v1 : vec1)
    {
        cout << "[";
        for (auto n1 : v1)
            cout << n1 << ", ";
        cout << "]" << endl;
    }
}