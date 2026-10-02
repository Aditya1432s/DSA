class Solution {
public:
    void solve(int n, int open, int close, string s, vector<string>& ans) {

        // If string has 2*n brackets, it is complete
        if (s.length() == 2 * n) {
            ans.push_back(s);
            return;
        }

        // Add opening bracket
        if (open < n) {
            solve(n, open + 1, close, s + "(", ans);
        }

        // Add closing bracket only when it is valid
        if (close < open) {
            solve(n, open, close + 1, s + ")", ans);
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;

        solve(n, 0, 0, "", ans);

        return ans;
    }
};