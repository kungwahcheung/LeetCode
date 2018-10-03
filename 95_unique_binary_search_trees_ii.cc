/**
 * 递归解法比较直接, 分别以1, 2, 3, ..., n为root,
 * 递归构造二叉搜索树;
 * Discuss里面有非递归解法, 思路也比较直接, 但涉及的细节比较多, 导致实现难度比较大。
 */

#include <vector>
#include <iostream>
#include "treenode.h"

class Solution {
 public:
  vector<TreeNode*> generateTrees(int n) {
    if (n <= 0) return vector<TreeNode*>();
    return generateTrees(1, n);
  }
 
 private:
  vector<TreeNode*> generateTrees(int start, int end) {
    if (start == end) return vector<TreeNode*> {new TreeNode(start)};
    else if (start > end) return vector<TreeNode*> {NULL};
    vector<TreeNode*> res;
    for (int it = start; it <= end; ++it) {
      vector<TreeNode*> lefts = generateTrees(start, it - 1);
      vector<TreeNode*> rights = generateTrees(it + 1, end);
      for (auto left : lefts) {
        for (auto right : rights) {
          res.push_back(new TreeNode(it));
          res.back()->left = left;
          res.back()->right = right;
        }
      }
    }
    return res;
  }
};

int main () {
  Solution sol = Solution();
  vector<TreeNode*> res = sol.generateTrees(3);
  for (auto tree : res) {
    print_tree(tree);
    std::cout << "#-------------------------#" << std::endl;
  }
}
