/*
 * @Author: V4kst1z (dcydane@gmail.com)
 * @Date: 2021-08-21 13:44:09
 * @LastEditors: V4kst1z
 * @Description: JZ18 二叉树的镜像
 * @FilePath: /CodingInterviews/JZ18.cpp
 */

#include <iostream>

using namespace std;

struct TreeNode {
  int val;
  struct TreeNode *left;
  struct TreeNode *right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
  /**
   * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
   *
   *
   * @param pRoot TreeNode类
   * @return TreeNode类
   */
  TreeNode *Mirror(TreeNode *pRoot) {
    if (!pRoot)
      return pRoot;

    swap(pRoot->left, pRoot->right);
    Mirror(pRoot->left);
    Mirror(pRoot->right);
    return pRoot;
  }
};

int main() { return 0; }