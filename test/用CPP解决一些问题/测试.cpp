#include <iostream>
using namespace std;

class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n = s.size();
        for (int i = 1; i * 2 <= n; ++i) {
            if (n % i == 0) {
                bool match = true;
                for (int j = i; j < n; ++j) {
                    if (s[j] != s[j - i]) {
                        match = false;
                        break;
                    }
                }
                if (match) {
                    return true;
                }
            }
        }
        return false;
    }
};



int main() {

    Solution ss;
   bool s= ss.repeatedSubstringPattern(("aaa"));
   cout << s;

   return 0;
}