// Last updated: 8/16/2026, 6:52:41 PM
class Solution {
public:
    long long minimumSteps(string s) {
        long long swaps=0;
        int black=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='0'){
                swaps+=black;
            }
            else{
                black++;
            }
        }
        return swaps;
    }
};