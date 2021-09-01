/*
 * @Author: V4kst1z (dcydane@gmail.com)
 * @Date: 2021-08-28 11:26:09
 * @LastEditors: V4kst1z
 * @Description: JZ54 字符流中第一个不重复的字符
 * @FilePath: /CodingInterviews/JZ54.cpp
 */

#include <iostream>
#include <map>

using namespace std;

class Solution {
private:
  char firstChar = '#';
  map<char, int> chrMp;

public:
  // Insert one char from stringstream
  void Insert(char ch) {
    chrMp[ch]++;

    if ((ch == firstChar && chrMp[ch] > 1) || firstChar == '#') {
      auto it = chrMp.begin();
      while (it != chrMp.end()) {
        if (it->second == 1) {
          firstChar = it->first;
          break;
        } else
          firstChar = '#';
        it++;
      }
      return;
    }
  }
  // return the first appearence once char in current stringstream
  char FirstAppearingOnce() { return firstChar; }
};

int main() {
  Solution sou;
  sou.Insert('g');
  sou.Insert('o');
  sou.Insert('o');
  sou.Insert('g');
  sou.Insert('l');

  cout << sou.FirstAppearingOnce() << endl;
  return 0;
}