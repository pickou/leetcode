// https://blog.csdn.net/SpeedMe/article/details/21654357
// http://xiaohuiliucuriosity.blogspot.com/2014/12/permutations.html
// Divide && Conquer
// DFS (use a visited array)
/*
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<bool> visited(nums.size(), false);
        vector<vector<int> > res;
        if(nums.size()==0) return res;
        vector<int> curr;
        helper(res, nums, curr, visited);
        return res;
    }
    void helper(vector<vector<int> > &res, vector<int> nums, vector<int> curr, vector<bool> visited) {
        if(curr.size() == nums.size()) {
            res.push_back(curr);
            return;
        }
        for(int i=0; i<nums.size(); i++) {
            if(visited[i] == false) {
                visited[i] = true;
                curr.push_back(nums[i]);
                helper(res, nums, curr, visited);
                visited[i] = false;
                curr.pop_back();
            }
        }
    }
};

*/
// based on swap
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        helper(nums, res, 0);
        return res;
    }
    void helper(vector<int> &nums, vector<vector<int>> &res, int i) {
        if(i==nums.size()-1) {
            vector<int> permute;
            for(int j=0; j<nums.size(); j++) {
                permute.push_back(nums[j]);
            }
            res.push_back(permute);
        }
        for(int j=i; j<nums.size(); j++) {
            swap(nums, i, j);
            helper(nums, res, i+1);
            swap(nums, i, j);
        }
    }
    void swap(vector<int> &nums, int i, int j) {
        int tmp = nums[i];
        nums[i] = nums[j];
        nums[j] = tmp;
    }
};
