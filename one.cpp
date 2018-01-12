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
