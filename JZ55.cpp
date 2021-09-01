/*
 * @Author: V4kst1z (dcydane@gmail.com)
 * @Date: 2021-08-28 12:10:13
 * @LastEditors: V4kst1z
 * @Description: JZ55 链表中环的入口结点
 * @FilePath: /CodingInterviews/JZ55.cpp
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
  ListNode *EntryNodeOfLoop(ListNode *pHead) {
    ListNode *fastH = pHead;
    ListNode *slowH = pHead;
    while (fastH && fastH->next) {
      fastH = fastH->next->next;
      slowH = slowH->next;
      if (fastH == slowH)
        break;
    }
    if (!fastH || !fastH->next)
      return nullptr;
    fastH = pHead;
    while (fastH != slowH) {
      fastH = fastH->next;
      slowH = slowH->next;
    }
    return fastH;
  }
};

int main() { return 0; }