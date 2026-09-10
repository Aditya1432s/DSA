class Solution {
public:
//  split Array Largets Sum ,Time complexity O(nlog(sun(nums)))
   bool isValid(vector<int> & nums, int k ,int mid ){
    int split =1;
       int sum = 0;

       for(int i =0; i<nums.size(); i++){

        if(nums[i]> mid){
            return false;
        }
        if(sum + nums[i] <= mid){
            sum+=nums[i];
        }else{
            split++;
            sum = nums[i];
        }
        if(split>k)
            return false;
       }
      return true;  
   }
    int splitArray(vector<int>& nums, int k) {
        int ans =-1;
        int low = *max_element(nums.begin(),nums.end());
        int high = accumulate(nums.begin(),nums.end(),0);

        while(low <= high){
            int mid = low + (high -low)/2;

            if(isValid(nums,k,mid)){
                ans = mid;
                high = mid -1;
            }else{
                low = mid +1;
            }
        }
        return ans;
    }
};