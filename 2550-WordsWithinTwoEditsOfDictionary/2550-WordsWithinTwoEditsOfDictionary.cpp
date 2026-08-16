// Last updated: 8/16/2026, 6:54:23 PM
class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        vector<string> result;
        for(string& q:queries){
            for(auto& s:dictionary){
                int diff=0;
                for(int i=0;i<s.length();i++){
                    if(q[i]!=s[i]){
                        diff++;
                    }
                    if(diff>2){
                        break;
                    }
                }
                if(diff<=2){
                    result.push_back(q);
                    break;
                }
            }
        }
        return result;
    }
};