class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        const int INF = 1e9;

        vector<int> dp(n + 1, INF);

        int left = 0;
        long long sum = 0;
        int ans = INF;

        for (int right = 0; right < n; right++) {
            sum += arr[right];

            while (sum > target) {
                sum -= arr[left++];
            }

            // Subarray [left ... right] has target sum
            if (sum == target) {
                int len = right - left + 1;

                // Best subarray completely before 'left'
                if (dp[left] != INF) {
                    ans = min(ans, dp[left] + len);
                }

                // Store the shortest valid subarray seen so far
                dp[right + 1] = min(dp[right], len);
            } 
            else {
                dp[right + 1] = dp[right];
            }
        }

        return ans == INF ? -1 : ans;
    }
};