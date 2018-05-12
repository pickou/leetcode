/*
Given four lists A, B, C, D of integer values, compute how many tuples (i, j, k, l) there are such that A[i] + B[j] + C[k] + D[l] is zero.

To make problem a bit easier, all A, B, C, D have same length of N where 0 ≤ N ≤ 500. All integers are in the range of -228 to 228 - 1 and the result is guaranteed to be at most 231 - 1.
*/

// upper_bound and lower_bound is binary search.

class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        vector<int> suma;
        int N = A.size();
        if(N==0) return 0;
        for(int i=0; i<N; i++) {
            for(int j=0; j<N; j++)
                suma.push_back(A[i]+B[j]);
        }
        sort(suma.begin(), suma.end());
        vector<int> sumb;
        for(int i=0; i<N; i++) {
            for(int j=0; j<N; j++)
                sumb.push_back(C[i]+D[j]);
        }
        int cnt = 0, target;
        for(int i=0; i<suma.size(); i++) {
            target = 0-sumb[i];
            cnt += upper_bound(suma.begin(), suma.end(), target)-
                lower_bound(suma.begin(), suma.end(), target);
        }
        return cnt;
    }
};
