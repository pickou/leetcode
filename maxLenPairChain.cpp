/*
You are given n pairs of numbers. In every pair, the first number is always smaller than the second number.

Now, we define a pair (c, d) can follow another pair (a, b) if and only if b < c. Chain of pairs can be formed in this fashion.

Given a set of pairs, find the length longest chain which can be formed. You needn't use up all the given pairs. You can select pairs in any order.

Example 1:
Input: [[1,2], [2,3], [3,4]]
Output: 2
Explanation: The longest chain is [1,2] -> [3,4]
*/

class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end(), compare);
        int cnt=1;
        int pre=pairs[0][1];
        for(int i=1; i<pairs.size(); i++) {
            if(pairs[i][0]>pre) {
                cnt += 1;
                pre = pairs[i][1];
            }
        }
        return cnt;
    }
private:
    static bool compare(vector<int> &a, vector<int> &b) {
        return a[1] < b[1];
    }
};
