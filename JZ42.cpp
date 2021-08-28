/*
 * @Author: V4kst1z (dcydane@gmail.com)
 * @Date: 2021-08-26 23:36:54
 * @LastEditors: V4kst1z
 * @Description: JZ42 和为S的两个数字
 * @FilePath: /CodingInterviews/JZ42.cpp
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> FindNumbersWithSum(vector<int> array, int sum) {
    int l = 0, r = array.size() - 1;
    vector<int> res;
    int product = INT32_MAX;
    while (l < r) {
      if ((array[l] + array[r]) > sum) {
        r--;
        continue;
      }

      if ((array[l] + array[r]) < sum) {
        l++;
        continue;
      }

      if ((array[l] + array[r]) == sum) {
        if (product > (array[l] + array[r])) {
          product = (array[l] + array[r]);
          res = {array[l], array[r]};
        }
        l++;
        r--;
        continue;
      }
    }
    return res;
  }
};

int main() {
  Solution sou;
  auto arr = sou.FindNumbersWithSum({1, 2, 4, 7, 11, 15}, 15);
  for (auto num : arr)
    cout << num << " ";
}