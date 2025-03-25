/*
Given a string s, rearrange the characters of s so that any two adjacent characters are not the same.

Return any possible rearrangement of s or return "" if not possible.

 

Example 1:

Input: s = "aab"
Output: "aba"
Example 2:

Input: s = "aaab"
Output: ""
 

Constraints:

1 <= s.length <= 500
s consists of lowercase English letters.

*/

class Solution {
public:
    string reorganizeString(string s) {
        map<char, int> mp;
        int n = s.length();
        string ans = "";
        for(int i=0; i<n; i++) mp[s[i]]++;
        for(int i=0; i<n; i++){
            if(mp[s[i]] > (n+1)/2) return "";
        }
        priority_queue<pair<int, char>> pq;
        for (auto [ch, freq] : mp) {
            pq.push({freq, ch});
        }
        while (pq.size() >= 2) {
            auto [freq1, ch1] = pq.top();
            pq.pop();
            auto [freq2, ch2] = pq.top();
            pq.pop();
            ans+=ch1;
            ans+=ch2;
            if(freq1-1 > 0) pq.push({freq1-1, ch1});
            if(freq2-1 > 0) pq.push({freq2-1, ch2});
        }
        if(!pq.empty()){
            auto [freq, ch] = pq.top();
            ans+=ch;
        }
        return ans;
    }
};

