// Last updated: 8/16/2026, 6:49:37 PM
class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,vector<int>> mp;
        for(int i=0;i<n;i++){
            mp[nums[i]].push_back(i);
        }
        int ans=INT_MAX;
        for(auto& it:mp){
            vector<int> indices=it.second;
            if (indices.size() < 3) continue;
            for(int i=0;i+2<indices.size();i++){
                ans=min(ans,2*(indices[i+2]-indices[i]));
            }
        }
        return ans==INT_MAX?-1:ans;;
    }
};