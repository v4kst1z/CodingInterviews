/*
 * @Author: V4kst1z (dcydane@gmail.com)
 * @Date: 2021-08-27 10:29:34
 * @LastEditors: V4kst1z
 * @Description: JZ45 扑克牌顺子
 * @FilePath: /CodingInterviews/JZ45.cpp
 */

#include <iostream>
#include <set>
#include <vector>

using namespace std;

class Solution {
public:
  bool IsContinuous(vector<int> numbers) {
    int zeroNum = 0;
    set<int> numSet;
    for (auto num : numbers) {
      if (num == 0)
        zeroNum++;
      else
        numSet.insert(num);
    }
    if (numSet.size() + zeroNum != numbers.size())
      return false;

    if (zeroNum == 4)
      return true;
    if (!((*(--numSet.end()) - *numSet.begin()) > 4))
      return true;
    return false;
  }
};
int main() {
  Solution sou;
  cout << sou.IsContinuous({1, 3, 2, 6, 4}) << endl;
  return 0;
}