/*
 * @Author: V4kst1z (dcydane@gmail.com)
 * @Date: 2021-08-24 14:20:53
 * @LastEditors: V4kst1z
 * @Description: JZ28 数组中出现次数超过一半的数字
 * @FilePath: /CodingInterviews/JZ28.cpp
 */

#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
  int MoreThanHalfNum_Solution(vector<int> numbers) {
    unordered_map<int, int> numMp;
    for (auto elem : numbers) {
      numMp[elem]++;
      if (numMp[elem] > numbers.size() / 2)
        return elem;
    }
    return 0;
  }
};

int main() {
  Solution sou;
  return 0;
}