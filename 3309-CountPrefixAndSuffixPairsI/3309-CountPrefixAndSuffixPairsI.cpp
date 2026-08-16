// Last updated: 8/16/2026, 6:52:11 PM
class Solution {
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int n=words.size();
        int ans=0;
        for(int i=0;i<n;i++){
            string str1 = words[i];
            for(int j=i+1;j<n;j++){
                string str2=words[j];
                if(str2.length() < str1.length()){
                    continue;
                }
                string pre=str2.substr(0,str1.length());
                string suff=str2.substr(str2.length()-str1.length());
                if(pre==words[i] && suff==words[i]){
                    ans++;
                }
            }
        }
        return ans;
    }
};