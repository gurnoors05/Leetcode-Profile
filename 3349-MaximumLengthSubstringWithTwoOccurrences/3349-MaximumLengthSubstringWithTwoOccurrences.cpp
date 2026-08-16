// Last updated: 8/16/2026, 6:51:54 PM
class Solution {
public:
    int maximumLengthSubstring(string s) {
        unordered_map<char,int> mp;
        int l=0;
        int r=0;
        int n=s.length();
        int result=INT_MIN;
        while(r<n){
            mp[s[r]]++;
            if(mp[s[r]]>2){
                while(mp[s[r]]>2){
                    mp[s[l]]--;
                    l++;
                }
            }
            result=max(result,r-l+1);
            r++;
        }
        return result;
    }
};