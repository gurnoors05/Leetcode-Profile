// Last updated: 8/16/2026, 6:59:58 PM
class Solution {
public:
    string makeGood(string s) {
        string result="";
        for(char& ch:s){
            if(result.size()>0 && (ch+32==result.back() || ch-32==result.back())){
                result.pop_back();
            }
            else{
                result.push_back(ch);
            }
        }
        return result;
    }
};