// Last updated: 8/16/2026, 7:02:37 PM
class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n=arr.size();
        return solve(start,arr);
    }
    bool solve(int i,vector<int> &arr){
        if(i<0 || i>=arr.size() || arr[i]<0){
            return false;
        }   
        if(arr[i]==0){
            return true;
        }
        arr[i]*=-1;
        bool right=solve(i-arr[i],arr);
        bool left=solve(i+arr[i],arr);
        return left|| right;
    }
};