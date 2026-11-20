
class Solution {
public:
    vector<vector<int>> ans;
    vector<int> temp;

    void solve(vector<int>& nums, int index) {
        // Every current combination is a valid subset
        ans.push_back(temp);

        for (int i = index; i < nums.size(); i++) {
            // Include current element
            temp.push_back(nums[i]);

            // Explore next elements
            solve(nums, i + 1);

            // Backtrack
            temp.pop_back();
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        solve(nums, 0);
        return ans;
    }
};
