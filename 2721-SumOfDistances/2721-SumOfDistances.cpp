// Last updated: 8/16/2026, 6:53:28 PM
class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        unordered_map<int,vector<int>> mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]].push_back(i);
        }
        vector<long long> res(nums.size());
        for(auto& m:mp){
            vector<int>& v=m.second;
            int n=v.size();
            
            vector<long long> prev(n,0);
            prev[0]=v[0];
            for(int i=1;i<n;i++){
                prev[i]=prev[i-1]+v[i];
            }
            for(int i=0;i<n;i++){
                long long left=0;
                long long right=0;
                if(i>0){
                    left=(long long)i*v[i]-prev[i-1];
                }
                if(i<n-1){
                    right=(prev[n-1]-prev[i])-(long long)(n-i-1)*v[i];
                }
                res[v[i]]=left+right;

            }
        }
        return res;
    }
};