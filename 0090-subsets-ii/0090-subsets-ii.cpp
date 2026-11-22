
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;

        sort(nums.begin(), nums.end());

        function<void(int)> solve = [&](int index) {
            ans.push_back(temp);

            for (int i = index; i < nums.size(); i++) {
                if (i > index && nums[i] == nums[i - 1]) {
                    continue;
                }

                temp.push_back(nums[i]);

                solve(i + 1);

                temp.pop_back();
            }
        };

        solve(0);

        return ans;
    }
};
