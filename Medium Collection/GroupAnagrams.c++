/*
Given an array of strings strs, group the anagrams together. You can return the answer in any order.

Example 1:

Input: strs = ["eat","tea","tan","ate","nat","bat"]

Output: [["bat"],["nat","tan"],["ate","eat","tea"]]

Explanation:
There is no string in strs that can be rearranged to form "bat".
The strings "nat" and "tan" are anagrams as they can be rearranged to form each other.
The strings "ate", "eat", and "tea" are anagrams as they can be rearranged to form each other.

Example 2:

Input: strs = [""]

Output: [[""]]

Example 3:

Input: strs = ["a"]

Output: [["a"]]


Constraints:

1 <= strs.length <= 104
0 <= strs[i].length <= 100
strs[i] consists of lowercase English letters.
*/

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
      // Hash Map Keyed By sorted word
        map <string, vector<string>> mp;
        for(int i=0; i<strs.size(); i++){
            string temp = strs[i];
            sort(strs[i].begin(),strs[i].end());
            mp[strs[i]].push_back(temp);
        }
        int index = 0;
        vector<vector<string>> ans(mp.size());
        for(auto j:mp){
            for(auto i:j.second){
                ans[index].push_back(i);
            }
            index++;
        }
        return ans;
    }
};
