// Last updated: 8/16/2026, 6:54:49 PM
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
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<int,vector<int>> adj;
        convert(root,adj,-1);
         queue<int> que;
        que.push(start);
        unordered_set<int> visited;
        visited.insert(start);
        int minutes = 0;

        while (!que.empty()) {
            int n = que.size();

            while (n--) {
                int curr = que.front();
                que.pop();

                for (int &ngbr : adj[curr]) {
                    if (visited.find(ngbr) == visited.end()) {
                        que.push(ngbr);
                        visited.insert(ngbr);
                    }
                }
            }
            minutes++;
        }

        return minutes - 1;
    }
    void convert(TreeNode* root,unordered_map<int,vector<int>>& adj,int parent){
        if(root==NULL){
            return;
        }
        if(parent!=-1){
            adj[root->val].push_back(parent);
        }
        if(root->left){
            adj[root->val].push_back(root->left->val);
        }
        if(root->right){
            adj[root->val].push_back(root->right->val);
        }
        convert(root->left,adj,root->val);
        convert(root->right,adj,root->val);

    }
};