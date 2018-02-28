// Implement pow(x, n).
// testCase for n=-2^31, consider overflow.

class Solution {
public:
    double myPow(double x, int n) {
        if(x<1e-6) valid=false;
        else valid=true;
        if(abs(x-1.0)<1e-6) return 1.0;
        double result=0.0;
        if(n<0) result = powRecurr(x, (unsigned int)(-n));
        else result = powRecurr(x, (unsigned int)(n));
        if(n<0)  result = 1.0/result;
        return result;
    }
private:
    bool valid;
    double powRecurr(double base, unsigned int n) {
        double result = 0.0;
        if(n==0) return 1.0;
        if(n==1) return base;
        result = powRecurr(base, n>>1);
        result *= result;
        if(n&0x01==1) result *= base; 
        return result;
    }
};
