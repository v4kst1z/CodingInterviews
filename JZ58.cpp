/*
 * @Author: V4kst1z (dcydane@gmail.com)
 * @Date: 2021-08-28 19:13:59
 * @LastEditors: V4kst1z
 * @Description: JZ58 对称的二叉树
 * @FilePath: /CodingInterviews/JZ58.cpp
 */

#include <iostream>

using namespace std;

struct TreeNode {
  int val;
  struct TreeNode *left;
  struct TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
  bool isSame(TreeNode *pRoot1, TreeNode *pRoot2) {
    if (!pRoot1 && !pRoot2)
      return true;
    if (!pRoot1 || !pRoot2)
      return false;
    return pRoot1->val == pRoot2->val && isSame(pRoot1->left, pRoot2->right) &&
           isSame(pRoot1->right, pRoot2->left);
  }

public:
  bool isSymmetrical(TreeNode *pRoot) { return isSame(pRoot, pRoot); }
};

int main() { return 0; }