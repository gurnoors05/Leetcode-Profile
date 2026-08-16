// Last updated: 8/16/2026, 7:00:52 PM
class Solution {
public:
    int m,n;
    int apples[51][51];
    int dp[55][55][15];
    long long MOD = 1e9 + 7;
    int ways(vector<string>& pizza, int k) {
        m=pizza.size();
        n=pizza[0].size();
        memset(apples,0,sizeof(apples));
        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                apples[i][j]=apples[i][j+1];
                for(int c=i;c<m;c++){
                    apples[i][j]+=(pizza[c][j]=='A');
                }
            }
        }   
        memset(dp,-1,sizeof(dp));
        return solve(0,0,k);
    }
    int solve(int i,int j,int k){
        if(apples[i][j]<k){
            return 0;
        }
        if(k==1){
            if(apples[i][j]>=1){
                return 1;
            }
            return 0;
        }
        if(dp[i][j][k]!=-1){
            return dp[i][j][k];
        }
        int ans=0;
        //Horizontal cuts;
        for(int h=i+1;h<m;h++){
            int lower_cut=apples[h][j];
            int upper_cut=apples[i][j]-lower_cut;
            if(upper_cut>=1 && lower_cut>=k-1){
                ans = (ans % MOD + solve(h, j, k - 1) % MOD) % MOD;
            }
        }
        for(int v=j+1;v<n;v++){
            int right_cut=apples[i][v];
            int left_cut=apples[i][j]-right_cut;
            if(left_cut>=1 && right_cut>=k-1){
                ans = (ans % MOD + solve(i, v, k - 1) % MOD) % MOD;
            }
        }
        return dp[i][j][k]=ans;
    }
};