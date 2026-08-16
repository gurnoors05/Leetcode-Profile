// Last updated: 8/16/2026, 6:54:11 PM
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
    int minimumOperations(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int swaps=0;
        while(!q.empty()){
            int size=q.size();
            vector<int> value(size);
            for(int i=0;i<size;i++){
                TreeNode* cur=q.front();
                value[i]=cur->val;
                q.pop();
                if(cur->left!=NULL){
                    q.push(cur->left);
                }
                if(cur->right!=NULL){
                    q.push(cur->right);
                }
            }
            swaps+=countswaps(value);
        }
        return swaps;    
    }
    int countswaps(vector<int> value){
        int swaps=0;
        vector<int> sorted=value;
        unordered_map<int,int> mp;
        for(int i=0;i<value.size();i++){
            mp[value[i]]=i;
        }
        sort(sorted.begin(),sorted.end());
        for(int i=0;i<sorted.size();i++){
            if(value[i]!=sorted[i]){
                swaps++;
                int existingpos=mp[sorted[i]];
                mp[value[i]]=existingpos;
                mp[sorted[i]]=i;
                swap(value[existingpos],value[i]);
            }
        }
        return swaps;

    }
};