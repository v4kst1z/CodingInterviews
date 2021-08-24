/*
 * @Author: V4kst1z (dcydane@gmail.com)
 * @Date: 2021-08-21 15:39:43
 * @LastEditors: V4kst1z
 * @Description: JZ21 栈的压入、弹出序列
 * @FilePath: /CodingInterviews/JZ21.cpp
 */

// 描述
// 输入两个整数序列，第一个序列表示栈的压入顺序，请判断第
// 二个序列是否可能为该栈的弹出顺序。假设压入栈的所有数字
// 均不相等。例如序列1,2,3,4,5是某栈的压入顺序，序
// 列4,5,3,2,1是该压栈序列对应的一个弹出序列，但4,3,5,1,2就不
// 可能是该压栈序列的弹出序列。（注意：这两个序列的长度是相等的）

// 示例1
// 输入：[1,2,3,4,5],[4,3,5,1,2]
// 返回值：false

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  bool IsPopOrder(vector<int> pushV, vector<int> popV) {
    if (pushV.size() == 0)
      return false;
    vector<int> stack;
    for (int id = 0, jd = 0; id < pushV.size(); id++) {
      stack.push_back(pushV[id]);
      while (jd < popV.size() && stack.back() == popV[jd]) {
        stack.pop_back();
        jd++;
      }
    }
    return stack.empty();
  }
};

int main() {
  Solution sou;
  vector<int> pushV{1, 2, 3, 4, 5};
  vector<int> popV{4, 5, 3, 2, 1};
  cout << sou.IsPopOrder(pushV, popV) << endl;
  return 0;
}