class Solution {
public:
    struct State {
        long long score;
        vector<int> ids;
    };

    bool better(const State& a, const State& b) {
        if (a.score != b.score)
            return a.score > b.score;

        return a.ids < b.ids;
    }

    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        int n = intervals.size();

        // {left, right, weight, original index}
        vector<array<int, 4>> a(n);

        for (int i = 0; i < n; i++) {
            a[i] = {
                intervals[i][0],
                intervals[i][1],
                intervals[i][2],
                i
            };
        }

        // Sort by starting point
        sort(a.begin(), a.end());

        vector<int> start(n);

        for (int i = 0; i < n; i++) {
            start[i] = a[i][0];
        }

        // next[i] = first interval whose left > a[i].right
        vector<int> next(n);

        for (int i = 0; i < n; i++) {
            next[i] = upper_bound(
                start.begin(),
                start.end(),
                a[i][1]
            ) - start.begin();
        }

        // dp[i][k] = best answer from i onward
        // using at most k intervals
        vector<vector<State>> dp(n + 1, vector<State>(5));

        // Base case
        for (int k = 0; k <= 4; k++) {
            dp[n][k] = {0, {}};
        }

        for (int i = n - 1; i >= 0; i--) {

            for (int k = 0; k <= 4; k++) {

                // Option 1: Don't take interval i
                State skip = dp[i + 1][k];

                // If we cannot take any more
                if (k == 0) {
                    dp[i][k] = skip;
                    continue;
                }

                // Option 2: Take interval i
                State take = dp[next[i]][k - 1];

                take.score += a[i][2];

                // Add original index
                take.ids.push_back(a[i][3]);

                // We need the final indices sorted
                sort(take.ids.begin(), take.ids.end());

                // Choose better answer
                if (better(take, skip))
                    dp[i][k] = take;
                else
                    dp[i][k] = skip;
            }
        }

        return dp[0][4].ids;
    }
};