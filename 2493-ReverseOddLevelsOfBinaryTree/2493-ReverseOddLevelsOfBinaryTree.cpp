// Last updated: 8/16/2026, 6:54:36 PM

 // Definition for a binary tree node.
// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
// };
 
class Solution {
public:
    void dfs(TreeNode* leftchild,TreeNode* rightchild,int currentlevel){
        if(leftchild==NULL || rightchild==NULL){
            return;
        }
        if(currentlevel%2==0){
            swap(leftchild->val,rightchild->val);
        }
        dfs(leftchild->left,rightchild->right,currentlevel+1);
        dfs(leftchild->right,rightchild->left,currentlevel+1);
    }
    TreeNode* reverseOddLevels(TreeNode* root) {
        dfs(root->left,root->right,0);
        return root;
    }
};