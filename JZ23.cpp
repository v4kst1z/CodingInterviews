/*
 * @Author: V4kst1z (dcydane@gmail.com)
 * @Date: 2021-08-21 17:30:45
 * @LastEditors: V4kst1z
 * @Description: JZ23 二叉搜索树的后序遍历序列
 * @FilePath: /CodingInterviews/JZ23.cpp
 */

// 描述
// 输入一个整数数组，判断该数组是不是某二叉搜索树的后
// 序遍历的结果。如果是则返回true,否则返回false。假设输入的
// 数组的任意两个数字都互不相同。（ps：我们约定空树不是二叉搜索树）

// 示例1
// 输入：[4,8,6,12,16,14,10]
// 返回值：true

#include <iostream>
#include <vector>
using namespace std;

class Solution {
  bool isBST(int *arr, int len) {
    if (len == 0 || len == 1)
      return true;

    int root = *(arr + len - 1);
    int lenArr1 = 0, lenArr2 = 0;
    int id = 0;
    for (; id < len; id++) {
      if (*(arr + id) < root)
        lenArr1++;
      else
        break;
    }
    for (; id < len - 1; id++) {
      if (*(arr + id) > root)
        lenArr2++;
      else if (*(arr + id) < root)
        return false;
    }
    return isBST(arr, lenArr1) && isBST(arr + lenArr1, lenArr2);
  }

public:
  bool VerifySquenceOfBST(vector<int> &sequence) {
    if (sequence.empty())
      return false;
    return isBST(sequence.data(), sequence.size());
  }
};

int main() {
  Solution sou;
  vector<int> tmp{5, 4, 3, 2, 1};
  cout << sou.VerifySquenceOfBST(tmp) << endl;
  return 0;
}