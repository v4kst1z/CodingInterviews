/*
 * @Author: V4kst1z (dcydane@gmail.com)
 * @Date: 2021-08-26 13:40:11
 * @LastEditors: V4kst1z
 * @Description: JZ39 平衡二叉树
 * @FilePath: /CodingInterviews/JZ39.cpp
 */

#include <iostream>

using namespace std;

struct TreeNode {
  int val;
  struct TreeNode *left;
  struct TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/*
{1,2,3,4,5,#,6,#,#,7}
             1
            2 3
          4  5 # 6
         # # 7
*/

class Solution {
private:
  bool isBBT;
  int helper(TreeNode *pRoot) {
    if (!isBBT)
      return 0;
    if (!pRoot->left && !pRoot->right)
      return 0;
    int leftDep = 0;
    int rightDep = 0;

    if (pRoot->left)
      leftDep = helper(pRoot->left) + 1;
    if (pRoot->right)
      rightDep = helper(pRoot->right) + 1;
    if (abs(leftDep - rightDep) > 1)
      isBBT = false;
    return max(leftDep, rightDep);
  }

public:
  bool IsBalanced_Solution(TreeNode *pRoot) {
    if (!pRoot)
      return true;
    isBBT = true;
    helper(pRoot);
    return isBBT;
  }
};

int main() { return 0; }