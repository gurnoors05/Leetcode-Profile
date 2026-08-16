// Last updated: 8/16/2026, 7:00:47 PM
class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int n=s.length();
        int permutations=pow(2,k);
        // cout<<permutations;
        unordered_set<string> st;
        for(int i=0;i+k<=n;i++){
            string sub=s.substr(i,k);
            st.insert(sub);
            // cout<<sub;
        }
        return st.size()==permutations;
    }
};