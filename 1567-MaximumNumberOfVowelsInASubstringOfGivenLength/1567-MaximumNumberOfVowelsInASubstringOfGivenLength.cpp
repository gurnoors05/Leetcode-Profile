// Last updated: 8/16/2026, 7:00:44 PM
class Solution {
public:
    int maxVowels(string s, int k) {
        return solve(s,k);
    }
    int solve(string s,int k){
        int l=0;
        int r=0;
        int n=s.size();
        int count=0;
        int max_count=INT_MIN;
        while(r<n){
            if(isVowel(s[r])){
                count++;
            }
            if((r-l+1)==k){
                max_count=max(count,max_count);
                if(isVowel(s[l])){
                    count--;
                }
                l++;
            }
            r++;
        }
        return max_count;
    }
    bool isVowel(char ch){
        if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u'){
            return true;
        }
        return false;
        
    }
};