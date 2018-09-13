#include <vector>
#include <unordered_map>
#include <iostream>

using std::vector;
using std::unordered_map;
using std::cout;
using std::endl;

class Solution {
 public:
  vector<int> twoSum(vector<int>& nums, int target) {
    vector<int> ret;
    unordered_map<int, int> map;
    for (int i = 0; i < nums.size(); ++i) {
      if (map.find(target - nums[i]) != map.end()) {
        ret.push_back(map.at(target - nums[i]));
        ret.push_back(i);
        return ret;
      }
      map[nums[i]] = i;
    }
    return ret;
  }
};

int main() {
  Solution sol = Solution();
  vector<int> nums = {2, 7, 11, 15};
  int target = 9;
  vector<int> res = sol.twoSum(nums, target);
  for (auto it : res) cout << it << endl;
  return 0;
}
