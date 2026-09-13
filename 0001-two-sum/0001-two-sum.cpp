class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
    std::unordered_map<int,int>num_map;
    for(int i=0;i< nums.size(); ++i){
        int num=nums[i];
        int complement=target-num;
        if( num_map.count(complement)){
            return {num_map[complement],i};
        }
        num_map[num]=i;
    }
    return {};  
    } 
};