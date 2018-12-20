#include <algorithm>
#include <iostream>
#include <vector>

#ifndef SOLUTION
#define SOLUTION 2
#endif  // SOLUTION

using namespace std;

class Solution {
 public:
#if SOLUTION == 1
  /* 每次后移一位, 进行(k % size)次 */
  void rotate(vector<int>& nums, int k) {
    if (nums.size() <= 1) return;
    int size = nums.size();
    k = k % size;
    int tmp = 0;
    for (int t = 0; t < k; ++t) {
      tmp = nums[size-1];
      for (int i = size-1; i >= 0; --i) {
        nums[i] = nums[i-1];
      }
      nums[0] = tmp;
    }
  }
#elif SOLUTION == 2
  /* 后移k位的话, 前面k个数是原来排在数组最后面的k个数(的反转), 后面的n-k个数是原来数组排在前面的n-k个数(的反转) */
  void rotate(vector<int>& nums, int k) {
    k = k % nums.size();
    reverse(nums.begin(), nums.end());
    reverse(nums.begin(), nums.begin()+k);
    reverse(nums.begin()+k, nums.end());
    
  }

#endif  // SOLUTION
};


int main() {
  Solution sol = Solution();
  vector<int> nums {1,2,3,4,5,6};
  sol.rotate(nums, 3);
  for (int i = 0; i < nums.size(); ++i)
    cout << nums[i] << '\t';
  cout << endl;
  return 0;
}
