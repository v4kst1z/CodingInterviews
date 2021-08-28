/*
 * @Author: V4kst1z (dcydane@gmail.com)
 * @Date: 2021-08-25 20:48:44
 * @LastEditors: V4kst1z
 * @Description: JZ37 数字在升序数组中出现的次数
 * @FilePath: /CodingInterviews/JZ37.cpp
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
  int helper(vector<int> &data, int k, int begin, int end) {
    if (begin == end) {
      if (data[begin] == k)
        return 1;
      else
        return 0;
    }

    int mid = (begin + end) / 2;
    if (data[mid] > k)
      return helper(data, k, begin, mid);
    if (data[mid] < k)
      return helper(data, k, mid + 1, end);
    return helper(data, k, begin, mid) + helper(data, k, mid + 1, end);
  }

public:
  int GetNumberOfK(vector<int> data, int k) {
    if (!data.size())
      return 0;
    return helper(data, k, 0, data.size() - 1);
  }
};

int main() {
  Solution sou;
  cout << sou.GetNumberOfK({1, 2, 3, 3, 3, 3, 4, 5}, 3) << endl;
  return 0;
}