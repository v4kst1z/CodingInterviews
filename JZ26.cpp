/*
 * @Author: V4kst1z (dcydane@gmail.com)
 * @Date: 2021-08-21 19:39:11
 * @LastEditors: V4kst1z
 * @Description: JZ26 二叉搜索树与双向链表
 * @FilePath: /CodingInterviews/JZ26.cpp
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
  TreeNode *helper(TreeNode *pRootOfTree, bool isLeft) {
    if (!pRootOfTree->left && !pRootOfTree->right) // 叶节点
      return pRootOfTree;

    TreeNode *left = nullptr;
    TreeNode *right = nullptr;

    if (pRootOfTree->left)
      left = helper(pRootOfTree->left, true);
    if (pRootOfTree->right)
      right = helper(pRootOfTree->right, false);

    if (left) {
      left->right = pRootOfTree;
      pRootOfTree->left = left;
    }

    if (right) {
      right->left = pRootOfTree;
      pRootOfTree->right = right;
    }

    if (isLeft) {
      if (right) {
        while (right->right) {
          right = right->right;
        }
        return right;
      } else {
        return pRootOfTree;
      }
    } else {
      if (left) {
        while (left->left) {
          left = left->left;
        }
        return left;
      } else {
        return pRootOfTree;
      }
    }
  }

public:
  TreeNode *Convert(TreeNode *pRootOfTree) {
    if (!pRootOfTree)
      return nullptr;
    return helper(pRootOfTree, false);
  }
};

int main() { return 0; }