/*
 * @Author: V4kst1z (dcydane@gmail.com)
 * @Date: 2021-08-21 17:23:05
 * @LastEditors: V4kst1z
 * @Description: JZ22 从上往下打印二叉树
 * @FilePath: /CodingInterviews/JZ22.cpp
 */

// 描述
// 从上往下打印出二叉树的每个节点，同层节点从左至右打印。

// 示例1
// 输入：{5,4,#,3,#,2,#,1}
// 返回值：[5,4,3,2,1]

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
  vector<int> PrintFromTopToBottom(TreeNode *root) {
    vector<int> res;
    if (!root)
      return res;
    queue<TreeNode *> qNode;
    qNode.push(root);
    while (qNode.size()) {
      int num = qNode.size();
      while (num) {
        auto *node = qNode.front();
        qNode.pop();
        res.push_back(node->val);
        if (node->left)
          qNode.push(node->left);
        if (node->right)
          qNode.push(node->right);
        num--;
      }
    }
    return res;
  }
};

int main() {
  Solution sou;
  return 0;
}