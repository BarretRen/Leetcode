/*
判断⼀个整数是否是回⽂数。回⽂数是指正序（从左向右）和倒序（从右向左）读都是⼀样的整数.
负数，个位数，10 都不是回⽂数。其他的整数再按照回⽂的规则判断。
*/
#include <iostream>
#include <string>
using namespace std;

//第一种思路，转换成字符串进行前后比较
bool isPalindrome1(int x)
{
    //负数，末位为0的都不是回文数，0除外
    if (x < 0 || (x % 10 == 0 && x != 0))
    {
        return false;
    }

    string str = std::to_string(x);
    int size = str.length();
    for (int i = 0; i < size / 2; i++)
    {
        if (str[i] != str[size - i - 1])
        {
            return false;
        }
    }
    return true;
}

//第二章思路，除以10获得每一位的数字，再比较
bool isPalindrome2(int x)
{
    //负数，末位为0的都不是回文数，0除外
    if (x < 0 || (x % 10 == 0 && x != 0))
    {
        return false;
    }
    //临时变量累加，直到x和临时变量各占一半结束循环
    int revertedNumber = 0;
    while (x > revertedNumber)
    {
        revertedNumber = revertedNumber * 10 + x % 10;
        x /= 10;
    }

    // 当数字长度为奇数时，我们可以通过 revertedNumber/10 去除处于中位的数字。
    // 例如，当输入为 12321 时，在 while 循环的末尾我们可以得到 x = 12，revertedNumber = 123，
    return x == revertedNumber || x == revertedNumber / 10;
}

int main()
{
    cout << std::boolalpha << isPalindrome1(121) << endl;
    cout << std::boolalpha << isPalindrome2(-121) << endl;
    cout << std::boolalpha << isPalindrome2(10) << endl;
}