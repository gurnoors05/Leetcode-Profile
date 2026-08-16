// Last updated: 8/16/2026, 7:04:30 PM
class Solution {
public:
    vector<int> result;
    unordered_map<string,int> dp;
    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
        int n=req_skills.size();
        unordered_map<string,int> skills;
        for(int i=0;i<n;i++){
            skills[req_skills[i]]=i;
        }
        vector<int> peopleSkills;
        for(int i=0;i<people.size();i++){
            int skillBits=0;
            for(string& skill:people[i]){
                skillBits |= 1<<skills[skill];
            }
            peopleSkills.push_back(skillBits);
        }
        int targetSkills=pow(2,n)-1;
        vector<int> temp;
        solve(peopleSkills,0,0,targetSkills,temp);
        return result;
    }
    void solve(vector<int>& peopleSkills,int idx,int mask,int targetSkills,vector<int> &temp){
        if(idx>=peopleSkills.size()){
            if(mask==targetSkills){
                if(result.size()==0 || result.size()>=temp.size()){
                    result=temp;
                }
            }
            return;
        }
        string key=to_string(idx) + '_' + to_string(mask);
        if(dp.find(key)!=dp.end()){
            if(dp[key]<=temp.size()){
                return;
            }
        }
        if(result.size()!=0 && temp.size()>=result.size()){
            return;
        }
        solve(peopleSkills,idx+1,mask,targetSkills,temp);
        if((mask | peopleSkills[idx]) !=mask ){
            temp.push_back(idx);
            solve(peopleSkills,idx+1,mask | peopleSkills[idx],targetSkills,temp);
            temp.pop_back();
            dp[key] = (temp.size() != 0 ) ? temp.size() : -1;
        }

    }
};