// Last updated: 8/16/2026, 7:06:32 PM
class Solution {
public:
 vector<int> parent;
    vector<int> size;
    int find(int u){
        if(parent[u]==u){
            return parent[u];
        }
        return parent[u]=find(parent[u]);
    }
    void Union(int u,int v){
        int u_parent=find(u);
        int v_parent=find(v);
        if(u_parent==v_parent){
            return;
        }
        if(size[u_parent]>size[v_parent]){
            parent[v_parent]=u_parent;
            size[u_parent]+=size[v_parent];
        }
        else if(size[v_parent]>size[u_parent]){
            parent[u_parent]=v_parent;
            size[v_parent]+=size[u_parent];
        }
        else{
             parent[v_parent]=u_parent;
             size[u_parent]+=size[v_parent];
        }
    }
    int largestComponentSize(vector<int>& nums) {
        int n=nums.size();
        int max_val=*max_element(nums.begin(),nums.end());
        parent.resize(max_val+1);
        size.resize(max_val+1);
        for(int i=0;i<=max_val;i++){
            parent[i]=i;
        }   
        for(int i=0;i<n;i++){
            size[nums[i]]=1;
        }
        for(int i=0;i<n;i++){
            for(int j=2;j*j<=nums[i];j++){
                if(nums[i]%j==0){
                    Union(nums[i],j);
                    if(nums[i]/j!=j){
                        Union(nums[i]/j,nums[i]);
                    }
                }

            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            int find_parent=find(nums[i]);
            ans=max(ans,size[find_parent]);
        }
        return ans;
    }
};