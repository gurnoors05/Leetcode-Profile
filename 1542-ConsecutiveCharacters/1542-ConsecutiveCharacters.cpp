// Last updated: 8/16/2026, 7:00:58 PM
class Solution {
public:
    // int maxPower(string s) {
    //     int l=0;
    //     int r=0;
    //     int n=s.size();
    //     unordered_map<int,int> mp;
    //     int result=0;
    //     while(r<n){
    //         mp[s[r]-'a']++;
    //         if(mp.size()>=2){
    //             while(mp.size()>=2){
    //                 mp[s[l]-'a']--;
    //                 if(mp[s[l]-'a']==0){
    //                     mp.erase(s[l]-'a');
    //                 }
    //                 l++;
    //             }
    //         }
    //         result=max(result,r-l+1);
    //         r++;
    //     }
    //     return result;

    // }

    int maxPower(string s) {
        int n = s.size();
        int result = 1, count = 1;

        for (int i = 1; i < n; i++) {
            if (s[i] == s[i - 1]) {
                count++;
                result = max(result, count);
            } else {
                count = 1;
            }
        }
        return result;
    }
};