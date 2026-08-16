// Last updated: 8/16/2026, 7:05:28 PM
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
    int maxAncestorDiff(TreeNode* root) {
        int min_val=INT_MAX;
        int max_val=INT_MIN;
        return solve(root,min_val,max_val);
    }
    int solve(TreeNode* root,int mini,int maxi){
        if(!root){
            return abs(maxi-mini);
        }
        mini=min(mini,root->val);
        maxi=max(maxi,root->val);
        int l=solve(root->left,mini,maxi);
        int r=solve(root->right,mini,maxi);
        return max(l,r);
    }
};