class Solution {
public:
    int divide(int dividend, int divisor) {
        // Handle overflow cases
        if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX;
        }
        
        // Determine the sign of the result
        int sign = (dividend < 0) ^ (divisor < 0) ? -1 : 1;
        
        // Convert both dividend and divisor to positive
        long long ldividend = abs((long long)dividend);
        long long ldivisor = abs((long long)divisor);
        
        long long quotient = 0;
        while (ldividend >= ldivisor) {
            long long temp = ldivisor;
            long long multiple = 1;
            
            // Multiply the divisor by 2 until it's smaller than dividend
            while (ldividend >= (temp << 1)) {
                temp <<= 1;
                multiple <<= 1;
            }
            
            // Subtract the multiple of divisor from dividend
            ldividend -= temp;
            quotient += multiple;
        }
        
        return sign * quotient;
    }
};
