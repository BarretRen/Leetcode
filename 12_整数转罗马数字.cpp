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
给定一个整数，将其转为罗马数字。输入确保在 1 到 3999 的范围内。
*/
#include <iostream>
#include <string>
using namespace std;

string intToRoman(int num)
{
	if (num == 0)
		return "";
	//参照附件的硬编码图，分别计算不同进位上1-9对应的字符
	string thousands[] = { "", "M", "MM", "MMM" };
	string hundreds[] = { "", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM" };
	string tens[] = { "", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC" };
	string ones[] = { "", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX" };

	return thousands[num / 1000] + hundreds[num % 1000 / 100] + tens[num % 100 / 10] + ones[num % 10];
}

int main()
{
	cout << intToRoman(3) << endl;
	cout << intToRoman(4) << endl;
	cout << intToRoman(9) << endl;
	cout << intToRoman(1994) << endl;
}