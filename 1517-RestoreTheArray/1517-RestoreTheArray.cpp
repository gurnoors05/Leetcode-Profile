// Last updated: 8/16/2026, 7:01:22 PM
class Solution {
public:
const int MOD=1e9+7;
    int numberOfArrays(string s, int k) {
        vector<int> dp(s.length(), -1);
        return solve(0,s,k,dp);
    }
    int solve(int start,string &s,int k,vector<int>& dp){
        if(start==s.length()){
            return 1;
        }
        if(dp[start]!=-1){
            return dp[start];
        }
        if(s[start]=='0'){
            return dp[start]=0;
        }
        long num=0;
        long long ans=0;
        for(int end=start;end<s.length();end++){
            num=(num*10)+(s[end]-'0');
            if(num>k){
                break;
            }
            ans = (ans%MOD + solve(end+1, s, k,dp)%MOD)%MOD;
        }
        return dp[start]=ans;
    }
};