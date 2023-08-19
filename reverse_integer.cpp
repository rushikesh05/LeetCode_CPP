// Given a signed 32-bit integer x, return x with its digits reversed. If reversing x causes the value to go outside the signed 32-bit integer range [-231, 231 - 1], then return 0.

// Assume the environment does not allow you to store 64-bit integers (signed or unsigned).

 

// Example 1:

// Input: x = 123
// Output: 321
// Example 2:

// Input: x = -123
// Output: -321
// Example 3:

// Input: x = 120
// Output: 21
 

// Constraints:

// -231 <= x <= 231 - 1


class Solution {
public:
    int reverse(int x) {
        int reversed = 0;
        
        while (x != 0) {
            int lastDigit = x % 10;
            if (reversed > INT_MAX / 10 || (reversed == INT_MAX / 10 && lastDigit > 7)) {
                return 0; // Overflow
            }
            if (reversed < INT_MIN / 10 || (reversed == INT_MIN / 10 && lastDigit < -8)) {
                return 0; // Overflow
            }
            
            reversed = reversed * 10 + lastDigit;
            x /= 10;
        }
        
        return reversed;
    }
};