#include <algorithm>
#include <climits>
#include <iostream>
#include "treenode.h"

#ifndef SOLUTION
#define SOLUTION 1
#endif  // SOLUTION

using namespace std;


class Solution {
#if SOLUTION == 1
 public:
  bool isValidBST(TreeNode* root) {
    return isValidBST(root, NULL, NULL);
  }
 private:
  bool isValidBST(TreeNode* root, TreeNode* minNode, TreeNode* maxNode) {
    if (!root) return true;
    if ((minNode && root->val <= minNode->val) || (maxNode && root->val >= maxNode->val)) return false;
    return isValidBST(root->left, minNode, root) && isValidBST(root->right, root, maxNode);
  }
#elif SOLUTION == 2
/* solution 2 不能通过测试, 当root->val 为INT_MAX时答案错误 */
 public:
  bool isValidBST(TreeNode* root) {
    return isValidBST(root, INT_MIN, INT_MAX);
  }
 
 private:
  bool isValidBST(TreeNode* root, int low, int high) {
    if (!root) return true;
    if (root->val <= low || root->val >= high) return false;
    return isValidBST(root->left, low, root->val) && isValidBST(root->right, root->val, high);
  }
#endif  // SOLUTION
};


int main() {
  Solution sol = Solution();
  TreeNode *root = create_tree(vector<int> {2, 1, 3});
  cout << sol.isValidBST(root) << endl;
  return 0;
}
