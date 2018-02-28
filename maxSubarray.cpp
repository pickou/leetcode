
//Find the contiguous subarray within an array (containing at least one number) which has the largest sum.

//For example, given the array [-2,1,-3,4,-1,2,1,-5,4],
//the contiguous subarray [4,-1,2,1] has the largest sum = 6.

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
    int cnt=nums.size();
    if(cnt==1) return nums[0];
    int start=0, end=0, sum=0, maxSum=nums[0];
    for(int i=0;i<cnt;i++) {
        sum = 0;
        for(int j=i;j<cnt;j++) {
            sum += nums[j];
            if(sum>maxSum) {
                start = i;
                end = j;
                maxSum = sum;
            }
        }
    }
    return maxSum;
    }
};
