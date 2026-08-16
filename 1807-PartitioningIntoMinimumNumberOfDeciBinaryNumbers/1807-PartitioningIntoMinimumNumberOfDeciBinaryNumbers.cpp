// Last updated: 8/16/2026, 6:58:41 PM
class Solution {
public:
    int minPartitions(string n) {
        int ans=0;
        for(int i=0;i<n.length();i++){
            ans=max(ans,n[i]-'0');
        }
        return ans;
    }
};