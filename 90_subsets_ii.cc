#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iostream>

using std::vector;
using std::unordered_map;
using std::sort;
using std::cout;
using std::endl;

class Solution {
 public:
  vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> res = {vector<int>()};
    int count = 0;
    for (int i = 0; i < nums.size(); ++i) {
      // 统计当前的元素在前面已经出现的次数
      if (i > 0 && nums[i] == nums[i-1])
        ++count;
      else
        count = 0;
      if (0 == count) {  // 首次出现, 只需简单地往已有的子集添加这个新元素作为新加入的子集
        int size = res.size();
        for (int j = 0; j < size; ++j) {
          res.push_back(res[j]);
          res.back().push_back(nums[i]);
        }
      } else {  // 非首次出现, 需要做特殊处理, 例如, 对于{1,2,2,2} 处理第二个2的时候, 为避免重复添加, 不能再往没有2的子集中添加2
                // 处理第三个2的时候, 为避免重复添加, 除了不能再往没有2的子集中添加2, 也不能往只有一个2的子集中添加2
                // 综上所述, 对于重复出现的元素, 假设当前已经处理过的同样元素(假设为e)的个数为count, 
                // 如果目前检查的子集中e的个数少于count, 那么往这个子集添加e的话, 会造成重复添加, 因此我们跳过这个子集.
                // 换句话说, 我们只处理那些出现过count次e元素的子集.
        int size = res.size();
        for (int j = 0; j < size; ++j) {
          if (res[j].size() >= (count) && res[j][res[j].size()-count] == nums[i]) {
            res.push_back(res[j]);
            res.back().push_back(nums[i]);
          }
        }
      }
    }
    return res;
  }
  
  // 下面这种方法与上面的思路稍有不同, 避免了检查子集中当前元素的个数, 从而使得程序性能得到了优化
  // 参考 https://leetcode.com/problems/subsets-ii/discuss/30168/C++-solution-and-explanation
  // 简单来说就是, 对于当前要处理的元素e, 先统计e在nums中的个数, 对于已有子集, 可以有多种选择:
  // 不添加e元素, 添加1个e元素, 添加2个e元素, .. , 添加count个e元素
  // 由于采取了一次性处理完e元素的策略, 省去检查上面的方法中检查子集元素的麻烦, 性能有提升.
  vector<vector<int>> subsetsWithDup_v2(vector<int>& nums) {
    vector<vector<int>> res = {{}};
    sort(nums.begin(), nums.end());
    int count = 0;
    for (int i = 0; i < nums.size(); /* nothing here */) {
      count = 0;
      // 这个while循环值得学习
      while (i + count < nums.size() && nums[i+count] == nums[i]) ++count;
      int size = res.size();
      for (int j = 0; j < size; ++j) {
        // 此处做法巧妙
        vector<int> it = res[j];
        for (int k = 0; k < count; ++k) {
          it.push_back(nums[i]);
          res.push_back(it);
        }
      }
      i += count;
    }
    return res;
  }
};

int main() {
  Solution sol = Solution();
  vector<int> nums = {1, 2, 2};
  vector<vector<int>> res = sol.subsetsWithDup_v2(nums);
  for (auto subset : res) {
    cout << "[ ";
    for (auto it : subset) cout << it << " ";
      cout << "]" << endl;
  }
  return 0;
}
