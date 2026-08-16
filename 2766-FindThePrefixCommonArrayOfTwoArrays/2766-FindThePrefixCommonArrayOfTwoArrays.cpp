// Last updated: 8/16/2026, 6:53:24 PM
class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        unordered_map<int,int> mp;
        vector<int> ans(A.size());
        int count=0;
        for(int i=0;i<A.size();i++){
            mp[A[i]]++;
            if(mp[A[i]]==2){
                count++;
            }
            mp[B[i]]++;
            if(mp[B[i]]==2){
                count++;
            }
            ans[i]=count;
        }
        return ans;
    }
};