// Last updated: 8/16/2026, 6:52:00 PM
class Solution {
public:
    long long countSubstrings(string s, char c) {
        long long count=0;
        long long substrings=0;
        for(char& ch:s){
            if(ch==c){
                substrings+=(1+count);
                count++;
            }
        }
        return substrings;
    }
};