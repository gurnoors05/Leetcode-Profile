// Last updated: 8/16/2026, 7:07:34 PM
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
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        string s1="";
        string s2="";
        solve(root1,s1);
        solve(root2,s2);
        return s1==s2;
    }
    void solve(TreeNode* root,string &s){
        if(root==NULL){
            return;
        }
        if(root->left==NULL && root->right==NULL){
            s+=to_string(root->val)+'_';
            return;
        }
        solve(root->left,s);
        solve(root->right,s);
    }
};