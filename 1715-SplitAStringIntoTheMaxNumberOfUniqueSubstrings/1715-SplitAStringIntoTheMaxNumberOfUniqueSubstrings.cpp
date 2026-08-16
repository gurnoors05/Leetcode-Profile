// Last updated: 8/16/2026, 6:59:40 PM
class Solution {
public:
    int maxUniqueSplit(string s) {
        int currCount=0;
        int maxCount=0;
        unordered_set<string> st;
        solve(0,currCount,maxCount,s,st);
        return maxCount;
    }
    void solve(int i,int currCount,int& maxCount,string &s,unordered_set<string> &st){
        int n=s.length();
        if(i>=n){
            maxCount=max(maxCount,currCount);
            return;
        }
        for(int j=i;j<n;j++){
            string sub=s.substr(i,j-i+1);
            if(st.find(sub)==st.end()){
                st.insert(sub);
                solve(j+1,currCount+1,maxCount,s,st);
                st.erase(sub);
            }
        }

    }
};