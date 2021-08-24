/*
 * @Author: V4kst1z (dcydane@gmail.com)
 * @Date: 2021-08-20 17:00:06
 * @LastEditors: V4kst1z
 * @Description: JZ3 从尾到头打印链表
 * @FilePath: /CodingInterviews/JZ03.cpp
 */

// 描述
// 输入一个链表的头节点，按链表从尾到头的顺序返回每个节
// 点的值（用数组返回）。

// 如输入{1,2,3}的链表, 返回一个数组为[3,2,1]

// 0 <= 链表长度 <= 10000

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
  int val;
  struct ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

// class Solution {
// public:
//   vector<int> printListFromTailToHead(ListNode *head) {
//     vector<int> res;
//     while (head) {
//       res.push_back(head->val);
//       head = head->next;
//     }
//     reverse(res.begin(), res.end());
//     return res;
//   }
// };

class Solution {
private:
  void visit(ListNode *head, vector<int> &res) {
    if (head->next)
      visit(head->next, res);
    res.push_back(head->val);
  }

public:
  vector<int> printListFromTailToHead(ListNode *head) {
    vector<int> res;
    if (head)
      visit(head, res);
    return res;
  }
};

int main() {
  Solution sou;
  ListNode *node1 = new ListNode(1);
  ListNode *node2 = new ListNode(2);
  ListNode *node3 = new ListNode(3);
  node1->next = node2;
  node2->next = node3;
  auto arr = sou.printListFromTailToHead(node1);
  for (auto elem : arr)
    cout << elem << " ";
  delete node1;
  delete node2;
  delete node3;
  return 0;
}
