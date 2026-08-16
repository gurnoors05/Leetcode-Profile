// Last updated: 8/16/2026, 6:59:09 PM
class Solution {
public:
    const int MOD=1e9+7;
    unordered_map<int,int> mp;
    vector<int> tree;
    // void build(vector<int>& instructions,int index,int left,int right){
    //     if(left==right){
    //         tree[index]=instructions[left];
    //         return;
    //     }
    //     int mid=left+(right-left)/2;
    //     build(instructions,2*index+1,left,mid);
    //     build(instructions,2*indx+2,mid+1,right);
    //     tree[index]=tree[2*index+1]+[2*index+2];
    // }
    void update(int i,int index,int left,int right){
        if(left==right){
            tree[index]++;
            return;
        }
        int mid=left+(right-left)/2;
        if(i<=mid){
            update(i,2*index+1,left,mid);
        }
        else{
            update(i,2*index+2,mid+1,right);
        }
        tree[index]=tree[2*index+1]+tree[2*index+2];
    }
    int query(int ql,int qr,int index,int left,int right){
        if(right<ql || left>qr){
            return 0;
        }
        // full overlap
        if(left>=ql && right<= qr){
            return tree[index];
        }
        int mid=(left+right)>>1;
        return query(ql,qr,2*index+1,left,mid) + query(ql,qr,2*index+2,mid+1,right);
    }
    int createSortedArray(vector<int>& instructions) {
       vector<int> sorted = instructions;
        sort(sorted.begin(), sorted.end());
        sorted.erase(unique(sorted.begin(),sorted.end()),sorted.end());
        int n=instructions.size();
        for(int i=0;i<sorted.size();i++){
            mp[sorted[i]]=i;
        }
        tree.resize(4*n,0);

        //build(instructions,0,0,n-1);

        int cost = 0;
        // Step 2: process left to right
        for(int i=0;i<instructions.size();i++){
            int idx = mp[instructions[i]];

            int less = (idx > 0) ? query(0, idx-1, 0, 0, n-1) : 0;
            int greater = (idx < n-1) ? query(idx+1, n-1, 0, 0, n-1) : 0;

            cost = (cost + min(less, greater)) % MOD;
            update(idx, 0, 0, n-1);
        }
        return cost;
    }
};