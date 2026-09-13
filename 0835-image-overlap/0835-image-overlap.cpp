class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();
        int ans = 0;

        // Shift img1 by (dr, dc)
        for (int dr = -n + 1; dr < n; dr++) {
            for (int dc = -n + 1; dc < n; dc++) {

                int overlap = 0;

                for (int r = 0; r < n; r++) {
                    for (int c = 0; c < n; c++) {
                    //   after shifting new index of row and column
                        int nr = r + dr;
                        int nc = c + dc;

                        // Check whether shifted position is inside img2
                        // nr=new row nc=new column
                        if (nr >= 0 && nr < n &&
                            nc >= 0 && nc < n) {
                            //  r stand for row of orignal imag,similiarly for c
                            if (img1[r][c] == 1 && img2[nr][nc] == 1) {
                                overlap++;
                            }
                        }
                    }
                }

                ans = max(ans, overlap);
            }
        }

        return ans;
    }
};