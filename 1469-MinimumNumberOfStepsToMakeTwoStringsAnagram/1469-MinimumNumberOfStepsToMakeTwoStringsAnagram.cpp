// Last updated: 8/16/2026, 7:01:46 PM
class Solution {
public:
    int minSteps(string s, string t) {
        int n=s.length();
        int m=t.length();
        int chars_in_s[26]={};
        int chars_in_t[26]={};
        for(int i=0;i<s.length();i++){
            chars_in_s[s[i]-'a']++;
            chars_in_t[t[i]-'a']++;
        }
        int result=0;
        for(int i=0;i<26;i++){
            int char_s=chars_in_s[i];
            int char_t=chars_in_t[i];\
            if(char_t<char_s){
                result+=char_s-char_t;
            }
        }
        return result;
    }
};