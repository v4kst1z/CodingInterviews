/*
 * @Author: V4kst1z (dcydane@gmail.com)
 * @Date: 2021-08-28 23:31:55
 * @LastEditors: V4kst1z
 * @Description: JZ60 把二叉树打印成多行
 * @FilePath: /CodingInterviews/JZ60.cpp
 */

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct TreeNode {
  int val;
  struct TreeNode *left;
  struct TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
  vector<vector<int>> Print(TreeNode *pRoot) {
    if (!pRoot)
      return {};
    vector<vector<int>> res;
    queue<TreeNode *> qNode;
    qNode.push(pRoot);
    while (qNode.size()) {
      int num = qNode.size();
      vector<int> tmp;
      while (num) {
        TreeNode *node = qNode.front();
        qNode.pop();
        tmp.push_back(node->val);

        if (node->left)
          qNode.push(node->left);

        if (node->right)
          qNode.push(node->right);
        num--;
      }

      res.push_back(tmp);
    }
    return res;
  }
};

int main() { return 0; }