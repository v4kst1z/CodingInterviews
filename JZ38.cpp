/*
 * @Author: V4kst1z (dcydane@gmail.com)
 * @Date: 2021-08-26 13:34:57
 * @LastEditors: V4kst1z
 * @Description: JZ38 二叉树的深度
 * @FilePath: /CodingInterviews/JZ38.cpp
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
  void helper(TreeNode *pRoot, int dep, int &res) {
    if (!pRoot->left && !pRoot->right) {
      res = max(res, dep + 1);
    }
    if (pRoot->left)
      helper(pRoot->left, dep + 1, res);

    if (pRoot->right)
      helper(pRoot->right, dep + 1, res);
  }

public:
  int TreeDepth(TreeNode *pRoot) {
    int res = 0;
    if (!pRoot)
      return 0;
    helper(pRoot, 0, res);
    return res;
  }
};

int main() { return 0; }
