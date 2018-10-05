#include <string>
#include <vector>
#include <iostream>

using std::string;
using std::vector;
using std::cin;
using std::cout;
using std::endl;

class Solution {
 public:
  string convert(string s, int numRows) {
    if (s.length() <= numRows || numRows == 1) return s;
    vector<string> arr(numRows, "");
    int row = 0;
    bool flag = false;  // true: downward; false: upward
    for (int i = 0; i < s.length(); ++i) {
      arr[row].push_back(s[i]);
      if (row == 0 || row == (numRows - 1))
        flag = (flag == true) ? false : true;
      row = flag ? row + 1 : row - 1;
    }
    s.clear();
    for (int i = 0; i < arr.size(); ++i) {
      cout << arr[i] << endl;
      s.append(arr[i]);
    }
    return s;
  }
};


int main() {
  Solution sol = Solution();
  cout << "zigzag string of \"PAYPALISHIRING\"(3 rows): " << sol.convert("PAYPALISHIRING", 3) << endl;
  cout << "zigzag string of \"PAYPALISHIRING\"(4 rows): " << sol.convert("PAYPALISHIRING", 4) << endl;
}
