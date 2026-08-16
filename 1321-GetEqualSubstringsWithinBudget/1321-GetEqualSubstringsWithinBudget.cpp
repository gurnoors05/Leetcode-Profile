// Last updated: 8/16/2026, 7:03:36 PM
class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        return solve(s,t,maxCost);
    }
    int solve(string s,string t,int maxCost){
        int l=0;
        int r=0;
        int n=s.length();
        int max_length=INT_MIN;
        while(r<n){
            int absDiff= abs((s[r]-'a')-(t[r]-'a'));
            maxCost-=absDiff;
            while(maxCost<0){
                int diff=abs((s[l]-'a')-(t[l]-'a'));
                maxCost+=diff;
                l++;
            }
            int length=r-l+1;
            max_length=max(max_length,length);
            r++;

        }
        return max_length;
    }
};