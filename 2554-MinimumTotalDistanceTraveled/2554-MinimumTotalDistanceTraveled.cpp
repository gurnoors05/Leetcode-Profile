// Last updated: 8/16/2026, 6:54:15 PM
class Solution {
public:
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        sort(begin(robot),end(robot));
        sort(begin(factory),end(factory));
        vector<int> positions;
        for(int i=0;i<factory.size();i++){
            int pos=factory[i][0];
            int limit=factory[i][1];
            for(int i=0;i<limit;i++){
                positions.push_back(pos);
            }
        }
        vector<vector<long long>> dp(robot.size()+1,vector<long long>(positions.size()+1,-1));
        return solve(robot,positions,0,0,dp);
    }
    long long solve(vector<int>& robot,vector<int>& positions,int r,int f,vector<vector<long long>>& dp){
        if(r>=robot.size()){
            return 0;
        }
        if(f>=positions.size()){
            return 1e12;
        }
        if(dp[r][f]!=-1){
            return dp[r][f];
        }

        long long take=abs(robot[r]-positions[f])+solve(robot,positions,r+1,f+1,dp);
        long long skip=solve(robot,positions,r,f+1,dp);
        return dp[r][f]=min(take,skip);
    }
};