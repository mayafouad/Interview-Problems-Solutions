/*
Given an integer numRows, return the first numRows of Pascal's triangle.

In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:


Example 1:

Input: numRows = 5
Output: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]
  
Example 2:

Input: numRows = 1
Output: [[1]]
 

Constraints:

1 <= numRows <= 30

  */

class Solution {
public:
    int dp[32][32] = {0};
    void create(){
        dp[1][1] = 1;
        for(int i=2; i<32; i++){
            for(int j=1; j<=i; j++){
                dp[i][j] = dp[i-1][j]+dp[i-1][j-1];
            }
        }
    }
    
    vector<vector<int>> generate(int numRows) {
        create();
        vector<vector<int>> ans;
        for(int i=1; i<=numRows; i++){
            vector <int> sub;
            for(int j=1; j<=i; j++){
                sub.push_back(dp[i][j]);
            }
            ans.push_back(sub);
        }
        return ans;
    }
};




