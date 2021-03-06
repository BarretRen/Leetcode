/*
给出⼀个⾮负整数数组 a1，a2，a3，…… an，每个整数标识⼀个竖⽴在坐标轴x位置的⼀堵⾼度为ai的墙，选择两堵墙和x轴构成的容器可以容纳最多的⽔。
*/
#include <iostream>
#include <vector>
using namespace std;

//首尾两个指针，从两端向中间遍历
int maxArea1(vector<int> &height)
{
    int ret = 0, start = 0, end = height.size() - 1;
    int width = 0, high = 0;
    while (start < end)
    {
        width = end - start;
        if (height[start] < height[end])
        {
            //前面小，需要增加start，看看有没有更大的前面高度
            high = height[start];
            start++;
        }
        else
        {
            //后面小，需要减小end，看看有没有更大的后面高度
            high = height[end];
            end--;
        }
        ret = max(ret, (width * high));
    }
    return ret;
}

int main()
{
    vector<int> vec{1, 8, 6, 2, 5, 4, 8, 3, 7};
    cout << maxArea1(vec) << endl;
}