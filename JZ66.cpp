/*
 * @Author: V4kst1z (dcydane@gmail.com)
 * @Date: 2021-09-01 14:36:28
 * @LastEditors: V4kst1z
 * @Description: JZ66 机器人的运动范围
 * @FilePath: /CodingInterviews/JZ66.cpp
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
  int count;
  void helper(int threshold, int rows, int cols, int idx, int jdx,
              vector<vector<bool>> &visited) {
    if (idx >= rows || idx < 0 || jdx >= cols || jdx < 0 || visited[idx][jdx])
      return;
    int sum = 0;
    int tmpIdx = idx, tmpJdx = jdx;
    while (tmpIdx || tmpJdx) {
      if (tmpIdx) {
        sum += (tmpIdx % 10);
        tmpIdx /= 10;
      }
      if (tmpJdx) {
        sum += (tmpJdx % 10);
        tmpJdx /= 10;
      }
    }
    if (sum > threshold)
      return;
    count++;
    visited[idx][jdx] = true;

    helper(threshold, rows, cols, idx + 1, jdx, visited);
    helper(threshold, rows, cols, idx - 1, jdx, visited);
    helper(threshold, rows, cols, idx, jdx + 1, visited);
    helper(threshold, rows, cols, idx, jdx - 1, visited);
  }

public:
  int movingCount(int threshold, int rows, int cols) {
    if (!rows || !cols)
      return 0;
    count = 0;
    vector<vector<bool>> visited(rows, vector<bool>(cols, false));
    helper(threshold, rows, cols, 0, 0, visited);
    return count;
  }
};

int main() {
  Solution sou;
  cout << sou.movingCount(5, 10, 10) << endl;
  return 0;
}