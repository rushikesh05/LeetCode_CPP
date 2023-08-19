// A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include letters and numbers.

// Given a string s, return true if it is a palindrome, or false otherwise.

 

// Example 1:

// Input: s = "A man, a plan, a canal: Panama"
// Output: true
// Explanation: "amanaplanacanalpanama" is a palindrome.

#include <string>
#include <cctype>

class Solution {
public:
    bool isPalindrome(std::string s) {
        int left = 0;
        int right = s.length() - 1;

        while (left < right) {
            while (left < right && !std::isalnum(s[left])) {
                left++;
            }

            while (left < right && !std::isalnum(s[right])) {
                right--;
            }

            if (std::tolower(s[left]) != std::tolower(s[right])) {
                return false;
            }

            left++;
            right--;
        }

        return true;
    }
};
