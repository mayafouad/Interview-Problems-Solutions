/*
Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Every close bracket has a corresponding open bracket of the same type.
 

Example 1:

Input: s = "()"

Output: true

Example 2:

Input: s = "()[]{}"

Output: true

Example 3:

Input: s = "(]"

Output: false

Example 4:

Input: s = "([])"

Output: true

 

Constraints:

1 <= s.length <= 104
s consists of parentheses only '()[]{}'.


*/



class Solution {
public:
    bool isValid(string s) {
        stack <char> st;
        for(int i=0; i<s.length(); i++){
            if(s[i] == '(' || s[i] == '{' || s[i] == '[') st.push(s[i]);
            if(s[i] == ')'){
                if(st.size() && st.top() == '(') st.pop();
                else return false;
            }
            if(s[i] == '}'){
                if(st.size() && st.top() == '{') st.pop();
                else return false;
            }
            if(s[i] == ']'){
                if(st.size() && st.top() == '[') st.pop();
                else return false;
            }
        }
        return (st.size() == 0) ;
    }
};
