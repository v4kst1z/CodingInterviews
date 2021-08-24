/*
 * @Author: V4kst1z (dcydane@gmail.com)
 * @Date: 2021-08-21 12:42:16
 * @LastEditors: V4kst1z
 * @Description: JZ16 合并两个排序的链表
 * @FilePath: /CodingInterviews/JZ16.cpp
 */

// 描述
// 输入两个单调递增的链表，输出两个链表合成后的链
// 表，当然我们需要合成后的链表满足单调不减规则。

// 示例1
// 输入： {1,3,5},{2,4,6}
// 返回值： {1,2,3,4,5,6}
#include <iostream>

using namespace std;

struct ListNode {
  int val;
  struct ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
  ListNode *Merge(ListNode *pHead1, ListNode *pHead2) {
    ListNode *dummyHead = new ListNode(0);
    ListNode *pHead = dummyHead;
    while (pHead1 || pHead2) {
      if (!pHead1) {
        pHead->next = pHead2;
        pHead2 = nullptr;
        break;
      }

      if (!pHead2) {
        pHead->next = pHead1;
        pHead1 = nullptr;
        break;
      }

      if (pHead1->val <= pHead2->val) {
        pHead->next = new ListNode(pHead1->val);
        pHead1 = pHead1->next;
      } else {
        pHead->next = new ListNode(pHead2->val);
        pHead2 = pHead2->next;
      }
      pHead = pHead->next;
    }
    return dummyHead->next;
  }
};

int main() {
  Solution sou;
  auto *node1 = new ListNode(1);
  auto *node3 = new ListNode(3);
  auto *node5 = new ListNode(5);
  node1->next = node3;
  node3->next = node5;

  auto *node2 = new ListNode(2);
  auto *node4 = new ListNode(4);
  auto *node6 = new ListNode(6);
  node2->next = node4;
  node4->next = node6;

  auto *node = sou.Merge(node1, node2);
  while (node) {
    cout << node->val << " ";
    node = node->next;
  }

  delete node1;
  delete node2;
  delete node3;
  delete node4;
  delete node5;
  delete node6;
  return 0;
}