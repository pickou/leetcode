/*
回溯法一般都是要求列举所有情况，或者说所有情况都要讨论
1. 确定问题的解空间，这个解空间树至少包含一个你需要的解
2. 组织好这棵树，弄明白这棵树的每个节点代表什么，每个分支代表什么
3. 从这棵树的根节点不断的向下搜索，当遇到不合适的节点的时候直接跳过以这个几点为根的子树
4. 当搜索到叶子节点的时候就回溯
5. 不断重读3,4步
6. 根据具体的情况还可以定义限界条件，最优值条件，根据这两个条件可以剪枝

回溯法一般采用递归编写，那么递归写法一般是
T backtrace() {
 recursiveEnd(); //递归结束条件
 recursiveRule(); //递归的的规则
}

leetcode 经典例题
1. 52. N-Queens
2. 842. Split Array into Fibonacci Sequence
3. 36. Valid Sudoku
*/

// 52. N-Queens
//********************The code lies bug before, it's bug free now!************
class Solution {
public:
    int totalNQueens(int n) {
        int nums = 0;
        vector<int> pos(n);
        nQueens(pos, nums, n, 0);
        return nums;
    }
    
    void nQueens(vector<int> &pos, int &nums, int n, int k) {
        if(k==n){ // recursive end
            nums += 1;
            return;
        }

        for(int i=0; i<n; i++) { // recursive rule, each queen has 1~n position to place
            pos[k] = i;
            if(isValid(pos, k, i)) {
                // pos[k] = i;  bug lies here!!!!
                nQueens(pos, nums, n, k+1);
            }
        }
    }
    
    bool isValid(vector<int> &pos, int k, int l) {
        for(int i=0; i<k; i++) {
            if(pos[i]==pos[k]||abs(pos[k]-pos[i])==abs(k-i)) // same column or parrallel
                return false;
        }
        return true;
    }
};



// 842. Split Array into Fibonacci Sequence

using limit = std::numeric_limits<int>; // This is new to me
class Solution {
public:
	vector<int> splitIntoFibonacci(string S) {
    vector<int> res, solution;
    isFibonacci(S, res, solution, 0);
    return res;
  }
  bool isValid(vector<int>& nums, int num) {
    int n = nums.size();
    return n<2||nums[n-2]+nums[n-1]==num;
  }
  void isFibonacci(string S, vector<int>& res, vector<int>& solution, int k) {
    if(k==S.size()&&solution.size()>=3) { // recursive end
      res = solution;
      return;
    }
    for(int i=k; i<S.size(); i++) { // recursive rule
      string s = S.substr(k, i-k+1);
      if(s[0]=='0'&&s.size()>1) return; // no 0143 number exists
      long long num = stoll(s);
      if(num>limit::max()) return; // consider overflow
      if(isValid(solution, num)) {
        solution.push_back(num);
        isFibonacci(S, res, solution, i+1);
        solution.pop_back();
      }
    }
  }
 };
 
 // 36. Valid Sudoku
 //***************This code lies bug, Time exceed***********
 class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        vector<vector<char>> res(board.size(), vector<char>(board[0].size()));
        sudoku(board, res, 0);
        mmcopy(res, board);
        
    }
    void sudoku(vector<vector<char>>& board, vector<vector<char>>& res, int k) {
        if(k==81) {
            mmcopy(board, res);
            return;
        }
        int row = k/9;
        int col = k%9;
        if(board[row][col]!='.') {
            sudoku(board, res, k+1);
        }
        for(int i=0; i<=9; i++) {
            if(isValid(board, k, i+'0')) {
                board[row][col] = i+'0';
                sudoku(board, res, k+1);
                board[row][col] = '.'; // clear
            }
        }
    }
    void mmcopy(vector<vector<char>>& board, vector<vector<char>>& res){
        for(int i=0; i<board.size(); i++) {
            for(int j=0; j<board[0].size(); j++) {
                res[i][j] = board[i][j];
            }
        }
    }
    bool isValid(vector<vector<char>>& board, int k, char ch) {
        int row = k/9;
        int col = k%9;
        for(int i=0; i<9; i++) { // row check
            if(i!=col&&board[row][i]==ch)
                return false;
        }
        for(int i=0; i<9; i++) { // col check
            if(i!=row&&board[i][col]==ch)
                return false;
        }
        int secX = row/3;
        int secY = col/3; // which sub-box
        secX *= 3;
        secY *= 3;
        for(int i=secX; i<secX+3; i++) {
            for(int j=secY; j<secY+3; j++) {
                if(i!=row&&j!=col&&board[i][j]==ch)
                    return false;
            }
        }
        return true;
    }
};
