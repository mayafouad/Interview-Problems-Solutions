/*
Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.
Notice that the solution set must not contain duplicate triplets.

Example 1:
Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]
Explanation: 
nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
The distinct triplets are [-1,0,1] and [-1,-1,2].
Notice that the order of the output and the order of the triplets does not matter.

Example 2:
Input: nums = [0,1,1]
Output: []
Explanation: The only possible triplet does not sum up to 0.
Example 3:

Input: nums = [0,0,0]
Output: [[0,0,0]]
Explanation: The only possible triplet sums up to 0.
 

Constraints:

3 <= nums.length <= 3000
-105 <= nums[i] <= 105
*/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size(); 
        vector<vector<int>> v2;
        sort(nums.begin(), nums.end());
        for(int i=0; i<n; i++){
            // Skip duplicate elements for the first element of the triplet
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            int x = nums[i];
            int l = i+1, r = n-1;
            while(l < r){
                if(nums[l] + nums[r] == -1*x){
                    int mn =  min(x, min(nums[l], nums[r])) , mx = max(x, max(nums[l], nums[r]));
                    v2.push_back({x, nums[l], nums[r]});
                    // Skip duplicate elements for the second element of the triplet
                    while (l < r && nums[l] == nums[l + 1]) l++;
                    // Skip duplicate elements for the third element of the triplet
                    while (l < r && nums[r] == nums[r - 1]) r--;
                    l++; r--;
                }
                else if(nums[l] + nums[r] < -1*x) l++;
                else r--;
            }
        }
        return v2;
    }
};
