// about Catalan number 
// http://www.cnblogs.com/wuyuegb2312/p/3016878.html
/*
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        addingpar(res, "", n, 0);
        return res;
    }
    void addingpar(vector<string> &v, string str, int n, int m) {
        if(n==0 && m==0) {
            v.push_back(str);
            return;
        }
        if(m > 0) { addingpar(v, str+")", n, m-1); }
        if(n > 0) { addingpar(v, str+"(", n-1, m+1); }
    }
};
*/
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        if(n==0) return vector<string>(1, "");
        if(n==1) return vector<string>(1, "()");
        vector<string> res;
        for(int i=0; i<n; i++) {
            for(auto inner: generateParenthesis(i)) {
                for(auto outer: generateParenthesis(n-i-1))
                    res.push_back("("+inner+")"+outer);
            }
        }
        return res;
    }
};
