// Given a string s, find the first non-repeating character in it and return its index. If it does not exist, return -1.

 

// Example 1:

// Input: s = "leetcode"
// Output: 0
// Example 2:

// Input: s = "loveleetcode"
// Output: 2
// Example 3:

// Input: s = "aabb"
// Output: -1
 

// Constraints:

// 1 <= s.length <= 105
// s consists of only lowercase English letters.

class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> freqMap;
        
        // Store the frequency of each character
        for (char ch : s) {
            freqMap[ch]++;
        }
        
        // Find the first non-repeating character and return its index
        for (int i = 0; i < s.length(); ++i) {
            if (freqMap[s[i]] == 1) {
                return i;
            }
        }
        
        return -1; // No non-repeating character found
    }
};
