#include <iostream>
#include <stack>
#include <vector>
#include "treenode.h"

#ifndef SOLUTION
#define SOLUTION 2
#endif  // SOLUTION

using namespace std;

class Solution {
 public:
#if SOLUTION == 1
  /* 递归求解 */
  vector<int> inorderTraversal(TreeNode* root) {
    vector<int> res{};
    inorder(root, res);
    return res;
  }
  void inorder(TreeNode* root, vector<int>& res) {
    if (!root) return;
    inorder(root->left, res);
    res.push_back(root->val);
    inorder(root->right, res);
  }

#elif SOLUTION == 2
  /* 非递归解法, 使用栈 */
  vector<int> inorderTraversal(TreeNode* root) {
    vector<int> res;
    stack<TreeNode*> s;
    TreeNode *p = root;
    while (!s.empty() || p) {
      if (p) {
        s.push(p);
        p = p->left;
      } else {
        p = s.top();
        s.pop();
        res.push_back(p->val);
        p = p->right;
      }
    }
    return res;
  }
#endif  // SOLUTION
};


int main() {
  Solution sol = Solution();
  TreeNode *root = create_tree({1,None,3,2});
  vector<int> res = sol.inorderTraversal(root);
  for (auto it : res) {
    cout << it << '\t';
  }
  cout << endl;
  return 0;
}
