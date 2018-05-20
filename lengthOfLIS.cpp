// leetcode 300
// dynamic programming
/*
Given an unsorted array of integers, find the length of longest increasing subsequence.

Example:

Input: [10,9,2,5,3,7,101,18]
Output: 4 
Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4. 
Note:

There may be more than one LIS combination, it is only necessary for you to return the length.
Your algorithm should run in O(n2) complexity.
Follow up: Could you improve it to O(n log n) time complexity?
*/
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int N = nums.size();
        if(N==0) return 0;
        vector<int> maxL(N, 1);
        // dynamic programming
        for(int i=1; i<N; i++) {
            for(int j=0; j<i; j++) {
                if(nums[i]>nums[j]&&maxL[j]+1>maxL[i]){
                    maxL[i] = maxL[j]+1;
                }
            }
        }
        int cnt=maxL[0];
        for(int i=1; i<N; i++) {
            if(cnt<maxL[i]) cnt=maxL[i];
        }
        return cnt;
    }
};
