#include <algorithm>  // min, max
#include <iostream>
#include <string>
#include <vector>

#include <cassert>  // assert

using namespace std;

class Solution {
 public:
  int maxArea(vector<int>& height) {
    int res = 0;
    int left = 0, right = height.size() - 1;
    while(left < right){
      res = max(res, (right - left) * min(height[left], height[right]));
      if (height[left] < height[right]) {
        ++left;
      } else {
        --right;
      }
    }
  return res;
  }
};


int main() {
  Solution sol = Solution();
  vector<int> height{1, 8, 6, 2, 5, 4, 8, 3, 7};
  assert(sol.maxArea(height) == 49);
  return 0;
}
