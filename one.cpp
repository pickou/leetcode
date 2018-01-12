/*************3Sum*******************/
// 求解一个数组中的三个数,使得a+b+c=0,返回值是vector<vecor<int>>
// 学习到几个更c++化的写法,upper_bound/lower_bound,next/prev,当然还有sort
// 连接 http://en.cppreference.com/w/cpp/algorithm/upper_bound
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        std::vector<std::vector<int>> ans;
        std::sort(std::begin(nums), std::end(nums));
        for (auto i = std::begin(nums); i < std::end(nums);) {
            auto j = std::next(i);
            auto k = std::prev(std::end(nums));
            auto target = -*i;
            while (j < k) {
                if (*j + *k == target) {
                    ans.push_back({*i, *j, *k});
                    j = std::upper_bound(j, k, *j);
                    k = std::lower_bound(j, k, *k);
                } else if (*j + *k < target) {
                    ++j;
                } else {
                    --k;
                }
            }
            i = std::upper_bound(i, std::end(nums), *i);
        }
        return ans;
    }
};

/***********3Sum_closest****************/
// 一个数组中三个数相加距离给定的数字更近，返回这三个数的和
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int p,q;
        int closest_sum=nums[0]+nums[1]+nums[nums.size()-1];
        int sum=closest_sum;
        int dis=abs(sum-target);
        for(int i=0; i< nums.size()-1; i++) {
            p = i+1;
            q = nums.size()-1;
            while(p<q){
                sum = nums[i]+nums[p]+nums[q];
                if(abs(sum-target)<dis) {dis=abs(sum-target); closest_sum=sum;}
                if(sum<target) p++;
                else if(sum>target) q--;
                else return sum;
            }
        }
        return closest_sum;
    }
};
