// Last updated: 8/16/2026, 7:01:50 PM
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
    long maxP=0;
    long MOD=1e9+7;
    long totalSum=0;
    int maxProduct(TreeNode* root) {
        totalSum=solve(root);
        solve(root);
        return maxP%MOD;
    }
    int solve(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        int leftSum=solve(root->left);
        int rightSum=solve(root->right);
        int sum=root->val+leftSum+rightSum;
        maxP=max(maxP,(totalSum-sum)*sum);
        return sum;
    }
};