/*
 * @Author: V4kst1z (dcydane@gmail.com)
 * @Date: 2021-08-20 16:47:43
 * @LastEditors: V4kst1z
 * @Description: JZ2 替换空格
 * @FilePath: /CodingInterviews/JZ02.cpp
 */

// 描述
// 请实现一个函数，将一个字符串中的每个空格替换成“%20”。例
// 如，当字符串为We Are Happy.则经过替换之后的字符串为We
// %20Are%20Happy。

#include <iostream>

using namespace std;

class Solution {
public:
  /**
   * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
   *
   *
   * @param s string字符串
   * @return string字符串
   */
  string replaceSpace(string s) {
    int idx = 0;
    while (true) {
      if (idx == s.size())
        return s;
      for (; idx < s.size(); idx++) {
        if (s[idx] == ' ') {
          s = s.substr(0, idx) + "%20" + s.substr(idx + 1);
          break;
        }
      }
    }
  }
};

int main() {
  Solution sou;
  cout << sou.replaceSpace("We Are Happy") << endl;
  return 0;
}
