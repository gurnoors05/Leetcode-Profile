// Last updated: 8/16/2026, 6:54:53 PM
class Solution {
public:
    long long minimumReplacement(vector<int>& arr) {
        int n=arr.size();
        long long operations=0;
        for(int i=n-2;i>=0;i--){
            if(arr[i]>arr[i+1]){
                int parts=arr[i]/arr[i+1];
                if(arr[i] % arr[i+1] !=0){
                    parts+=1;
                }
                operations += parts-1;
                arr[i] = arr[i]/parts; // Leftmost element after split
            }
        }
        return operations;
    }
};