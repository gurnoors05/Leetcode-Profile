// Last updated: 8/16/2026, 6:50:12 PM
class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int waterAfterLand=solve(landStartTime,landDuration,waterStartTime,waterDuration);
        int landAfterWater=solve(waterStartTime,waterDuration,landStartTime,landDuration);
        return min(waterAfterLand,landAfterWater);
    }
    int solve(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration){
        int start1=INT_MAX;
        for(int i=0;i<landStartTime.size();i++){
            start1=min(start1,landStartTime[i]+landDuration[i]);
        }
        int start2=INT_MAX;
        for(int i=0;i<waterStartTime.size();i++){
            start2=min(start2,max(start1,waterStartTime[i])+waterDuration[i]);
        }
        return start2;
    }
};