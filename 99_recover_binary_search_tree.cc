#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include "treenode.h"

using namespace std;

class Solution {
 public:
  TreeNode *pre = nullptr;
  TreeNode *first = nullptr;
  TreeNode *second = nullptr;
  
  void recoverTree(TreeNode* root) {
    traverse(root);
    if (first) swap(first->val, second->val);
  }
 private:
  void traverse(TreeNode* root) {
    if (!root) return;
    traverse(root->left);
    if (pre && root->val < pre->val) {
      if (!first) first = pre;
      second = root;
    }
    pre = root;
    traverse(root->right);
  }
};


int main() {
  Solution sol = Solution();
  TreeNode *root = create_tree({3,1,4,None,None,2});
  sol.recoverTree(root);
  print_tree(root);
  return 0;
}
