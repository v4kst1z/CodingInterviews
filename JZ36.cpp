/*
 * @Author: V4kst1z (dcydane@gmail.com)
 * @Date: 2021-08-25 20:35:31
 * @LastEditors: V4kst1z
 * @Description: JZ36 两个链表的第一个公共结点
 * @FilePath: /CodingInterviews/JZ36.cpp
 */

#include <iostream>

using namespace std;

struct ListNode {
  int val;
  struct ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
  ListNode *FindFirstCommonNode(ListNode *pHead1, ListNode *pHead2) {
    int len1 = 0, len2 = 0;
    ListNode *p1 = pHead1, *p2 = pHead2;
    while (p1) {
      p1 = p1->next;
      len1++;
    }
    while (p2) {
      p2 = p2->next;
      len2++;
    }
    p1 = pHead1;
    p2 = pHead2;
    if (len1 <= len2) {
      swap(p1, p2);
      swap(len1, len2);
    }

    int tmp = len1 - len2;
    while (tmp) {
      p1 = p1->next;
      tmp--;
    }
    while (p1) {
      if (p1 == p2)
        return p1;
      else {
        p1 = p1->next;
        p2 = p2->next;
      }
    }
    return nullptr;
  }
};

int main() { return 0; }