// Last updated: 8/16/2026, 6:55:29 PM
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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int,TreeNode*> mp; // value -> to its node
        unordered_set<int> children;
        for(auto& d:descriptions){
            int p=d[0];
            int c=d[1];
            int isLeft=d[2];
            if(mp.find(p)==mp.end()){
                mp[p]=new TreeNode(p);
            }
            if(mp.find(c)==mp.end()){
                mp[c]=new TreeNode(c);
            }
            if(isLeft==1){
                mp[p]->left=mp[c];
            }
            else{
                mp[p]->right=mp[c];
            }
            children.insert(c);
        }
        for(auto& nodes:mp){
            int val=nodes.first;
            TreeNode* actualNode=nodes.second;
            if(children.find(val)==children.end()){
                return actualNode; // Means it is a parent
            }
        }
        return NULL;
    }
};