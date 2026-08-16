// Last updated: 8/16/2026, 6:59:45 PM
class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int prevMax=0;
        int ans=0;
        for(int i=0;i<colors.length();i++){
            if(i>0 && colors[i]!=colors[i-1]){
                prevMax=0;
            }
            int curr=neededTime[i];
            ans+=min(prevMax,curr);
            prevMax=max(prevMax,curr);
        }
        return ans;
    }
};