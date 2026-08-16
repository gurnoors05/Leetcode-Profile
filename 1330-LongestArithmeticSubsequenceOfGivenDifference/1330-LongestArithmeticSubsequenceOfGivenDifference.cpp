// Last updated: 8/16/2026, 7:03:27 PM
class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        unordered_map<int,int> mp;
        int result=0;
        for(int i=0;i<arr.size();i++){
            mp[arr[i]]=mp[arr[i]-difference]+1;
            result=max(result,mp[arr[i]]);
        }
        return result;
    }
};