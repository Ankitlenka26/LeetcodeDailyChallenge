/*
Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.
Follow up: If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.

Example 1:

Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6.
Example 2:

Input: nums = [1]
Output: 1
Example 3:

Input: nums = [0]
Output: 0
Example 4:

Input: nums = [-1]
Output: -1
Example 5:

Input: nums = [-2147483647]
Output: -2147483647
*/
#include<iostream>
#include<climits>
#include<vector>
#include<algorithm>
using namespace std ; 
class Solution {
public:
    // Simple Kadane's Algorithm O(n) time O(1) space
    int maxSubArray(vector<int>& nums) {
        // O(1) space complexity , O(N) time complexity
        if(nums.size()==0){
            return INT_MIN; 
        }
        int max_till_now =  nums[0]; 
        int max_ends_here = nums[0]; 
        for(int i=1 ; i<nums.size() ;i++){
            max_ends_here = max(max_ends_here + nums[i] , nums[i]); 
            if(max_ends_here > max_till_now){
                max_till_now = max_ends_here ; 
            }
        }
        return max_till_now; 
    }
};
