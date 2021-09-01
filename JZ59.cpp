/*
 * @Author: V4kst1z (dcydane@gmail.com)
 * @Date: 2021-08-28 23:17:52
 * @LastEditors: V4kst1z
 * @Description: JZ59 按之字形顺序打印二叉树
 * @FilePath: /CodingInterviews/JZ59.cpp
 */

#include <algorithm>
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
    bool flag = true;
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
      if (!flag)
        reverse(tmp.begin(), tmp.end());
      flag = !flag;
      res.emplace_back(std::move(tmp));
    }
    return res;
  }
};

int main() { return 0; }