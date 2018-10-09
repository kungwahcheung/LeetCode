#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  string intToRoman(int num) {
    string M[] = {"", "M", "MM", "MMM"};
    string C[] = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
    string X[] = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
    string I[] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
    string roman = M[num/1000] + C[(num%1000)/100] + X[(num%100)/10] + I[num%10];
    return roman;
  }
};


int main() {
  Solution sol = Solution();
  int num = 0;
  cout << "input an integer: ";
  cin >> num;
  cout << sol.intToRoman(num) << endl;
  return 0;
}
