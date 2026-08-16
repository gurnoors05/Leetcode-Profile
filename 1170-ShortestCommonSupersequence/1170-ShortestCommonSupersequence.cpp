// Last updated: 8/16/2026, 7:04:55 PM
class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        string text1 = str1;
        string text2 = str2;

       int n=text1.size();
        int m=text2.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1));
        for(int i=0;i<n;i++){
            dp[i][0]=0;
        }
        for(int j=0;j<m;j++){
            dp[0][j]=0;
        }
        for(int i=1;i<n+1;i++){
            for(int j=1;j<m+1;j++){
                if(text1[i-1]==text2[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
    string result="";
        int i=n,j=m;
        while(i>0 && j>0){
            if(text1[i-1]==text2[j-1]){
                result.push_back(text1[i-1]);
                i--;
                j--;
            }
            else{
                if(dp[i-1][j]>dp[i][j-1]){
                    result.push_back(text1[i-1]);
                    i--;
                }
                else{
                    result.push_back(text2[j-1]);
                    j--;
                }
            }
        }
        while(i>0){
            result.push_back(text1[i-1]);
            i--;
        }
        while(j>0){
            result.push_back(text2[j-1]);
            j--;
        }
        reverse(begin(result),end(result));
        return result;

    }
};