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

    int solve(int &maxsum, TreeNode* root){
        if (root == nullptr) {
            return 0;
        }

        int left = max(0, solve(maxsum, root->left));
        int right = max(0, solve(maxsum, root->right));

        // Maximum path passing through this node
        int currSum = root->val + left + right;

        maxsum = max(maxsum, currSum);

        // Return the maximum one-sided path to the parent
        return root->val + max(left, right);
    }

    int maxPathSum(TreeNode* root) {
        int maxsum = INT_MIN;
        solve(maxsum, root);
        return maxsum;
    }

};
