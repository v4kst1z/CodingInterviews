/*
 * @Author: V4kst1z (dcydane@gmail.com)
 * @Date: 2021-08-27 11:57:55
 * @LastEditors: V4kst1z
 * @Description: JZ49 把字符串转换成整数
 * @FilePath: /CodingInterviews/JZ49.cpp
 */

#include <iostream>

using namespace std;

class Solution {
public:
  int StrToInt(string str) {
    int flag = str[0] != '-' ? 1 : -1;
    int ret = 0;
    for (int idx = 0; idx < str.size(); idx++) {
      if (idx == 0 && (str[idx] == '+' || str[0] == '-')) {
        continue;
      }
      if (str[idx] >= '0' && str[idx] <= '9') {
        ret = ret * 10 + (str[idx] - '0');
      } else {
        return 0;
      }
    }
    return flag * ret;
  }
};

int main() {
  Solution sou;
  cout << sou.StrToInt("+2147483647") << endl;
  return 0;
}