// Last updated: 8/16/2026, 6:51:08 PM
class Solution {
public:
    int countKConstraintSubstrings(string s, int k) {
        int l=0;
        int r=0;
        int count0=0;
        int count1=0;
        int n=s.size();
        int ans=0;
        while(r<n){
            if(s[r]=='0'){
                count0++;
            }
            else{
                count1++;
            }
            while(count0>k && count1>k){
                if(s[l]=='0'){
                    count0--;
                }
                else{
                    count1--;
                }
                l++;
            }
            ans+=r-l+1;
            r++;
        }
        return ans;
    }
};