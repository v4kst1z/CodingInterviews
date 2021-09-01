/*
 * @Author: V4kst1z (dcydane@gmail.com)
 * @Date: 2021-08-28 10:19:05
 * @LastEditors: V4kst1z
 * @Description: JZ53 表示数值的字符串
 * @FilePath: /CodingInterviews/JZ53.cpp
 */

#include <iostream>

using namespace std;

class Solution {
public:
  /**
   * @param str string字符串
   * @return bool布尔型
   */
  bool isNumeric(string str) {
    int len = str.size();
    size_t idx = 0;
    bool hasSign = false, hasNum = false, hasE = false, hasDot = false;

    while (idx < len && str[idx] == ' ') {
      idx++;
    }
    if (str[idx] == '-' || str[idx] == '+') {
      hasSign = true;
      idx++;
    }

    while ((str[idx] >= '0' && str[idx] <= '9') || str[idx] == '.') {
      if (str[idx] == '.') {
        if (hasDot == true)
          return false;
        else {
          hasDot = true;
          if (idx + 1 < len) {
            if (str[idx + 1] >= '0' && str[idx + 1] <= '9')
              hasNum = true;
          }
        }
      } else {
        if (!hasDot && (str[idx] >= '0' && str[idx] <= '9'))
          hasNum = true;
      }
      idx++;
    }

    if (str[idx] == 'e' || str[idx] == 'E') {
      if (hasNum == false)
        return false;
      hasE = true;
      idx++;
      if (str[idx] == '-' || str[idx] == '+')
        idx++;
      if (!(str[idx] >= '0' && str[idx] <= '9'))
        return false;
    }
    while (str[idx] >= '0' && str[idx] <= '9') {
      idx++;
    }
    while (str[idx] == ' ') {
      idx++;
    }
    if (idx != len)
      return false;
    if (!hasNum)
      return false;
    return true;
  }
};

int main() {
  Solution sou;
  cout << sou.isNumeric("12e") << endl;
  return 0;
}