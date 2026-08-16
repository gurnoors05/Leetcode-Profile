// Last updated: 8/16/2026, 6:57:24 PM
class Solution {
public:
        // Recursion + memo - TLE
//     int dp[100001];
//     bool canReach(string s, int minJump, int maxJump) {
//         memset(dp,-1,sizeof(dp));
//         return solve(s,minJump,maxJump,0);
//     }
//     bool solve(string& s,int minJump, int maxJump,int i){
//         if(i==s.length()-1){
//             return true;
//         }
//         if(dp[i]!=-1){
//             return dp[i];
//         }
//         for(int j=i+minJump;j<=min((int)i + maxJump, (int)s.length() - 1);j++){
//             if(j>=s.length()){
//                 break;
//             }
//             if(s[j]=='0'){
//                 if(solve(s,minJump,maxJump,j)){
//                     return dp[i]= true;
//                 }
//             }
            
//         }
//         return dp[i]=false;
//     }


        // Bottom up - TLE
    // bool canReach(string s, int minJump, int maxJump) {
    //     int n=s.length();
    //     vector<bool> dp(s.length(),false);
    //     dp[n-1]=true;
    //     for(int i=n-2;i>=0;i--){
    //         for(int j=minJump;j<=maxJump;j++){
    //             int jump=j+i;
    //             if(jump>=n){
    //                 break;
    //             }
    //             if(s[jump]=='0'){
    //                 if(dp[jump]==true){
    //                     dp[i]=true;
    //                     break;
    //                 }
    //             }
    //         }
    //     }
    //     return dp[0];
    // }


    // Using sliding window
    bool canReach(string s, int minJump, int maxJump) {
        int n=s.length();
        int count=0;
        vector<int> dp(n,0);
        dp[0]=1;
        for(int i=1;i<=s.length()-1;i++){
            if(i-minJump>=0){
                count+=dp[i-minJump];
            }
            if(i-maxJump-1>=0){
                count-=dp[i-maxJump-1];
            }
            if(count>0 && s[i]=='0'){
                dp[i]=1;
            }
        }
        return dp[n-1]>0;
    }
};