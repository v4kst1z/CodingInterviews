/*
 * @Author: V4kst1z (dcydane@gmail.com)
 * @Date: 2021-08-28 15:13:21
 * @LastEditors: V4kst1z
 * @Description: JZ56 删除链表中重复的结点
 * @FilePath: /CodingInterviews/JZ56.cpp
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
  ListNode *deleteDuplication(ListNode *pHead) {
    ListNode *pNode = pHead;
    ListNode *preNode = nullptr;
    while (pNode) {
      int curr = pNode->val;
      ListNode *pNext = pNode->next;
      while (pNext) {
        if (pNext->val == curr) {
          pNext = pNext->next;
        } else
          break;
      }
      if (pNode->next != pNext) {
        while (pNode != pNext) {
          ListNode *tmp = pNode;
          pNode = pNode->next;
          delete tmp;
        }
        if (!preNode) {
          pHead = pNext;
        } else {
          preNode->next = pNext;
        }
      } else {
        preNode = pNode;
        pNode = pNode->next;
      }
    }
    return pHead;
  }
};

int main() { return 0; }