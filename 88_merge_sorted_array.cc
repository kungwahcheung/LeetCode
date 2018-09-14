/**
 * 很多的python的解法都是新建一个list(例如叫merge_list), 然后把nums1和nums2合并到merge_list中去, 最后让nums1=merge_list
 * 但在C++这里不能这么干, 因为函数返回的时候merge_list指向的空间就被释放了, nums1现在指向的内容也就不收保护
 * 整体思路就是, 为了不覆盖nums1前面的部分而导致丢失数据, 需要从后面开始填充
 */

#include <vector>
#include <iostream>

using std::vector;
using std::cout;
using std::endl;

class Solution {
 public:
  void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int cur = m + n;
/*
    while (m > 0 && n > 0)
      nums1[--cur] = nums1[m-1] > nums2[n-1] ? nums1[--m] : nums2[--n];
    // 当m >= 0 时, nums1剩下的元素已经在正确的位置, 不需要特别处理
    // 当n >= 0 时, 需要把nums2尚未处理的元素搬到nums1
    while (n > 0)
      nums1[--cur] = nums2[--n];
*/
    // 上面两个while循环可以合并    
    while (n > 0)
      nums1[--cur] = (m > 0 && nums1[m-1] > nums2[n-1]) ? nums1[--m] : nums2[--n];
  }
};

int main() {
  Solution sol = Solution();
  vector<int> nums1 = {1,2,3,0,0,0};
  vector<int> nums2 = {2,5,6};
  sol.merge(nums1, 3, nums2, 3);
  for (auto it : nums1)
    cout << it << '\t';
  cout << endl;
  return 0;
}
