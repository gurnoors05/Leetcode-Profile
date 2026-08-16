// Last updated: 8/16/2026, 6:49:24 PM
class Solution {
public:
    string largestEven(string s) {
        int lastTwo=-1;
        for(int i=0;i<s.length();i++){
            if(s[i]=='2'){
                lastTwo=i;
            }
        }
        if(lastTwo==-1){
            return "";
        }
        return s.substr(0,lastTwo+1);
    }
};