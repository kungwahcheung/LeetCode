#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*
 * for any a <= b, if c < 0 ==> ac >= bc
 */

class Solution {
 public:
  /* 这个解法直接看代码非常难理解, 实际运用的还是DP的思想
   * 关键是需要理解imax/imin保存的是以nums[i]结尾的子数组的最大/最小乘积 */
  int maxProduct(vector<int>& nums) {
    // store the result that is the max we have found so far
    int res = nums[0];
    // the meanings of imax/imin is the key point
    // imax/imin stores the max/min product of
    // subarray that ends with the current number nums[i]
    for (int i = 1, imin = res, imax = res; i < nums.size(); ++i) {
      // multiplied by a negative makes big number smaller, small number bigger
      // so we redefine the extremums by swapping them
      if (nums[i] < 0)
        swap(imin, imax);
      
      // max/min product for the current number is either the current number itself
      // or the max/min by the previous number times the current one
      imin = min(imin * nums[i], nums[i]);
      imax = max(imax * nums[i], nums[i]);

      res = max(res, imax);
    }
    return res;
  }
};


int main() {
  Solution sol = Solution();
  vector<int> nums = {2,3,-2,4};
  cout << sol.maxProduct(nums) << endl;
  return 0;
}
