#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring_1(string s) {
        int count, max=0;
        bool flag;
        for (int i=0; i < s.size(); ++i) {
            count = 0;
            
            for (int j=i; j < s.size(); ++j) {
                flag = false;
                for (int k=i; k < j; ++k) {
                   if (s[j] == s[k]) {
                     flag = true;
                     break;
                   } 
                }

               if (flag) {
                   break;
               }
               
               ++count;
            }

            if (count > max) {
                max = count;
            }
        }

        return max;
    }

    int lengthOfLongestSubstring(string s) {
        int m[256] = {0}, res = 0, left = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (m[s[i]] == 0 || m[s[i]] < left) {
                res = max(res, i - left + 1);
            } else {
                left = m[s[i]];
            }
            m[s[i]] = i + 1;
        }
        return res;
    }
};

int main() {
 Solution s;
 string str = "pwwkew";

 cout << "Max Length: " << s.lengthOfLongestSubstring(str) << endl;

 return 0;
}

