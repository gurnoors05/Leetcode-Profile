// Last updated: 8/16/2026, 6:51:37 PM
class Solution {
public:
    int numberOfSpecialChars(string word) {
        unordered_set<char> st(word.begin(),word.end());
        int count=0;
        for(char c='a';c<='z';c++){
            if(st.count(c) && st.count(c-'a'+'A')){
                count++;
            }
        }
        return count;
    }
};