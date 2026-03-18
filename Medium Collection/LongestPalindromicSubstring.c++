/*
Given a string s, return the longest palindromic substring in s.

 

Example 1:

Input: s = "babad"
Output: "bab"
Explanation: "aba" is also a valid answer.
Example 2:

Input: s = "cbbd"
Output: "bb"
 

Constraints:

1 <= s.length <= 1000
s consist of only digits and English letters.
*/


// sol 1 expand around the center :  O(n^2) !!!!!!!!!

class Solution {
public:
    string longestPalindrome(string s) {
        string ans = "";
        int len = 0;
        for(int i = 0;i < s.length();i++){
            // for odd len
            int p1 = i,p2 = i;
            while(p1 >= 0 && p2 < s.length() && s[p1] == s[p2]){
                if(p2 - p1 + 1 > len){
                    len = p2 - p1 + 1;
                    ans = s.substr(p1,len);
                }
                p1--;
                p2++;
            }
            
            // for even len
            p1 = i,p2 = i+1;
            while(p1 >= 0 && p2 < s.length() && s[p1] == s[p2]){
                if(p2 - p1 + 1 > len){
                    len = p2 - p1 + 1;
                    ans = s.substr(p1,len);
                }
                p1--;
                p2++;
            }
        }
        return ans;
    }
};



// sol 2 using Manacher’s Algorithm : O(n) time & space
// Manacher avoids that by:
// Reusing previously computed palindrome info
// Making expansion almost always constant time

class Solution {
public:
    string longestPalindrome(string s) {
        string t = "_";
        for(char c : s) {
            t += c;
            t += "_";
        }
      
        int n = t.size();
        vector<int> p(n, 0);

        int center = 0, right = 0, maxLen = 0, start = 0;

        for(int i = 0; i < n; i++) {
            int mirror = 2 * center - i;

            if(i < right)
                p[i] = min(right - i, p[mirror]);

            while(i + p[i] + 1 < n && i - p[i] - 1 >= 0 && t[i + p[i] + 1] == t[i - p[i] - 1]) {
                p[i]++;
            }

            if(i + p[i] > right) {
                center = i;
                right = i + p[i];
            }

            if(p[i] > maxLen) {
                maxLen = p[i];
                start = (i - maxLen) / 2;
            }
        }

        return s.substr(start, maxLen);
    }
};
