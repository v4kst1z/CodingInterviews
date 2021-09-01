/*
 * @Author: V4kst1z (dcydane@gmail.com)
 * @Date: 2021-08-28 15:53:38
 * @LastEditors: V4kst1z
 * @Description: JZ57 二叉树的下一个结点
 * @FilePath: /CodingInterviews/JZ57.cpp
 */

#include <iostream>

using namespace std;

struct TreeLinkNode {
  int val;
  struct TreeLinkNode *left;
  struct TreeLinkNode *right;
  struct TreeLinkNode *next;
  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};
// {8,6,10,5,7,9,11},5
//          8
//        6   10
//      5  7 9  11
class Solution {
public:
  TreeLinkNode *GetNext(TreeLinkNode *pNode) {
    if (!pNode)
      return pNode;

    if (pNode->right) {
      TreeLinkNode *tNode = pNode->right;
      while (tNode->left) {
        tNode = tNode->left;
      }
      return tNode;
    }

    while (pNode->next) {
      TreeLinkNode *parent = pNode->next;
      if (parent->left == pNode) {
        return parent;
      }
      pNode = pNode->next;
    }
    return pNode->next;
  }
};

int main() { return 0; }