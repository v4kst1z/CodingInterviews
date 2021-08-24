/*
 * @Author: V4kst1z (dcydane@gmail.com)
 * @Date: 2021-08-21 12:21:59
 * @LastEditors: V4kst1z
 * @Description: JZ15 反转链表
 * @FilePath: /CodingInterviews/JZ15.cpp
 */

// 描述
// 输入一个链表，反转链表后，输出新链表的表头。

#include <iostream>

using namespace std;

struct ListNode {
  int val;
  struct ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
  ListNode *ReverseList(ListNode *pHead) {
    ListNode *res = new ListNode(0);
    while (pHead) {
      auto *next = res->next;
      auto *val = new ListNode(pHead->val);
      val->next = next;
      res->next = val;
      pHead = pHead->next;
    }
    return res->next;
  }
};

int main() {
  Solution sou;
  ListNode *node1 = new ListNode(1);
  ListNode *node2 = new ListNode(2);
  ListNode *node3 = new ListNode(3);
  node1->next = node2;
  node2->next = node3;

  auto *pHead = sou.ReverseList(node1);
  while (pHead) {
    cout << pHead->val << " ";
    pHead = pHead->next;
  }

  delete node1;
  delete node2;
  delete node3;
  return 0;
}