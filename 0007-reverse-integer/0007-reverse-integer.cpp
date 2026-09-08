class Solution {
public:
    int reverse(int x) {
        int res = 0;
        while(x!=0){
            // logic to reverse 
            int digit = x % 10;
            x = x/10;
            
            // condition for posite range of res.
            if(res> INT_MAX/10 || ( res == INT_MAX/10 && digit > 7))
            return 0;

        // condition for negative range of res.
            if(res< INT_MIN/10 || ( res == INT_MIN/10 && digit <-8))
            return 0;

            res = res * 10 + digit;
             
        }
         return res;
    }
   
};