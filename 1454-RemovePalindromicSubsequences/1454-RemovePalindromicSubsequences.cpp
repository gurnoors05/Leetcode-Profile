// Last updated: 8/16/2026, 7:02:08 PM
class Solution {
public:
    int removePalindromeSub(string s) {
        int i=0;
        int n=s.length()-1;
        int j=n;
        while(i<=j){
            if(s[i]==s[j]){
                i++;
                j--;
            }
            else{
                return 2;
            }
        }
        return 1;
    }
};