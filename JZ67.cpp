/*
 * @Author: V4kst1z (dcydane@gmail.com)
 * @Date: 2021-09-01 14:49:53
 * @LastEditors: V4kst1z
 * @Description: JZ67 剪绳子
 * @FilePath: /CodingInterviews/JZ67.cpp
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int cutRope(int number) {
    if (number == 2 || number == 3)
      return number - 1;
    vector<int> dp(number + 1, -1);
    for (int idx = 1; idx <= 4; idx++)
      dp[idx] = idx;
    for (int idx = 5; idx <= number; idx++) {
      for (int jdx = 1; jdx < idx; jdx++) {
        dp[idx] = max(dp[idx], jdx * dp[idx - jdx]);
      }
    }
    return dp[number];
  }
};

int main() {
  Solution sou;
  cout << sou.cutRope(8) << endl;
  return 0;
}