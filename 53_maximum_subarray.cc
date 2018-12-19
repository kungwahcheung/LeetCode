#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  int maxSubArray(vector<int>& nums) {
    if (nums.empty()) return 0;
    int res = nums[0], tmp = 0;
    for (int i = 0; i < nums.size(); ++i) {
      tmp += nums[i];
      res = (res > tmp) ? res : tmp;
      if (tmp < 0) tmp = 0;
    }
    return res;
  }
};


int main() {
  Solution sol = Solution();
  vector<int> nums{-2,1,-3,4,-1,2,1,-5,4};
  cout << (sol.maxSubArray(nums) == 6 ? "passed" : "failed") << endl;
  return 0;
}
