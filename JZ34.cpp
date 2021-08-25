/*
 * @Author: V4kst1z (dcydane@gmail.com)
 * @Date: 2021-08-25 15:01:27
 * @LastEditors: V4kst1z
 * @Description: JZ34 第一个只出现一次的字符
 * @FilePath: /CodingInterviews/JZ34.cpp
 */

#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
  int FirstNotRepeatingChar(string str) {
    unordered_map<char, int> numMp;
    for (auto chr : str)
      numMp[chr]++;
    for (size_t idx = 0; idx < str.size(); idx++)
      if (numMp[str[idx]] == 1)
        return idx;
    return -1;
  }
};

int main() {
  Solution sou;
  cout << sou.FirstNotRepeatingChar("google") << endl;
  return 0;
}