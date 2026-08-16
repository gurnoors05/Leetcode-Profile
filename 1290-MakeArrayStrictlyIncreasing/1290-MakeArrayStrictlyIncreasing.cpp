// Last updated: 8/16/2026, 7:03:52 PM
class Solution {
public:
    map<pair<int,int>,int> mp;
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        mp.clear();
        sort(begin(arr2),end(arr2));
        int result=solve(arr1,arr2,0,INT_MIN);
        if(result==1e9+1){
            return -1;
        }
        return result;
    }
    int solve(vector<int>& arr1, vector<int>& arr2,int i,int prev){
        if(i>=arr1.size()){
            return 0;
        }
        if(mp.find({i,prev})!=mp.end()){
            return mp[{i,prev}];
        }
        int result1=1e9+1;
        int result2=1e9+1;
        if(arr1[i]>prev){
            result1=solve(arr1,arr2,i+1,arr1[i]);
        }
        auto it=upper_bound(begin(arr2),end(arr2),prev);
        if(it!=arr2.end()){
            int idx=it-arr2.begin();
            // arr1[i]=arr2[idx];
            result2=1+solve(arr1,arr2,i+1,arr2[idx]);
        }
        return mp[{i, prev}]=min(result1,result2);
    }
};