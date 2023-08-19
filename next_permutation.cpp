// Given a string containing just the characters '(' and ')', return the length of the longest valid (well-formed) parentheses 
// substring
// .

 

// Example 1:

// Input: s = "(()"
// Output: 2
// Explanation: The longest valid parentheses substring is "()".
// Example 2:

// Input: s = ")()())"
// Output: 4
// Explanation: The longest valid parentheses substring is "()()".
// Example 3:

// Input: s = ""
// Output: 0
 

// Constraints:

// 0 <= s.length <= 3 * 104
// s[i] is '(', or ')'.


class Solution {
public:
    int longestValidParentheses(string s) {
        int maxLen = 0;
        stack<int> stk;
        stk.push(-1); // Initialize with a sentinel value
        
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                stk.push(i); // Push the index of '('
            } else {
                stk.pop(); // Pop the top element (corresponding '(' or sentinel)
                if (stk.empty()) {
                    stk.push(i); // Push the current index as a sentinel
                } else {
                    maxLen = max(maxLen, i - stk.top()); // Update max length
                }
            }
        }
        
        return maxLen;
    }
};
