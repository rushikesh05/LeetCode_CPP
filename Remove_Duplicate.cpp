// Input: nums = [1,1,2]
// Output: 2, nums = [1,2,_]
// Explanation: Your function should return k = 2, with the first two elements of nums being 1 and 2 respectively.
// It does not matter what you leave beyond the returned k (hence they are underscores).


#include <vector>

class Solution {
public:
    int removeDuplicates(std::vector<int>& nums) {
        int n = nums.size();
        if (n == 0) {
            return 0; // If the array is empty, return 0
        }

        int j = 0; // Pointer to track the position to insert unique elements

        for (int i = 1; i < n; ++i) {
            if (nums[i] != nums[j]) {
                // Copy the unique element at position i to position j+1
                nums[++j] = nums[i];
            }
            // If nums[i] is equal to nums[j], skip the duplicate and continue with the next element
        }

        // The first j+1 elements contain the unique elements
        return j + 1;
    }
};
