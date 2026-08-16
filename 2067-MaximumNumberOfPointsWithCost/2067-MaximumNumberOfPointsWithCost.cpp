// Last updated: 8/16/2026, 6:56:55 PM
class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        int n=points.size();
        int m=points[0].size();
        vector<long long> prev(m);
        for(int i=0;i<m;i++){
            prev[i]=1ll*points[0][i];
        }
        for(int row=1;row<n;row++){
            vector<long long> leftmax(m);
            long long maxi=LLONG_MIN;
            for(int k=0;k<m;k++){
                maxi=max(maxi,prev[k]+k);
                leftmax[k]=maxi;
            }
            maxi=LONG_MIN;
            vector<long long> rightmax(m);
            for(int k=m-1;k>=0;k--){
                maxi=max(maxi,prev[k]-k);
                rightmax[k]=maxi;
            }
            for(int j=0;j<m;j++){
                prev[j]=(max(leftmax[j]-j,rightmax[j]+j))+points[row][j];
            }

        }
        return *max_element(prev.begin(),prev.end());
    }


    // TLE
    // vector<vector<long long>> dp;
    // long long maxPoints(vector<vector<int>>& points) {
    //     int n=points.size();
    //     int m=points[0].size();
    //     dp.assign(n,vector<long long>(m,-1));
    //     return solve(points,0,-1);
    // }
    // long long solve(vector<vector<int>>& points,int row,int prevCol){
    //     if(row==points.size()){
    //         return 0;
    //     }
    //     if(prevCol!=-1 && dp[row][prevCol]!=-1){
    //         return dp[row][prevCol];
    //     }
    //     long long result=0;
    //     for(int i=0;i<points[0].size();i++){
    //         long long take=(points[row][i]-(prevCol==-1?0:abs(i-prevCol)))+solve(points,row+1,i);
    //         result=max(result,take);
    //     }
    //     if(prevCol!=-1){
    //         return dp[row][prevCol]=result;
    //     }
    //     return result;
    // }
};