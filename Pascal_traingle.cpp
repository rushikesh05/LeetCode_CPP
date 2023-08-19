// Given an integer numRows, return the first numRows of Pascal's triangle.

// In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:


 

// Example 1:

// Input: numRows = 5
// Output: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]
// Example 2:

// Input: numRows = 1
// Output: [[1]]
 

// Constraints:

// 1 <= numRows <= 30

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;

        for (int i = 0; i < numRows; ++i) {
            vector<int> row(i + 1, 1); // Initialize each row with 1s

            // Calculate values for the current row (except the first and last elements)
            for (int j = 1; j < i; ++j) {
                row[j] = result[i - 1][j - 1] + result[i - 1][j];
            }

            result.push_back(row);
        }

        return result;
    }
};
