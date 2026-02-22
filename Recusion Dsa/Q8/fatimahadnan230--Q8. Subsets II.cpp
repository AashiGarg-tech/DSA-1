#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    /**
     * helper function to build subsets using backtracking.
     * to avoid duplicates, we sort the array and skip identical 
     * elements at the same recursion level.
     */
    void backtrack(vector<int>& nums, int start, vector<int>& current, vector<vector<int>>& result) {
        // add the current combination to the result set
        result.push_back(current);

        for (int i = start; i < nums.size(); i++) {
            // skip duplicates: if the current number is the same as the previous 
            // one in this loop, it would result in a duplicate subset.
            if (i > start && nums[i] == nums[i - 1]) {
                continue;
            }

            // include the element
            current.push_back(nums[i]);
            
            // move to the next element in the array
            backtrack(nums, i + 1, current, result);
            
            // backtrack: remove the element to try other combinations
            current.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> current;
        
        // sorting is crucial so that duplicate elements are adjacent
        sort(nums.begin(), nums.end());
        
        backtrack(nums, 0, current, result);
        return result;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 2, 2};
    
    vector<vector<int>> powerSet = sol.subsetsWithDup(nums);

    // displaying the results
    cout << "possible subsets (power set):" << endl;
    for (const auto& subset : powerSet) {
        cout << "[ ";
        for (int x : subset) cout << x << " ";
        cout << "]" << endl;
    }

    return 0;
}