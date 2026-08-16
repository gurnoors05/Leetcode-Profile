// Last updated: 8/16/2026, 6:57:59 PM
class Solution {
public:
    int maxScore(vector<int>& nums) {
        vector<bool> visited(nums.size(),false);
        unordered_map<vector<bool>,int> mp;
        return solve(nums,visited,1,mp);
    }
    int solve(vector<int>& nums,vector<bool>& visited,int operation,unordered_map<vector<bool>,int>& mp){
        int n=nums.size();
        int maxScore=0;
        if(mp.find(visited)!=mp.end()){
            return mp[visited];
        }
        for(int i=0;i<n-1;i++){
            if(visited[i]==true){
                continue;
            }
            for(int j=i+1;j<n;j++){
                if(visited[j]==true){
                    continue;
                }
                visited[i]=true;
                visited[j]=true;
                int score=operation*__gcd(nums[i],nums[j]);
                int remaining=solve(nums,visited,operation+1,mp);
                maxScore=max(maxScore,score+remaining);
                visited[i]=false; // backtrack
                visited[j]=false;
            }
        }
        return mp[visited]=maxScore;
    }
};