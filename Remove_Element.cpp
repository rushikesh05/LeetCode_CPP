// Given an integer array nums and an integer val, remove all occurrences of val in nums in-place. The order of the elements may be changed. Then return the number of elements in nums which are not equal to val.

// Consider the number of elements in nums which are not equal to val be k, to get accepted, you need to do the following things:

// Change the array nums such that the first k elements of nums contain the elements which are not equal to val. The remaining elements of nums are not important as well as the size of nums.
// Return k.
// Custom Judge:

// Example 1:

// Input: nums = [3,2,2,3], val = 3
// Output: 2, nums = [2,2,_,_]
// Explanation: Your function should return k = 2, with the first two elements of nums being 2.
// It does not matter what you leave beyond the returned k (hence they are underscores).



#include <vector>

class Solution {
public:
    int removeElement(std::vector<int>& nums, int val) {
        int i = 0; // Pointer to iterate through the array
        int j = 0; // Pointer to track the position to insert elements not equal to val

        while (i < nums.size()) {
            if (nums[i] != val) {
                nums[j++] = nums[i]; // Copy element to position j and increment j
            }
            i++; // Always increment i to move through the array
        }

        return j; // j is the count of elements not equal to val
    }
};
