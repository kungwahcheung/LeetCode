#include <vector>
#include <iostream>

using std::vector;
using std::cout;
using std::endl;

class Solution {
 public:
  double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    if ((nums1.size() + nums2.size()) % 2 == 1)
      return findkth(nums1, 0, nums2, 0, (nums1.size()+nums2.size())/2+1);
    else
      return (findkth(nums1, 0, nums2, 0, (nums1.size()+nums2.size())/2) + findkth(nums1, 0, nums2, 0, (nums1.size()+nums2.size())/2+1)) / 2.0;
  }

 private:
  int findkth(vector<int>& nums1, int start1, vector<int>& nums2, int start2, int k) {
    if (nums1.size() - start1 > nums2.size() - start2) return findkth(nums2, start2, nums1, start1, k);
    if (start1 == nums1.size()) return nums2[start2+k-1];
    if (k == 1) return nums1[start1] < nums2[start2] ? nums1[start1] : nums2[start2];
    // (nums.size()-start) is the number of not-checked element in nums
    int h1 = k / 2 < nums1.size() - start1 ? k / 2 : nums1.size() - start1;
    int h2 = k / 2 < nums2.size() - start2 ? k / 2 : nums2.size() - start2;
    if (nums1[start1+h1-1] < nums2[start2+h2-1]) return findkth(nums1, start1+h1, nums2, start2, k-h1);
    else return findkth(nums1, start1, nums2, start2+h2, k-h2);
  }
};


int main() {
  Solution sol = Solution();
  vector<int> nums1{1, 2};
  vector<int> nums2{3, 4};
  cout << sol.findMedianSortedArrays(nums1, nums2) << endl;
}
