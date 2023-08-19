// Input: nums = [0,1,0,3,12]
// Output: [1,3,12,0,0]


#include <vector>

class Solution {
public:
    void moveZeroes(std::vector<int>& nums) {
        int j = 0; // Pointer to track the position to insert non-zero elements

        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != 0) {
                nums[j++] = nums[i]; // Copy non-zero element to position j and increment j
            }
        }

        // Set remaining elements after j to zero
        while (j < nums.size()) {
            nums[j++] = 0;
        }
    }
};
