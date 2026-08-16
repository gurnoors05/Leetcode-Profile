// Last updated: 8/16/2026, 7:06:15 PM
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
    string result="";
    string smallestFromLeaf(TreeNode* root) {
        solve(root,"");
        return result;
    }
    void solve(TreeNode* root,string curr){
        if(root==NULL){
            return;
        }
        curr=char(root->val+'a')+curr;
        if(root->left==NULL && root->right==NULL){
            if(result=="" || result>curr){
                result=curr;
            }
        }
        solve(root->left,curr);
        solve(root->right,curr);
    }
};