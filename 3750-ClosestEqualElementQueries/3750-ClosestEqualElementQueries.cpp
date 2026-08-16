// Last updated: 8/16/2026, 6:50:39 PM
class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        int n=nums.size();
        unordered_map<int,vector<int>> mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]].push_back(i);
        }
        vector<int> ans;
        for(int i=0;i<queries.size();i++){
            int qi=queries[i];
            int element=nums[qi];
            vector<int>& indices=mp[element];
            int size=indices.size();
            if(indices.size()==1){
                ans.push_back(-1);
                continue;
            }
            int result=INT_MAX;
            int idx=lower_bound(begin(indices),end(indices),qi)-begin(indices);
            int rightIdx=indices[(idx+1)%size];
            
            int disToRight=abs(qi-rightIdx);
            int circulardis=n-disToRight;
            result=min({result,disToRight,circulardis});

            int leftIdx=indices[(idx-1+size)%size];
            disToRight=abs(qi-leftIdx);
            circulardis=n-disToRight;
            result=min({result,disToRight,circulardis});

            ans.push_back(result);
        }
        return ans;
    }
};