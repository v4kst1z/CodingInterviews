/*
 * @Author: V4kst1z (dcydane@gmail.com)
 * @Date: 2021-08-24 16:41:52
 * @LastEditors: V4kst1z
 * @Description: JZ30 连续子数组的最大和
 * @FilePath: /CodingInterviews/JZ30.cpp
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int FindGreatestSumOfSubArray(vector<int> array) {
    int len = array.size();
    if (len == 0)
      return 0;

    vector<int> dp(len, 0);
    dp[0] = array[0];
    int max = dp[0];
    for (int id = 1; id < len; id++) {
      dp[id] = dp[id - 1] + array[id] > array[id] ? dp[id - 1] + array[id]
                                                  : array[id];
      max = std::max(max, dp[id]);
    }
    return max;
  }
};

int main() {
  Solution sou;
  cout << sou.FindGreatestSumOfSubArray({1, -2, 3, 10, -4, 7, 2, -5}) << endl;
  return 0;
}