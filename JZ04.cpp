/*
 * @Author: V4kst1z (dcydane@gmail.com)
 * @Date: 2021-08-20 17:17:56
 * @LastEditors: V4kst1z
 * @Description: JZ4 重建二叉树
 * @FilePath: /CodingInterviews/JZ04.cpp
 */

#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;

// Definition for binary tree
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
  TreeNode *reConstructBinaryTree(vector<int> pre, vector<int> vin) {
    int len = pre.size();
    if (len == 0)
      return nullptr;

    TreeNode *ret = new TreeNode(pre[0]);
    unordered_map<int, int> valMap;
    for (int idx = 0; idx < vin.size(); idx++)
      valMap.insert({vin[idx], idx});

    vector<int> leftPre, leftVin, rightPre, rightVin;
    for (int idx = 1; idx < pre.size(); idx++) {
      if (valMap[pre[idx]] < valMap[pre[0]])
        leftPre.push_back(pre[idx]);
      else
        rightPre.push_back(pre[idx]);
    }

    for (int idx = 0; idx < vin.size(); idx++) {
      if (valMap[vin[idx]] < valMap[pre[0]])
        leftVin.push_back(vin[idx]);
      if (valMap[vin[idx]] > valMap[pre[0]])
        rightVin.push_back(vin[idx]);
    }
    ret->left = reConstructBinaryTree(leftPre, leftVin);
    ret->right = reConstructBinaryTree(rightPre, rightVin);
    return ret;
  }
};

int main() {
  Solution sou;
  vector<int> pre{1, 2, 4, 7, 3, 5, 6, 8};
  vector<int> vin{4, 7, 2, 1, 5, 3, 8, 6};
  TreeNode *res = sou.reConstructBinaryTree(pre, vin);
  queue<TreeNode *> qNode;
  qNode.push(res);
  while (qNode.size()) {
    int num = qNode.size();
    while (num > 0) {
      TreeNode *node = qNode.front();
      qNode.pop();

      cout << node->val << " ";
      if (node->left)
        qNode.push(node->left);

      if (node->right)
        qNode.push(node->right);

      num--;
    }
    cout << "\n";
  }
  return 0;
}
