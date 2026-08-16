// Last updated: 8/16/2026, 7:05:36 PM
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
    int sumRootToLeaf(TreeNode* root) {
        return solve(root,0);
    }
    int solve(TreeNode* root,int val){
        if(root==NULL){
            return 0;
        }
        val=2*val+1*(root->val);
        if(root->left==NULL && root->right==NULL){
            return val;
        }
        return solve(root->left,val) + solve(root->right,val);
    }
};