class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> current;
        
        // Sort the candidates to simplify the backtracking process
        sort(candidates.begin(), candidates.end());
        
        backtrack(candidates, target, 0, 0, current, result);
        
        return result;
    }
    
    void backtrack(vector<int>& candidates, int target, int start, int sum, vector<int>& current, vector<vector<int>>& result) {
        if (sum == target) {
            result.push_back(current);
            return;
        }
        
        for (int i = start; i < candidates.size(); ++i) {
            if (sum + candidates[i] <= target) {
                current.push_back(candidates[i]);
                backtrack(candidates, target, i, sum + candidates[i], current, result);
                current.pop_back();
            } else {
                break; // No need to continue if the sum exceeds the target
            }
        }
    }
};
