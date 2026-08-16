// Last updated: 8/16/2026, 6:55:24 PM
class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int,int> mp;
        int round=0;
        for(int& t:tasks){
            mp[t]++;
        }
        for(auto& it:mp){
            int task=it.second;
            if(task==1){
                return -1;
            }
            if(task%3==0){
                round+=task/3;
            }
            else{
                round+=(task/3)+1;
            }
        }
        return round;
    }
};