// Last updated: 8/16/2026, 7:05:13 PM
class Solution {
public:
    int dp[1001][1001];
    int longestStrChain(vector<string>& words) {
        memset(dp,-1,sizeof(dp));
        sort(begin(words),end(words),myfunction);
        return solve(words,0,-1);
    }
    static bool myfunction(string& word1,string& word2){
        return word1.length()<word2.length();
    }
    int solve(vector<string>& words,int i,int prev){
        int n=words.size();
        if(i==n){
            return 0;
        }
        if(prev!=-1 && dp[prev][i]!=-1){
            return dp[prev][i];
        }
        int take=0,skip=0;
        if(prev==-1 || ispred(words[prev],words[i])){
            take=1+solve(words,i+1,i);
        }
        skip=solve(words,i+1,prev);
        if(prev!=-1){
            dp[prev][i]=max(take,skip);
        }
        return max(take,skip);
    }
    bool ispred(string& prev, string& curr) {
        int M = prev.length();
        int N = curr.length();
        
        if(M >= N || N-M != 1)
            return false;
        
        int i = 0, j = 0;
        while(i < M && j < N) {
            if(prev[i] == curr[j]) {
                i++;
            }
            j++;
        }
        return i==M;
    }
};