/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int ans = 0;
    // Count = Average of subtree 

    int averageOfSubtree(TreeNode* root) {
        dfs(root);
        return ans;
    }

    vector<int> dfs(TreeNode* node) {
        if (node == nullptr) {
            return {0, 0};
        }

        vector<int> left = dfs(node->left);
        vector<int> right = dfs(node->right);

        int sum = left[0] + right[0] + node->val;
        int count = left[1] + right[1] + 1;

        if (node->val == sum / count) {
            ans++;
        }

        return {sum, count};
    }
};