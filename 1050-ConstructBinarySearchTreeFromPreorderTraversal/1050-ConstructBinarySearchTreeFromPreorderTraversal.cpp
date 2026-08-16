// Last updated: 8/16/2026, 7:05:54 PM
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
    // We can also solve this by making inorder array by sorting the preorder array, because in bst, inorder array is always sorted, but it will give Larger T.C
    // So we will use upper bound now
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i=0;
        return solve(preorder,i,INT_MAX);
    }
    TreeNode* solve(vector<int>& preorder,int& i,int upper_bound){
        if(i==preorder.size() || preorder[i]>upper_bound){
            return NULL;
        }
        TreeNode* root=new TreeNode(preorder[i++]);
        root->left=solve(preorder,i,root->val);
        root->right=solve(preorder,i,upper_bound);
        return root;
    }
};