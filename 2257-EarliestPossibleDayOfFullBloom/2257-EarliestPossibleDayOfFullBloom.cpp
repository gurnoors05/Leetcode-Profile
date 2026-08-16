// Last updated: 8/16/2026, 6:55:43 PM
class Solution {
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        int n=plantTime.size();
        vector<pair<int,int>> vec(n);
        for(int i=0;i<plantTime.size();i++){
            vec[i]={plantTime[i],growTime[i]};
        }
        auto lambda=[](pair<int,int> &p1, pair<int,int> &p2){
            return p1.second>p2.second;
        };
        sort(vec.begin(),vec.end(),lambda);
        int maxBloomDays=0;
        int currPlantDays=0;
        for(int i=0;i<vec.size();i++){
            int plantTime=vec[i].first;
            int growTime=vec[i].second;
            currPlantDays+=plantTime;
            maxBloomDays=max(maxBloomDays, growTime+currPlantDays);
        }
        return maxBloomDays;
    }
};