// Last updated: 8/16/2026, 6:56:58 PM
class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n = s.size();
        unordered_set<char> letters;
        for(int i=0;i<n;i++){
            letters.insert(s[i]);
        }
        int result=0;
        for(char letter:letters){
            int left_most=-1;
            int right_most=-1;
            for(int i=0;i<n;i++){
                if(s[i]==letter){
                    if(left_most==-1){
                        left_most=i;
                    }
                    right_most=i;
                }
            }
            unordered_set<char> st;
            for(int middle=left_most+1;middle<right_most;middle++){
                st.insert(s[middle]);
            }
            result += st.size();
        }
        return result;
    }
};