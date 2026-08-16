// Last updated: 8/16/2026, 7:00:11 PM
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
    int countPairs(TreeNode* root, int distance) {
        unordered_map<TreeNode*,vector<TreeNode*>> mp;
        unordered_set<TreeNode*> st;
        makeGraph(root,mp,st,NULL);
        int count=0;
        for(auto& leaves:st){
            queue<TreeNode*> q;
            q.push(leaves);
            unordered_set<TreeNode*> visited;
            visited.insert(leaves);
            for(int level=0;level<=distance;level++){
                int size=q.size();
                while(size--){
                    TreeNode* curr=q.front();
                    q.pop();
                    if(curr!=leaves && st.find(curr)!=st.end()){
                        count++;
                    }
                    for(auto& neigh:mp[curr]){
                        if(visited.find(neigh)==visited.end()){
                            q.push(neigh);
                            visited.insert(neigh);
                        }
                    }
                }
            }
        }
        return count/2;
    }
    void makeGraph(TreeNode* root,unordered_map<TreeNode*,vector<TreeNode*>>& mp,unordered_set<TreeNode*> &st,TreeNode* prev){
        if(root==NULL){
            return;
        }
        if(root->left==NULL && root->right==NULL){
            st.insert(root);
        }
        if(prev!=NULL){
            mp[root].push_back(prev);
            mp[prev].push_back(root);
        }
        makeGraph(root->left,mp,st,root);
        makeGraph(root->right,mp,st,root);

        
    }
};