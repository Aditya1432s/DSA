class Solution {
public:
    int totalNumbers(vector<int>& digits) {

        int ans = 0;
    //    range of 3 digit numbers
        for (int num = 100; num <= 999; num++) {

            // Number must be even
            if (num % 2 != 0)
                continue;

            int x = num;
        //    extract numbers from x like once tens hundred 
            int d1 = x % 10;
            x /= 10;

            int d2 = x % 10;
            x /= 10;

            int d3 = x % 10;

            vector<int> freq(10, 0);
//  count frequency of exract numbers in digit 
            for (int d : digits) {
                freq[d]++;
            }

            if (freq[d1] > 0) {
                freq[d1]--;
            }
            else {
                continue;
            }

            if (freq[d2] > 0) {
                freq[d2]--;
            }
            else {
                continue;
            }

            if (freq[d3] > 0) {
                ans++;
            }
        }

        return ans;
    }
};