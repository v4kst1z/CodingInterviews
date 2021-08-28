/*
 * @Author: V4kst1z (dcydane@gmail.com)
 * @Date: 2021-08-26 23:58:12
 * @LastEditors: V4kst1z
 * @Description: JZ44 翻转单词序列
 * @FilePath: /CodingInterviews/JZ44.cpp
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  string ReverseSentence(string str) {
    int len = str.size();
    if (!len)
      return "";

    string delimiter = " ";
    size_t pos = 0;
    vector<string> strArr;
    while ((pos = str.find(delimiter)) != string::npos) {
      strArr.push_back(str.substr(0, pos));
      str.erase(0, pos + 1);
    }
    strArr.push_back(str);
    str = "";
    for (auto &s : strArr) {
      if (str.empty())
        str = s + str;
      else
        str = s + " " + str;
    }

    return str;
  }
};

int main() {
  Solution sou;
  cout << sou.ReverseSentence("nowcoder. a am I") << endl;
  return 0;
}