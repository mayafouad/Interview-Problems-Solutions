/*
Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.


Example 1:

Input: nums1 = [1,3], nums2 = [2]
Output: 2.00000
Explanation: merged array = [1,2,3] and median is 2.

Example 2:

Input: nums1 = [1,2], nums2 = [3,4]
Output: 2.50000
Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.
 

Constraints:

nums1.length == m
nums2.length == n
0 <= m <= 1000
0 <= n <= 1000
1 <= m + n <= 2000
-106 <= nums1[i], nums2[i] <= 106
*/


/*
solution 1: time complexity  O(m+n).

- merge then get the median
*/
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();
        int n = n1 + n2;
        int arr[n];
        int i = 0, j = 0, k = 0;
        while(i<n1 && j<n2){
           if(nums1[i] < nums2[j]) arr[k++] = nums1[i++];
           else arr[k++] = nums2[j++];
        }
        while(i<n1) arr[k++] = nums1[i++];
        while(j<n2) arr[k++] = nums2[j++];
        
        double ans;
        if(n % 2) ans = arr[n/2];
        else ans = (arr[n/2] + arr[n/2 - 1])/2.0;
        return ans;
    }
    
};


/*
solution 2: time complexity  O(log (m+n)).

- binary search on the smaller array & two pointers to divide both arrays into left and right halves.
*/


class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) 
        swap(nums1, nums2); // ensure nums1 is the smaller array

        int m = nums1.size(), n = nums2.size();
        int l = 0, r = m;

        while (l <= r) {
            int mid1 = (l + r) / 2;    
            int mid2 = (m + n + 1) / 2 - mid1; 
            int L1 = (mid1 == 0) ? INT_MIN : nums1[mid1 - 1]; 
            int R1 = (mid1 == m) ? INT_MAX : nums1[mid1];     
            int L2 = (mid2 == 0) ? INT_MIN : nums2[mid2 - 1]; 
            int R2 = (mid2 == n) ? INT_MAX : nums2[mid2];     
            if (L1 <= R2 && L2 <= R1) return (m + n) % 2 == 0 ? (max(L1, L2) + min(R1, R2)) / 2.0 : max(L1, L2); 
            else if (L1 > R2)  r = mid1 - 1; 
            else  l = mid1 + 1;        
        }
        
        return 0.0;
    }
    
};
