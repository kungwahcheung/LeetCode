#include <vector>
#include <iostream>

using std::vector;
using std::max;
using std::cout;
using std::endl;

class Solution {
 public:
  int largestRectangleArea(vector<int>& heights) {
    heights.push_back(0);
    vector<int> stack;
    int max_area = 0;
    for (int i = 0; i < heights.size(); i++) {
      while (stack.size() > 0 && heights[i] < heights[stack.back()]) {
        int cur_index = stack.back();  // 当前考虑的高度(的下标)
        stack.pop_back();
        // 当stack为空时, cur_index对应的height必定是heights[0,1,2,...,i-1]中最小的, 这时, width等于i.
        // 如果stack非空, 考虑的矩形的宽度对应的边为[stack.back()+1,stack.back()+2,...,i-1], 即width的左边从目前stack的最后一个元素(这是一个下标)对应的下一个位置开始, 到下标i-1结束.
        // 注意, 这个宽度不是[cur_index,...,i-1]对应的边, 思考heights={1,2,4,5,3}的情况, 当i为4时(即height=3准备入栈), while循环结束后, stack为[0,1,3],
        // 然后考虑高度为3的矩形, 下边长显然应该是3, 而不是1.
        int width = stack.empty() ? i : i - stack.back() - 1;  // key point
        max_area = max(heights[cur_index] * width, max_area);
      }
      stack.push_back(i);
    }
    return max_area;
  }
};

int main() {
  Solution sol = Solution();
  vector<int> heights = {2, 1, 5, 6, 2, 3};
  heights = {2, 1, 2};
  cout << sol.largestRectangleArea(heights) << endl;
  return 0;
}
