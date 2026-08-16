// Last updated: 8/16/2026, 6:58:27 PM
class Solution {
public:
struct TrieNode{
      TrieNode* child[2];
  };
  TrieNode* getNode(){
      TrieNode* newNode= new TrieNode();
      newNode->child[0]=NULL;
      newNode->child[1]=NULL;
      return newNode;
  }
  TrieNode* root;
  Solution(){
      root=getNode();
  }
  void insert(int n){
      TrieNode* curr=root;
      for(int i=31;i>=0;i--){
          int bit=(n>>i)&1;
          
          if(curr->child[bit]==NULL){
              TrieNode* newNode=getNode();
              curr->child[bit]=newNode;
             
          }
           curr=curr->child[bit];
      }
  }
  int findMaxXor(int val){
      TrieNode* curr=root;
      int sum=0;
      for(int i=31;i>=0;i--){
          int bit=(val>>i)&1;
          if(curr->child[!bit]){
              curr=curr->child[!bit];
              sum+=(1<<i);
          }
          else{
              curr=curr->child[bit];
          }
      }
      return sum;
  }
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        for(int i=0;i<queries.size();i++){
            queries[i].push_back(i);
        }
        sort(queries.begin(),queries.end(),[&](auto& a,auto& b){
            return a[1]<b[1];
        });
        sort(nums.begin(),nums.end());
        int idx=0;
        vector<int> ans(queries.size());
        for(auto& q:queries){
            int u=q[0];
            int v=q[1];
            int index=q[2];
            int i=0;
            while(idx < nums.size() && nums[idx] <= v){
                insert(nums[idx]);
                idx++;
            }
            if(idx == 0){
                ans[index] = -1;
            }
            else{
                ans[index] = findMaxXor(u);
            }
        }
        return ans;
    }
};