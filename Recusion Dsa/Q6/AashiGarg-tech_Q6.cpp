class Solution {
    public:
        vector<vector<int>> res;
        vector<int> path;
    
        void dfs(vector<int>& nums, int start, int target) {
            if (target == 0) {
                res.push_back(path);
                return;
            }
    
            for (int i = start; i < nums.size(); i++) {
                if (nums[i] > target) continue;
    
                path.push_back(nums[i]);
                dfs(nums, i, target - nums[i]);   // i (not i+1) → reuse allowed
                path.pop_back();
            }
        }
    
        vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
            sort(candidates.begin(), candidates.end());
            dfs(candidates, 0, target);
            return res;
        }
    };