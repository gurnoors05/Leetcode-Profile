// Last updated: 8/16/2026, 6:59:17 PM
class Solution {
public:
    int dp[1001][1001];
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        vector<pair<int,int>> players;
        for(int i = 0; i < scores.size(); i++) {
            players.push_back({ages[i], scores[i]});
        }
        sort(players.begin(), players.end());
        memset(dp,-1,sizeof(dp));
        return solve(players,0,-1);
    }
    int solve(vector<pair<int,int>> &players,int i,int prevScore){
        if(i==players.size()){
            return 0;
        }
        if(dp[i][prevScore+1]!=-1){
            return dp[i][prevScore+1];
        }
        int take;
        int skip;
        if(prevScore!=-1 && players[i].second<players[prevScore].second){
            return solve(players,i+1,prevScore);
        }
        else{
            take=players[i].second+solve(players,i+1,i);
            skip=solve(players,i+1,prevScore);
        }
        return dp[i][prevScore+1]=max(take,skip);
    }
};