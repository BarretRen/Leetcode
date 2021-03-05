/*
给出⼀个 32 位的有符号整数，你需要将这个整数中每位上的数字进⾏反转。
注意:32位的有符号整数，则其数值范围为 [−2^31, 2^31 − 1]。请根据这个假设，如果反转后整数溢出那么就返回 0
*/
#include <iostream>
#include <limits>
using namespace std;

int reverse(int x)
{
	long ret = 0;//有可能溢出，所以找个比int大的类型
	while (x != 0)
	{
		ret = ret * 10 + x % 10;
		x /= 10;
	}
	if (ret < numeric_limits<int>::min() || ret > numeric_limits<int>::max())
		return 0;
	return ret;
}

int main()
{
	cout << reverse(-123) << endl;
}