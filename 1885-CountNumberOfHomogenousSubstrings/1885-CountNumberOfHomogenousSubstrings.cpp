// Last updated: 8/16/2026, 6:58:05 PM
class Solution {
public:
    int MOD = 1e9+7;
    int countHomogenous(string s) {
        int n=s.length();
        int i=0;
        int count=0;
        int result=0;
        while(i<n){
            if(i>0 && s[i]==s[i-1]){
                count++;
            }
            else{
                count=1;
            }
            result=(result+count)%MOD;
            i++;
        }
        return result;
    }
};