// Last updated: 8/16/2026, 7:06:18 PM
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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        map<int, vector<pair<int,int>>> mp; // level -> [row, value]
        dfs(root,0,0,mp);
        for(auto& [col,vec]:mp){ // columns , vector{row,value} ... First sort by row,if row is same then sort by value
            sort(begin(vec),end(vec), [](pair<int,int> &a, pair<int,int> &b){
                if(a.first!=b.first){
                    return a.first<b.first;
                }
                return a.second<b.second;
            });
            vector<int> temp;
            for(auto& [row,value]:vec){
                temp.push_back(value);
            }
            ans.push_back(temp);
        }
        return ans;
    }
    void dfs(TreeNode* root,int row,int col,map<int,vector<pair<int,int>>> &mp){
        if(root==NULL){
            return;
        }
        mp[col].push_back({row,root->val});
        if (root->left){
            dfs(root->left, row+1, col-1, mp);
        } // protect against cycles
        
        if (root->right){
            dfs(root->right, row+1, col+1, mp);
        } // protect against cycles
    }
};