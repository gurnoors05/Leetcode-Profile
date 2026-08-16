// Last updated: 8/16/2026, 7:07:10 PM
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
    unordered_map<int,vector<TreeNode*>> dp;
    vector<TreeNode*> allPossibleFBT(int n) {
        if(n%2==0){
            return {};
        }
        if(n==1){
            TreeNode* root=new TreeNode(0);
            return {root};
        }
        if(dp.find(n)!=dp.end()){
            return dp[n];
        }
        vector<TreeNode*> result;
        for(int i=1;i<n;i+=2){
            vector<TreeNode*> leftFBT=allPossibleFBT(i);
            vector<TreeNode*> rightFBT=allPossibleFBT(n-i-1);
            for(auto& l:leftFBT){
                for(auto& r:rightFBT){
                    TreeNode* root=new TreeNode(0);
                    root->left=l;
                    root->right=r;
                    result.push_back(root);
                }
            }
        }
        return dp[n]=result;
    }
};