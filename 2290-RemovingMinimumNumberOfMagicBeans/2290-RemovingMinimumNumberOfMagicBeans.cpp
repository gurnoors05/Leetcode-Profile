// Last updated: 8/16/2026, 6:55:36 PM
class Solution {
public:
    long long minimumRemoval(vector<int>& beans) {
        int n=beans.size();
        sort(beans.begin(),beans.end());
        long long  mini=LLONG_MAX;
        long long sum=accumulate(beans.begin(),beans.end(),0LL);
        for(int i=0;i<beans.size();i++){
            long long target=beans[i];
            long long remaining=target*(n-i);
            mini=min(mini,sum-remaining);
        }
        return mini;
    }
};