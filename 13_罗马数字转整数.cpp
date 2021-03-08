/*
罗⻢数字包含以下七种字符: I，V，X，L，C，D 和 M
字符          数值
I             1
V             5
X             10
L             50
C             100
D             500
M             1000

I 可以放在 V (5) 和 X (10) 的左边，来表示 4 和 9。
X 可以放在 L (50) 和 C (100) 的左边，来表示 40 和 90。 
C 可以放在 D (500) 和 M (1000) 的左边，来表示 400 和 900。
给定一个罗马数字，将其转换成整数。输入确保在 1 到 3999 的范围内。
*/
#include <iostream>
#include <string>
using namespace std;

int romanToInt(string s)
{
	if (s.size() == 0)
		return 0;

	int ret = 0, num = 0, lastnum = 0;
	//从低位到高位遍历
	for (int i = s.size() - 1; i >= 0; i--)
	{
		switch (s[i])
		{
		case 'I':
			num = 1;
			break;
		case 'V':
			num = 5;
			break;
		case 'X':
			num = 10;
			break;
		case 'L':
			num = 50;
			break;
		case 'C':
			num = 100;
			break;
		case 'D':
			num = 500;
			break;
		case 'M':
			num = 1000;
			break;
		}
		if (num < lastnum)
			ret -= num;//case for IV=4的情况
		else
			ret += num;
		lastnum = num;
	}
	return ret;
}

int main()
{
	cout << romanToInt("III") << endl;
	cout << romanToInt("IV") << endl;
	cout << romanToInt("IX") << endl;
	cout << romanToInt("MCMXCIV") << endl;
}