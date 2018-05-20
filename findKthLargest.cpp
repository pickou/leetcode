
//There are a lot of solutions.
// 1. quick sort 
// 2. c++ stl multiset
// 3. insert sort, keep an array of size k.
// 4. recursive solution
/*class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        return getKth(nums, k, 0, nums.size()-1);
    }
    int getKth(vector<int> &nums, int k, int left, int right) {
        int low=left, high=right;
        int key = nums[left];
        int N = nums.size();
        while(low<high) {
            // point 1. high before low
            while(nums[high]>=key&&low<high) high--;
            while(nums[low]<=key&&low<high) low++;
            if(low<high) {
                int tmp = nums[low];
                nums[low] = nums[high];
                nums[high] = tmp;
            }
        }
        // point 2. put the key and set the left
        nums[left] = nums[low];
        nums[low] = key;
        if(N-low==k) return key;
        if(N-low<k) return getKth(nums, k, left, low-1);
        else return getKth(nums, k, low+1, right);
    }
    
   
};
*/

//  5. loop solution
/*
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int N = nums.size();
        int left=0, right=N-1;
        int low=left, high=right, key=nums[left];
        while(N-low!=k||high!=low) {
            low=left; high=right;
            key = nums[left];
            while(low<high) {
                while(nums[high]>=key&&low<high) high--;
                while(nums[low]<=key&&low<high) low++;
                if(low<high) {
                    int tmp = nums[low];
                    nums[low] = nums[high];
                    nums[high] = tmp;
                }
            }
            nums[left] = nums[low];
            nums[low] = key;
            if(N-low<k) right = low-1;
            else left = low+1;
        }
        return key;
    }
};
*/
// 6. bitmap binary search. in place algorithmn

class Solution {
public:
    int findKthLargest(vector<int>nums, int k) {
        int low=0, high=0, last=0, cur=0, mask=1;
        int i,j;
        // deal the negative numbers
        for(auto &num:nums) {
            if((1<<31)&num!=0) low++;
            else high++;
        }
        if(high<k) {
            last=1;
            k=k-high;
        }
        // choose the numbers in every bit [31-0]
        for(i=31; i>0; i--) {
            cur=mask<<i;
            low=0, high=0;
            for(j=0; j<nums.size(); j++) {
                if(((last<<i)^(cur&nums[j]))==0) { //whether the number should be considered
                    if(((1<<(i-1))&nums[j])>0) high++;
                    else low++;
                }
            }
            // return condition
            if(high==1&&k==1) {
                last=last<<i;
                last=last|(1<<(i-1));
                cur=cur|(1<<(i-1));
                break;
            }
            else if(k==1&&low==1&&high==0) {
                last=last<<i;
                cur=cur|(1<<(i-1));
                break;
            }
            last=last<<1;
            if(high<k) k=k-high;
            else last=last|1;
            mask=(mask<<1)|1;
        }
        if(i==0) return last;
        for(auto num:nums) {
            if((last^(cur&num))==0) return num;
        }
        return last>>1;
    }
};
