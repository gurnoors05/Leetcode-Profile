// Last updated: 8/16/2026, 7:07:42 PM
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    unordered_map<TreeNode*,TreeNode*> parent;
    void inorder(TreeNode* root){
        if(root==NULL){
            return;
        }
        if(root->left!=NULL){
            parent[root->left]=root;
        }
        inorder(root->left);
        if(root->right!=NULL){
            parent[root->right]=root;
        }
        inorder(root->right);

    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        inorder(root);
        unordered_set<int> visited;
        queue<TreeNode*> q;
        q.push(target);
        visited.insert(target->val);
        while(!q.empty()){
            int size=q.size();
            if(k==0){
                break;
            }
            while(size--){
                TreeNode* node=q.front();
                q.pop();
                if(node->left!=NULL && !visited.count(node->left->val)){
                    q.push(node->left);
                    visited.insert(node->left->val);
                }
                if(node->right!=NULL && !visited.count(node->right->val)){
                    q.push(node->right);
                    visited.insert(node->right->val);
                }
                if(parent.count(node) && !visited.count(parent[node]->val)){
                    q.push(parent[node]);
                    visited.insert(parent[node]->val);
                }
            }
            k--;
        }
        vector<int> result;
        while(!q.empty()){
            TreeNode* curr=q.front();
            q.pop();
            result.push_back(curr->val);
        }
        return result;
    }
};