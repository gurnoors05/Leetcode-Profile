// Last updated: 8/16/2026, 6:54:39 PM
class Solution {
public:
    int partitionString(string s) {
        vector<int> lastSeen(26,-1);
        int substringStart=0;
        int count=0;
        for(int i=0;i<s.length();i++){
            if(lastSeen[s[i]-'a']>=substringStart){
                count++;
                substringStart=i;
            }
            lastSeen[s[i]-'a']=i;
        }
        return count+1;
    }
};