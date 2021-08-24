/*
 * @Author: V4kst1z (dcydane@gmail.com)
 * @Date: 2021-08-21 14:00:39
 * @LastEditors: V4kst1z
 * @Description: JZ19 顺时针打印矩阵
 * @FilePath: /CodingInterviews/JZ19.cpp
 */

// 描述
// 输入一个矩阵，按照从外向里以顺时针的顺序依次打印出
// 每一个数字，例如，如果输入如下4 X 4矩阵：
// [
//     [1,2,3,4],
//     [5,6,7,8],
//     [9,10,11,12],
//     [13,14,15,16]
// ]
// 则依次打印出数字
// [1,2,3,4,8,12,16,15,14,13,9,5,6,7,11,10]

#include <iostream>
#include <vector>

using namespace std;

class Solution {
  void print(vector<vector<int>> &matrix, int rowL, int rowH, int colL,
             int colH, vector<int> &res) {
    for (int idx = colL; idx <= colH; idx++)
      res.push_back(matrix[rowL][idx]);

    if (rowL == rowH)
      return;

    for (int idx = rowL + 1; idx <= rowH; idx++)
      res.push_back(matrix[idx][colH]);

    if (colH == colL)
      return;

    for (int idx = colH - 1; idx >= colL; idx--)
      res.push_back(matrix[rowH][idx]);

    for (int idx = rowH - 1; idx > rowL; idx--)
      res.push_back(matrix[idx][colL]);
  }

public:
  vector<int> printMatrix(vector<vector<int>> &matrix) {
    vector<int> res;
    if (matrix.empty() || matrix[0].empty())
      return res;
    int rowL = 0, rowH = matrix.size() - 1, colL = 0,
        colH = matrix[0].size() - 1;
    while (rowL <= rowH && colL <= colH) {
      print(matrix, rowL, rowH, colL, colH, res);
      if (colH == colL || rowL == rowH)
        break;
      if (rowL < rowH) {
        rowL++;
        rowH--;
      }
      if (colL < colH) {
        colL++;
        colH--;
      }
    }
    return res;
  }
};

int main() {
  Solution sou; ///[1,2,4,6,8,10,9,7,5,3]
  vector<vector<int>> tmp = {{1, 2}, {3, 4}, {5, 6}, {7, 8}, {9, 10}};
  auto res = sou.printMatrix(tmp);
  for (auto elem : res)
    cout << elem << " ";
  return 0;
}