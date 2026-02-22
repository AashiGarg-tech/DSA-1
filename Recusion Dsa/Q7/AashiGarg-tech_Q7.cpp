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
                if (i > start && nums[i] == nums[i - 1]) continue;
                if (nums[i] > target) break;
    
                path.push_back(nums[i]);
                dfs(nums, i + 1, target - nums[i]);
                path.pop_back();
            }
        }
    
        vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
            sort(candidates.begin(), candidates.end());
            dfs(candidates, 0, target);
            return res;
        }
    };