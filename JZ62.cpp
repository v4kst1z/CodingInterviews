/*
 * @Author: V4kst1z (dcydane@gmail.com)
 * @Date: 2021-08-29 13:01:40
 * @LastEditors: V4kst1z
 * @Description: JZ62 二叉搜索树的第k个结点
 * @FilePath: /CodingInterviews/JZ62.cpp
 */

#include <iostream>
#include <stack>

using namespace std;

struct TreeNode {
  int val;
  struct TreeNode *left;
  struct TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// {5,3,7,2,4,6,8},
//     5
//    3  7
//  2  4 6 8
// class Solution {
// private:
//   int idx;
//   TreeNode *helper(TreeNode *pRoot, int k) {
//     if (!pRoot)
//       return nullptr;
//     auto *p1 = helper(pRoot->left, k);
//     idx++;
//     if (idx == k)
//       return pRoot;
//     auto *p2 = helper(pRoot->right, k);
//     if (p1)
//       return p1;
//     if (p2)
//       return p2;
//     return nullptr;
//   }

// public:
//   TreeNode *KthNode(TreeNode *pRoot, int k) {
//     idx = 0;
//     return helper(pRoot, k);
//   }
// };

class Solution {
private:
  int idx;

public:
  TreeNode *KthNode(TreeNode *pRoot, int k) {
    if (!pRoot)
      return nullptr;
    idx = 0;
    stack<TreeNode *> stackNode;

    while (pRoot || !stackNode.empty()) {
      if (pRoot) {
        stackNode.push(pRoot);
        pRoot = pRoot->left;
      } else {
        pRoot = stackNode.top();
        stackNode.pop();
        idx++;
        if (idx == k)
          return pRoot;
        pRoot = pRoot->right;
      }
    }
    return nullptr;
  }
};

int main() { return 0; }