// Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.

// A mapping of digits to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.


 

// Example 1:

// Input: digits = "23"
// Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]

#include <vector>
#include <string>

class Solution {
public:
    std::vector<std::string> letterCombinations(std::string digits) {
        std::vector<std::string> result;
        if (digits.empty()) {
            return result;
        }
        
        std::vector<std::string> mapping = {
            "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"
        };
        
        std::string current;
        backtrack(result, digits, mapping, current, 0);
        return result;
    }
    
private:
    void backtrack(std::vector<std::string>& result, const std::string& digits, const std::vector<std::string>& mapping, std::string& current, int index) {
        if (index == digits.size()) {
            result.push_back(current);
            return;
        }
        
        int digit = digits[index] - '0';
        for (char c : mapping[digit]) {
            current.push_back(c);
            backtrack(result, digits, mapping, current, index + 1);
            current.pop_back();
        }
    }
};
