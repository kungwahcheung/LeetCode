/*
 * an example:
 * [
 *   ["1","0","1","0","0"],
 *   ["1","0","1","1","1"],
 *   ["1","1","1","1","1"],
 *   ["1","0","0","1","0"]
 * ]
 *
 * 策略: 把matrix看成多个直方图, 每一行及其上方的数据都构成一个直方图, 需要考察matrix.size()个直方图
 * 对于每个点(row, col), 我们最后都计算以这个点上方的连续的'1'往left, right方向延申可以得到的最大的矩形的面积
 * 通过这种方法获取的矩形一定会把最大的矩形包含在内
 * height[row][col]记录的是(row, col)这个坐标为底座的直方图柱子的高度, 如果这个点是'0', 那么高度当然是0了
 * left[row][col]记录的是(row, col)这个坐标点对应的height可以延申到的最左边的位置
 * right[row][col]记录的是(row, col)这个坐标点对应的height可以延申到的最右边的位置+1
 * 以上面的matrix为例, 
 * 对于(row=2, col=1)这个点, left=0, right=5, height=1
 * 对于(row=2, col=2)这个点, left=2, right=3, height=3
 * (2,2)这个点与(2,1)紧挨着,left和right却已经变化如此之大了, 这是因为left和right除了受左右两边的'1'影响, 还受到了其上方连续的'1'的制约
 * 由于点(2,2)上有height=3个'1', 这几个'1'的left的最小值作为当前点的left, 这几个'1'的right的最小值作为当前点的right
 * 因此, 实际上, 我们是要找以hight对应的这条线段往左右两边移动(只能往全是'1'的地方移动), 可以扫过的最大面积
 * 当hight与目标最大矩形区域的最短的height重合时, 最大矩形的面积就找到了, 如上面的例子, 就是点(2,3)或(2,4)对应的height
 */
#include <vector>
#include <iostream>

using std::vector;
using std::min;
using std::max;
using std::cout;
using std::endl;

class Solution {
 public:
  int maximalRectangle(vector<vector<char>>& matrix) {
    int max_area = 0;
    int row_num = matrix.size(), col_num = matrix[0].size();
    vector<int> height = vector<int> (col_num, 0);
    vector<int> left = vector<int> (col_num, 0);
    vector<int> right = vector<int> (col_num, col_num);
    for (int row = 0; row < row_num; ++row) {
      int cur_left = 0, cur_right = col_num;
      // update height
      for (int col = 0; col < col_num; ++col) {
        height[col] = matrix[row][col] == '0' ? 0 : height[col] + 1;
      }
      cout << "height:" << endl;;
      for (auto it : height) cout << it << '\t';
      cout << endl;
      // update left
      for (int col = 0; col < col_num; ++col) {
        if (matrix[row][col] == '0') {
          left[col] = 0;
          cur_left = col + 1;
        } else {
          left[col] = max(cur_left, left[col]);
        }
      }
      cout << "left:" << endl;
      for (auto it : left) cout << it << '\t';
      cout << endl;
      // update right
      for (int col = col_num - 1; col >= 0; --col) {
        if (matrix[row][col] == '0') {
          right[col] = col_num;
          cur_right = col;
        } else {
          right[col] = min(cur_right, right[col]);
        }
      }
      cout << "right:" << endl;
      for (auto it : right) cout << it << '\t';
      cout << endl;
      for (int col = 0; col < col_num; ++col) {
        max_area = max(max_area, height[col] * (right[col] - left[col]));
      }
      cout << "----------------" << endl;
    }
    return max_area;
  }
};

int main() {
  Solution sol = Solution();
  vector<vector<char>> matrix = 
  { {'1', '0', '1', '0', '0'},
    {'1', '0', '1', '1', '1'},
    {'1', '1', '1', '1', '1'},
    {'1', '0', '0', '1', '0'}
  };
  cout << sol.maximalRectangle(matrix) << endl;
  return 0;
}
