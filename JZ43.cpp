/*
 * @Author: V4kst1z (dcydane@gmail.com)
 * @Date: 2021-08-26 23:50:15
 * @LastEditors: V4kst1z
 * @Description: JZ43 左旋转字符串
 * @FilePath: /CodingInterviews/JZ43.cpp
 */

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
  string LeftRotateString(string str, int n) {
    int len = str.size();
    if (!len)
      return "";
    n %= len;
    return str.substr(n) + str.substr(0, n);
  }
};

int main() {
  Solution sou;
  cout << sou.LeftRotateString("abcXYZdef", 3) << endl;
  return 0;
}