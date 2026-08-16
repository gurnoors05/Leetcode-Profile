// Last updated: 8/16/2026, 6:49:23 PM
class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string ans="";
        for(auto& word:words){
            int sum=0;
            for(int i=0;i<word.length();i++){
                int index=word[i]-'a';
                sum+=weights[index];
            }
            sum%=26;
            ans+=('z'-sum);
        }
        return ans;
    }
};