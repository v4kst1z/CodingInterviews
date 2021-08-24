/*
 * @Author: V4kst1z (dcydane@gmail.com)
 * @Date: 2021-08-20 20:45:55
 * @LastEditors: V4kst1z
 * @Description: JZ9 跳台阶扩展问题
 * @FilePath: /CodingInterviews/JZ09.cpp
 */

#include <iostream>
#include <numeric>
#include <vector>
using namespace std;
class Solution {
public:
  int jumpFloorII(int number) {
    vector<int> dp(number + 1, 0);
    dp[1] = 1;
    dp[2] = 2;

    for (int idx = 3; idx <= number; idx++) {
      dp[idx] = accumulate(dp.begin(), dp.begin() + idx, 0) + 1;
    }
    return dp[number];
  }
};

int main() {
  Solution sou;
  cout << sou.jumpFloorII(3) << endl;
}