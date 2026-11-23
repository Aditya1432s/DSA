
class Solution {
public:
    int m, n;

    bool dfs(vector<vector<char>>& board, string& word,
             int i, int j, int index) {

        // All characters matched
        if (index == word.size())
            return true;

        // Check boundaries
        if (i < 0 || j < 0 || i >= m || j >= n)
            return false;

        // Character does not match
        if (board[i][j] != word[index])
            return false;

        // Mark cell as visited
        char ch = board[i][j];
        board[i][j] = '#';

        // Explore four directions
        bool found =
            dfs(board, word, i + 1, j, index + 1) ||
            dfs(board, word, i - 1, j, index + 1) ||
            dfs(board, word, i, j + 1, index + 1) ||
            dfs(board, word, i, j - 1, index + 1);

        // Backtrack: restore original character
        board[i][j] = ch;

        return found;
    }

    bool exist(vector<vector<char>>& board, string word) {

        m = board.size();
        n = board[0].size();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (board[i][j] == word[0]) {
                    if (dfs(board, word, i, j, 0))
                        return true;
                }
            }
        }

        return false;
    }
};
