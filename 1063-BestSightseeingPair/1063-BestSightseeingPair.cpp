// Last updated: 8/16/2026, 7:05:42 PM
class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int ans=0;
        int prev=values[0];
        for(int j=1;j<values.size();j++){
            ans=max(ans,prev+values[j]-j);
            prev=max(prev,values[j]+j);
        }
        return ans;
    }
};