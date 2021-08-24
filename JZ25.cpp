/*
 * @Author: V4kst1z (dcydane@gmail.com)
 * @Date: 2021-08-21 19:08:34
 * @LastEditors: V4kst1z
 * @Description: JZ25 复杂链表的复制
 * @FilePath: /CodingInterviews/JZ25.cpp
 */

#include <iostream>
#include <unordered_map>

using namespace std;

struct RandomListNode {
  int label;
  struct RandomListNode *next, *random;
  RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

class Solution {
public:
  RandomListNode *Clone(RandomListNode *pHead) {
    if (pHead == nullptr)
      return nullptr;
    unordered_map<RandomListNode *, RandomListNode *> nodeMap;
    RandomListNode *p = pHead;
    RandomListNode *prev = nullptr;
    while (p) {
      RandomListNode *node = new RandomListNode(p->label);
      nodeMap.insert({p, node});

      if (prev) {
        nodeMap[prev]->next = node;
      }

      prev = p;
      p = p->next;
    }
    p = pHead;
    while (p) {
      if (p->random) {
        nodeMap[p]->random = nodeMap[p->random];
      }
      p = p->next;
    }
    return nodeMap[pHead];
  }
};

int main() { return 0; }