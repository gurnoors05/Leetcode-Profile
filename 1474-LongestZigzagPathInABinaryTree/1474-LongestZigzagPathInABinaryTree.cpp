// Last updated: 8/16/2026, 7:01:43 PM
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
    int maxPath=0;
    int longestZigZag(TreeNode* root) {
        solve(root,0,false);
        solve(root,0,true);
        return maxPath;
    }
    void solve(TreeNode* root,int length,bool goLeft){
        if(root==NULL){
            return;
        }
        maxPath=max(maxPath,length);
        if(goLeft){
            solve(root->left,length+1,false);
            solve(root->right,1,true);
        }
        else{
            solve(root->left,1,false);
            solve(root->right,length+1,true);
            
        }
    }
};