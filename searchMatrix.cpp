// divide and conquer
// easy problem, just need to consider the boarder
/*
Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

Integers in each row are sorted in ascending from left to right.
Integers in each column are sorted in ascending from top to bottom.
Consider the following matrix:

[
  [1,   4,  7, 11, 15],
  [2,   5,  8, 12, 19],
  [3,   6,  9, 16, 22],
  [10, 13, 14, 17, 24],
  [18, 21, 23, 26, 30]
]
Example 1:

Input: matrix, target = 5
Output: true
Example 2:

Input: matrix, target = 20
Output: false
*/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int M = matrix.size();
        if(M==0) return false;
        int N = matrix[0].size();
        if(N==0) return false;
        // divide and conquer
        return searchT(matrix, target, 0, M, 0, N);
    }
    bool searchT(vector<vector<int> >&matrix, int target, int rowS, int rowE, int colS, int colE) {
        int i=0;
        bool res=false;
        if(rowS>=rowE||colS>=colE) return false;
        for(;i<colE-colS&&i<rowE-rowS; i++) {
            if(matrix[rowS+i][colS+i]==target) return true;
            if(matrix[rowS+i][colS+i]>target) break;
        }
        if(searchT(matrix, target, rowS, rowS+i, colS+i, colE))
            return true;
        if(searchT(matrix, target, rowS+i, rowE, colS, colS+i))
            return true;
        return false;
    }
};
    
