class Solution {
public:
//     Capacity To Ship Pakages With in D days 

   bool isValid(vector<int>& nums,int days,int mid){
    int weight =0;
    int part = 1;
    for(int i =0; i< nums.size(); i++){
        if(nums[i] > mid) return false;

        if(weight + nums[i] <= mid){
            weight+= nums[i];
        }else{
            part++;
            weight = nums[i];
        }
        if(part > days) 
         return false;
    }
    return true;
   }
    int shipWithinDays(vector<int>& nums, int days) {

         int ans =-1;
         int low = *max_element(nums.begin(),nums.end());
         int high = accumulate(nums.begin(),nums.end(),0);

         while(low <= high){

            int mid = low +( high - low)/2;

            if(isValid(nums,days,mid)){
                ans = mid;
                high = mid -1;
            }else{
                low = mid +1;
            }

         }
         return ans ;
        
    }
};