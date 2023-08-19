class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0) {
            return 1.0;
        }
        
        if (n == 1) {
            return x;
        }
        
        if (n == -1) {
            return 1.0 / x;
        }
        
        double halfPow = myPow(x, n / 2);
        double result = halfPow * halfPow;
        
        if (n % 2 == 1) {
            result *= x;
        } else if (n % 2 == -1) {
            result *= 1.0 / x;
        }
        
        return result;
    }
};
