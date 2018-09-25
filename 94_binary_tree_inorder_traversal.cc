#include <vector>
#include <iostream>
#include "treenode.h"

using std::vector;
using std::cout;
using std::endl;

class Solution {
 public:
  vector<int> inorderTraversal(TreeNode* root) {
    vector<int> res;
    inorder(root, res);
    return res;
  }
 
 private:
  void inorder(TreeNode* root, vector<int>& traversal) {
    if (!root) return;
    inorder(root->left, traversal);
    traversal.push_back(root->val);
    inorder(root->right, traversal);
  }
};


int main() {
  Solution sol = Solution();
  TreeNode *root = create_tree({1, None, 2, 3, 4});
  print_tree(root);
  vector<int> traversal = sol.inorderTraversal(root);
  cout << endl;
  for (auto it : traversal)
    cout << it << '\t';
  cout << endl;
  return 0;
}
