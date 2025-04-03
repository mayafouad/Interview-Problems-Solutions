/*
Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.

A mapping of digits to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.

Example 1:

Input: digits = "23"
Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]
Example 2:

Input: digits = ""
Output: []
Example 3:

Input: digits = "2"
Output: ["a","b","c"]
 

Constraints:

0 <= digits.length <= 4
digits[i] is a digit in the range ['2', '9'].

*/

//https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/

class Solution {
public:
    map<int, vector<char>> mp;

    void setMap (){
        mp[2] = {'a', 'b', 'c'};
        mp[3] = {'d', 'e', 'f'};
        mp[4] = {'g', 'h', 'i'};
        mp[5] = {'j', 'k', 'l'};
        mp[6] = {'m', 'n', 'o'};
        mp[7] = {'p', 'q', 'r', 's'};
        mp[8] = {'t', 'u', 'v'};
        mp[9] = {'w', 'x', 'y', 'z'};
    }

    vector<string> ans;

    void solve(string digits, int indx, int mxIndx, string comb){
        if(indx == mxIndx) {
            if(comb != "") ans.push_back(comb);
            return;
        }
        for(auto ch:mp[digits[indx]-'0']){
            comb+=ch;
            solve(digits, indx+1, mxIndx, comb);
            comb.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        setMap();
        solve(digits, 0, digits.length(), "");
        return ans;
    }
};


