/*
 * @Author: V4kst1z (dcydane@gmail.com)
 * @Date: 2021-08-21 12:54:53
 * @LastEditors: V4kst1z
 * @Description: JZ17 树的子结构
 * @FilePath: /CodingInterviews/JZ17.cpp
 */

#include <iostream>
#include <queue>

using namespace std;

struct TreeNode {
  int val;
  struct TreeNode *left;
  struct TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
  bool equalTree(TreeNode *pRoot1, TreeNode *pRoot2) {
    if (pRoot2 == nullptr)
      return true;
    if (pRoot1 && pRoot2)
      if (pRoot1->val == pRoot2->val)
        return equalTree(pRoot1->left, pRoot2->left) &&
               equalTree(pRoot1->right, pRoot2->right);
    return false;
  }

public:
  bool HasSubtree(TreeNode *pRoot1, TreeNode *pRoot2) {
    if (!pRoot1 || !pRoot2)
      return false;
    queue<TreeNode *> qTreeNode;
    qTreeNode.push(pRoot1);
    bool res = false;
    while (qTreeNode.size()) {
      int num = qTreeNode.size();
      while (num) {
        TreeNode *node = qTreeNode.front();
        qTreeNode.pop();
        if (node->val == pRoot2->val)
          res |= equalTree(node, pRoot2);
        cout << node->val << " " << pRoot2->val << endl;
        if (res)
          return true;
        if (node->left)
          qTreeNode.push(node->left);
        if (node->right)
          qTreeNode.push(node->right);
        num--;
      }
    }
    return res;
  }
};

int main() { return 0; }