// Last updated: 8/16/2026, 6:53:00 PM
class Solution {
public:
    bool checkStrings(string s1, string s2) {
        vector<int> evenIndices(26,0);
        vector<int> oddIndices(26,0);
        for(int i=0;i<s1.length();i++){
            if(i%2==0){
                evenIndices[s1[i]-'a']++;
                evenIndices[s2[i]-'a']--;
            }
            else{
                oddIndices[s1[i]-'a']++;
                oddIndices[s2[i]-'a']--;
            }
        }
        for(int i=0;i<26;i++){
            if(evenIndices[i]!=0 || oddIndices[i]!=0){
                return false;
            }
        }
        return true;
    }
};