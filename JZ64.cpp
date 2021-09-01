/*
 * @Author: V4kst1z (dcydane@gmail.com)
 * @Date: 2021-09-01 11:18:20
 * @LastEditors: V4kst1z
 * @Description: JZ64 滑动窗口的最大值
 * @FilePath: /CodingInterviews/JZ64.cpp
 */

#include <deque>
#include <iostream>
#include <vector>

using namespace std;

// class Solution {
// public:
//   vector<int> maxInWindows(const vector<int> &num, unsigned int size) {
//     vector<int> ret;
//     int len = num.size();
//     if (len == 0 || size < 1 || len < size)
//       return ret;
//     for (int idx = 0, jdx = idx + size; jdx <= len; idx++, jdx++) {
//         int maxVal = INT32_MIN;
//         for(int kdx = idx; kdx < jdx; kdx++) {
//             maxVal = max(maxVal, num[kdx]);
//         }
//         ret.push_back(maxVal);
//     }
//     return ret;
//   }
// };

class Solution {
public:
  vector<int> maxInWindows(const vector<int> &num, unsigned int size) {
    vector<int> ret;
    if (num.size() == 0 || size < 1 || num.size() < size)
      return ret;
    int n = num.size();
    deque<int> dq;
    for (int i = 0; i < n; ++i) {
      while (!dq.empty() && num[dq.back()] < num[i]) {
        dq.pop_back();
      }
      dq.push_back(i);
      // 判断队列的头部的下标是否过期
      if (dq.front() + size <= i) {
        dq.pop_front();
      }
      // 判断是否形成了窗口
      if (i + 1 >= size) {
        ret.push_back(num[dq.front()]);
      }
    }
    return ret;
  }
};
int main() { return 0; }