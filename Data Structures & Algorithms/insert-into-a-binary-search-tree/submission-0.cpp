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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        // base case
        if(root == NULL){
            root = new TreeNode(val);
            return root;
        }

        if(val > root -> val){
            // right part me insert karna h
            root -> right = insertIntoBST(root -> right, val);
        }
        else{
            // left part me insert karna h
            root -> left = insertIntoBST(root -> left, val);
        }

        return root;
    }
};