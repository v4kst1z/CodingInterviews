/*
 * @Author: V4kst1z (dcydane@gmail.com)
 * @Date: 2021-08-21 11:58:21
 * @LastEditors: V4kst1z
 * @Description: JZ14 链表中倒数最后k个结点
 * @FilePath: /CodingInterviews/JZ14.cpp
 */

#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
  int val;
  struct ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
  /**
   * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
   *
   *
   * @param pHead ListNode类
   * @param k int整型
   * @return ListNode类
   */
  ListNode *FindKthToTail(ListNode *pHead, int k) {
    ListNode *firstHead = pHead;
    while (k > 0 && firstHead) {
      firstHead = firstHead->next;
      k--;
    }

    if (k > 0)
      return nullptr;
    while (firstHead) {
      firstHead = firstHead->next;
      pHead = pHead->next;
    }
    return pHead;
  }
};

int main() {
  Solution sou;
  ListNode *node1 = new ListNode(1);
  ListNode *node2 = new ListNode(2);
  ListNode *node3 = new ListNode(3);
  ListNode *node4 = new ListNode(4);
  ListNode *node5 = new ListNode(5);
  node1->next = node2;
  node2->next = node3;
  node3->next = node4;
  node4->next = node5;

  auto *node = sou.FindKthToTail(node1, 6);
  if (node)
    cout << node->val << endl;
  delete node1;
  delete node2;
  delete node3;
  delete node4;
  delete node5;

  return 0;
}