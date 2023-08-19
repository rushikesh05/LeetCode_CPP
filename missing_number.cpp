// iven an array nums containing n distinct numbers in the range [0, n], return the only number in the range that is missing from the array.

 

// Example 1:

// Input: nums = [3,0,1]
// Output: 2
// Explanation: n = 3 since there are 3 numbers, so all numbers are in the range [0,3]. 2 is the missing number in the range since it does not appear in nums.


#include <vector>

class Solution {
public:
    int missingNumber(std::vector<int>& nums) {
        int n = nums.size();
        int expectedSum = n * (n + 1) / 2;
        int actualSum = 0;

        for (int num : nums) {
            actualSum += num;
        }

        return expectedSum - actualSum;
    }
};

// Explanation:

// The code calculates the size of the array n and the expected sum of all numbers in the range [0, n] using the formula n * (n + 1) / 2.
// It initializes actualSum to 0, which will be used to calculate the sum of elements in the nums array.
// The for loop iterates through the elements in the nums array and accumulates the sum in the actualSum.
// Finally, it subtracts the actualSum from the expectedSum, and the result will be the missing number in the range [0, n].