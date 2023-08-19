// Given two strings s and goal, return true if you can swap two letters in s so the result is equal to goal, otherwise, return false.

// Swapping letters is defined as taking two indices i and j (0-indexed) such that i != j and swapping the characters at s[i] and s[j].

// For example, swapping at indices 0 and 2 in "abcd" results in "cbad".
 

// Example 1:

// Input: s = "ab", goal = "ba"
// Output: true
// Explanation: You can swap s[0] = 'a' and s[1] = 'b' to get "ba", which is equal to goal.


#include <string>
#include <unordered_set>

class Solution {
public:
    bool buddyStrings(string s, string goal) {
        if (s.length() != goal.length()) {
            return false;
        }

        if (s == goal) {
            unordered_set<char> seen;
            for (char c : s) {
                if (seen.count(c) > 0) {
                    return true; // There are repeated characters in s.
                }
                seen.insert(c);
            }
            return false; // s and goal are the same, but no repeated characters.
        }

        int firstDiff = -1, secondDiff = -1;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] != goal[i]) {
                if (firstDiff == -1) {
                    firstDiff = i;
                } else if (secondDiff == -1) {
                    secondDiff = i;
                } else {
                    return false; // More than two differences found.
                }
            }
        }

        // Check if swapping the characters at firstDiff and secondDiff makes s and goal equal.
        return (secondDiff != -1) && (s[firstDiff] == goal[secondDiff]) && (s[secondDiff] == goal[firstDiff]);
    }
};
