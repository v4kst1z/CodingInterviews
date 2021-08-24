/*
 * @Author: V4kst1z (dcydane@gmail.com)
 * @Date: 2021-08-21 18:02:21
 * @LastEditors: V4kst1z
 * @Description: JZ24 二叉树中和为某一值的路径
 * @FilePath: /CodingInterviews/JZ24.cpp
 */

// 描述
// 输入一颗二叉树的根节点和一个整数，按字典序打印出二叉树中结
// 点值的和为输入整数的所有路径。路径定义为从树的根结点开始往
// 下一直到叶结点所经过的结点形成一条路径。

// 示例1
// 输入：{10,5,12,4,7},22
// 返回值： [[10,5,7],[10,12]]

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
private:
  vector<vector<int>> res;
  void dfsTree(TreeNode *root, int expectNumber, vector<int> path) {
    path.push_back(root->val);

    if (!root->left && expectNumber == root->val) {
      res.push_back(path);
      return;
    }
    if (root->left)
      dfsTree(root->left, expectNumber - root->val, path);

    if (!root->right && expectNumber == root->val) {
      res.push_back(path);
      return;
    }
    if (root->right)
      dfsTree(root->right, expectNumber - root->val, path);

    path.pop_back();
  }

public:
  vector<vector<int>> FindPath(TreeNode *root, int expectNumber) {
    if (!root)
      return {};
    res = {};
    vector<int> path = {};
    dfsTree(root, expectNumber, path);
    return res;
  }
};

int main() { return 0; }