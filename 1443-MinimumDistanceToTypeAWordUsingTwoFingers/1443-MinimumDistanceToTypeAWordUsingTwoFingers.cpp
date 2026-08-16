// Last updated: 8/16/2026, 7:02:24 PM
class Solution {
public:
    int dp[301][28][28];
    int minimumDistance(string word) {
        memset(dp,-1,sizeof(dp));
        return solve(word,27,27,0);
    }
    int solve(string word,int f1,int f2,int i){
        if(i>=word.length()){
            return 0;
        }
        if(dp[i][f1][f2]!=-1){
            return dp[i][f1][f2];
        }
        int curr=word[i]-'A';
        if(f1==27 && f2==27){ // both fingers are in air, and we can take any of them, but as they will form symmetry accoring to tree diagram, i m taking f1 first, ( but we can also take f2 as it will form symmetry)
           return dp[i][f1][f2]=solve(word,curr,f2,i+1);

        }

        if(f2==27){ // f2 is still in air
            int takef2 = solve(word,f1,curr,i+1);
            int takef1 = getdis(f1,curr) + solve(word,curr,f2,i+1);
            return dp[i][f1][f2]=min(takef1,takef2);
        }
        // if both f1 and f2 used
        int takef1=getdis(f1,curr)+solve(word,curr,f2,i+1);
        int takef2=getdis(f2,curr)+solve(word,f1,curr,i+1);
        return dp[i][f1][f2]=min(takef1,takef2);
    }
    int getdis(int f1,int curr){
        auto [x1,y1]=findCoordinates(f1);
        auto [x2,y2]=findCoordinates(curr);
        return abs(x1-x2)+abs(y1-y2);
    }
    pair<int,int> findCoordinates(int ch){
        return {ch/6,ch%6};
    }
};