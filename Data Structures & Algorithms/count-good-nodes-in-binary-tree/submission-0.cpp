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

    int solve(TreeNode* root, int maxValue){
        if(root == NULL){
            return 0;
        }

        int count = 0;

        if(root->val >= maxValue){
            count = 1;
        }

        maxValue = max(maxValue, root->val);

        int left = solve(root->left, maxValue);
        int right = solve(root->right, maxValue);

        return count + left + right;
    }

    int goodNodes(TreeNode* root) {
        int count = 0;
        return solve(root, root->val);
    }
};
