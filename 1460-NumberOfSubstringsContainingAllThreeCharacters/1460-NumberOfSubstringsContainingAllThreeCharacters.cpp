// Last updated: 8/16/2026, 7:01:57 PM
class Solution {
public:
    int numberOfSubstrings(string s) {
        vector<int> hash(3,0);
        return solve(s,hash);
    }
    int solve(string s,vector<int> &hash){

        int l=0;
        int r=0;
        int n=s.size();
        int noOfSub=0;
        while(r<n){
            hash[s[r]-'a']++;
            while(hash[0]>0 && hash[1]>0 && hash[2]>0){
                noOfSub+=(n-r);
                hash[s[l]-'a']--;
                l++;
            }
            r++;
        }
        return noOfSub;
    }
};