// Last updated: 8/16/2026, 6:52:43 PM
class Solution {
public:
    struct TrieNode{
        TrieNode* child[2];
        int count;
    };
    TrieNode* getNode(){
        TrieNode* newNode= new TrieNode();
        newNode->child[0]=NULL;
        newNode->child[1]=NULL;
        newNode->count=0;
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
            curr->count++;
        }
    }
    int findMaxXor(int val){
        TrieNode* curr=root;
        int sum=0;
        for(int i=31;i>=0;i--){
            int bit=(val>>i)&1;
            if(curr->child[!bit] && curr->child[!bit]->count>0){
                curr=curr->child[!bit];
                sum+=(1<<i);
            }
            else{
                curr=curr->child[bit];
            }
        }
        return sum;
    }
    void deleteNumber(int n){
        TrieNode* curr = root;
        for(int i=31;i>=0;i--) {
            int bit = (n>>i)&1;
            curr = curr->child[bit];
            curr->count--;
        }
    }
    int maximumStrongPairXor(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int l=0;
        int r=0;
        int maxXor=0;
        while(r<nums.size()){
            insert(nums[r]);
            while(nums[r]>2*nums[l]){
                deleteNumber(nums[l]);
                l++;
            }
            maxXor=max(maxXor,findMaxXor(nums[r]));
            
            r++;
        }
        return maxXor;
    }
};