/*
题目大意：
给你两个非空的链表，表示两个非负的整数。它们每位数字都是按照 逆序 的方式存储的，并且每个节点只能存储一位数字。
请你将两个数相加，并以相同形式返回一个表示和的链表。你可以假设除了数字 0 之外，这两个数都不会以 0 开头。

解题思路：

*/
#include <iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
{
	if (l1 == nullptr || l2 == nullptr)
		return nullptr;

	ListNode* head = nullptr, * tail = nullptr;
	int carry = 0;
	while (l1 || l2) {
		int n1 = l1 ? l1->val : 0;
		int n2 = l2 ? l2->val : 0;
		int sum = n1 + n2 + carry;
		if (!head) {
			head = tail = new ListNode(sum % 10);
		}
		else {
			tail->next = new ListNode(sum % 10);
			tail = tail->next;
		}
		carry = sum / 10;
		if (l1) {
			l1 = l1->next;
		}
		if (l2) {
			l2 = l2->next;
		}
	}
	if (carry > 0) {
		tail->next = new ListNode(carry);
	}
	return head;
}

int main()
{
	ListNode l1(2), a(4), b(3);
	l1.next = &a;
	a.next = &b;

	ListNode l2(5), d(6), e(4);
	l2.next = &d;
	d.next = &e;

	ListNode* ret = addTwoNumbers(&l1, &l2);
	while (ret != nullptr)
	{
		cout << ret->val << "\t";
		ret = ret->next;
	}
}