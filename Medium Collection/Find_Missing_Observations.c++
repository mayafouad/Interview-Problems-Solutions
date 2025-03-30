
/*
You have observations of n + m 6-sided dice rolls with each face numbered from 1 to 6. n of the observations went missing, and you only have the observations of m rolls. Fortunately, you have also calculated the average value of the n + m rolls.

You are given an integer array rolls of length m where rolls[i] is the value of the ith observation. You are also given the two integers mean and n.

Return an array of length n containing the missing observations such that the average value of the n + m rolls is exactly mean. If there are multiple valid answers, return any of them. If no such array exists, return an empty array.

The average value of a set of k numbers is the sum of the numbers divided by k.

Note that mean is an integer, so the sum of the n + m rolls should be divisible by n + m.


Example 1:

Input: rolls = [3,2,4,3], mean = 4, n = 2
Output: [6,6]
Explanation: The mean of all n + m rolls is (3 + 2 + 4 + 3 + 6 + 6) / 6 = 4.

Example 2:

Input: rolls = [1,5,6], mean = 3, n = 4
Output: [2,3,2,2]
Explanation: The mean of all n + m rolls is (1 + 5 + 6 + 2 + 3 + 2 + 2) / 7 = 3.

Example 3:

Input: rolls = [1,2,3,4], mean = 6, n = 4
Output: []
Explanation: It is impossible for the mean to be 6 no matter what the 4 missing rolls are.

Constraints:

m == rolls.length
1 <= n, m <= 105
1 <= rolls[i], mean <= 6

*/

class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m = rolls.size(), sum = 0;
        float len = n  + m ;
        for(int i=0; i<m; i++) sum+=rolls[i];
        float x = ((len * mean ) - sum) / n;
        if(x > 6.0 || x < 1) return {};
        else {
            int num = (((m + n) * mean ) - sum) ;
            vector<int> ans(n);
            int temp = num;
            for(int i=0; i<n; i++){
                ans[i] = num/n;
                temp -= num/n;
            } 
            if(temp){
                for(int i=0; i<n && temp; i++){
                    if(ans[i] == 6) continue;
                    if(temp >= 6-ans[i]){
                        temp-=6-ans[i];
                        ans[i] = 6;
                    }
                    else{
                        ans[i]+=temp;
                        break;
                    } 
                } 
            }
            return ans;
        }
    }
};


