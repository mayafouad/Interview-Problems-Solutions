/*
Given a string s that contains parentheses and letters, remove the minimum number of invalid parentheses to make the input string valid.

Return a list of unique strings that are valid with the minimum number of removals. You may return the answer in any order.

Example 1:
Input: s = "()())()"
Output: ["(())()","()()()"]
  
Example 2:
Input: s = "(a)())()"
Output: ["(a())()","(a)()()"]
  
Example 3:
Input: s = ")("
Output: [""]
 

Constraints:

1 <= s.length <= 25
s consists of lowercase English letters and parentheses '(' and ')'.
There will be at most 20 parentheses in s.

  */





class Solution {
public:
    vector<string> res;
    int maxLen = 0; 

    bool valid(string s){
        int c = 0;
        for(char ch:s){
            if(ch == '(') c++;
            else if(ch == ')') c--;
            if(c < 0) return false;
        }
        return c==0;
    }

    void solve(string s, int indx){
        if(valid(s)){
            if(s.length()>= maxLen){
                if(s.length()> maxLen){
                    res.clear();
                    maxLen = s.length();
                }
                if (find(res.begin(), res.end(), s) == res.end()) res.push_back(s); 
            }
            return;
        } 
        for (int i=indx; i<s.length(); i++) {
            if (i > indx && s[i] == s[i - 1]) continue;
            if (s[i] == '(' || s[i] == ')') {
                string next = s.substr(0, i) + s.substr(i + 1);
                solve(next, i);
            }
        }
    }

    vector<string> removeInvalidParentheses(string s) {
        maxLen = 0;
        solve(s, 0);
        return res;
    }

};


