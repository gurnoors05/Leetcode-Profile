// Last updated: 8/16/2026, 7:03:13 PM
class Solution {
public:
    unordered_map<string, int> mp;
    int maxLength(vector<string>& arr) {
        mp.clear();
        string temp="";
        return solve(arr,temp,0);
    }
    int solve(vector<string>& arr,string temp,int i){
        int n=arr.size();
        if(i>=n){
            return temp.length();
        }
        if(mp.find(temp)!=mp.end()){
            return mp[temp];
        }
        int exclude=0;
        int include=0;
        if(hasCommon(arr[i],temp)){
            exclude=solve(arr,temp,i+1);
        }
        else{
            exclude=solve(arr,temp,i+1);
            temp+=arr[i];
            include=solve(arr,temp,i+1);
        }
        return mp[temp]=max(include,exclude);
    }
    bool hasCommon(string& s1,string& s2){
        vector<int> arr(26,0);
        for(char& c:s1){
            if(arr[c-'a']>0){
                return true;
            }
            arr[c-'a']++;
        }
        for(char& c:s2){
            if(arr[c-'a']>0){
                return true;
            }
        }
        return false;

    }
};