/*
 * @Author: V4kst1z (dcydane@gmail.com)
 * @Date: 2021-08-27 12:05:57
 * @LastEditors: V4kst1z
 * @Description: JZ50 数组中重复的数字
 * @FilePath: /CodingInterviews/JZ50.cpp
 */

#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
  /**
   * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
   *
   *
   * @param numbers int整型vector
   * @return int整型
   */
  int duplicate(vector<int> &numbers) {
    unordered_set<int> numSet;
    for (auto num : numbers) {
      if (numSet.count(num))
        return num;
      else
        numSet.insert(num);
    }
    return -1;
  }
};

int main() {
  Solution sou;
  vector<int> arr{2, 3, 1, 0, 2, 5, 3};
  cout << sou.duplicate(arr) << endl;
  return 0;
}
