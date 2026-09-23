class Solution {
public:
// best approach TC = O(nlogn + n^2) SC = O(uniquetirples)
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>> result;

        for(int i = 0; i<n; i++){
            // optimisation first to check duplicate of i can not use twice
            if(i>0 && nums[i] == nums[i-1]) continue;
            int low = i+1,high = n-1;

            while(low < high){
                int sum = nums[i] + nums[low] + nums[high];
                if(sum < 0){
                    low++;
                }else if (sum > 0){
                    high--;
                }else{
                    result.push_back({nums[i],nums[low],nums[high]});
                    low++;
                    high--;
                    // optimisation second to check duplicate of low  can not use twice
                    while(low<high && nums[low] == nums[low - 1]) low++;
                }
            }        
        }
        return result;  
    }
};