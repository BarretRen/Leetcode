#include <string>
#include <iostream>
#include <unordered_set>
#include <unordered_map>
using namespace std;

//首先想到的版本，从第一个字符开始遍历，到出现重复字符停止
//性能较差
int lengthOfLongestSubstring1(string s)
{
    int size = s.size();
    if (size == 0)
    {
        return 0;
    }
    unordered_set<char> tmpSet;
    int ret = 0;
    for (int i = 0; i < size; ++i)
    {
        for (int j = i; j < size; j++)
        {
            if (tmpSet.find(s[j]) == tmpSet.end())
            {
                tmpSet.insert(s[j]);
            }
            else
            {
                break;
            }
        }
        ret = ret < tmpSet.size() ? tmpSet.size() : ret;
        tmpSet.clear();
    }
    return ret;
}

//第二版本，如何优化呢？
//两个循环，改成一个循环
int lengthOfLongestSubstring2(string s)
{
    int size = s.size();
    if (size == 0)
    {
        return 0;
    }
    int ret = 0;
    unordered_map<char, int> tmap; //保存char和对应的index
    for (int i = 0, j = 0; i < size; i++)
    {
        if (tmap.find(s[i]) != tmap.end())
        {
            j = tmap[s[i]] > j ? tmap[s[i]] : j;
        }
        ret = (ret < (i - j + 1)) ? (i - j + 1) : ret;
        tmap[s[i]] = i + 1;
    }
    return ret;
}

int main()
{
    string s = " ";
    cout << lengthOfLongestSubstring1(s) << endl;
    cout << lengthOfLongestSubstring2(s) << endl;
}