// Last updated: 8/16/2026, 7:00:10 PM
class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<int> lastZeros(n);
        for(int i=0;i<n;i++){
            int j=n-1;
            int count=0;
            while(j>=0 && grid[i][j]==0){
                count++;
                j--;
            }
            lastZeros[i]=count;
        }
        int swaps=0;
        for(int i=0;i<n;i++){
            int reqZeros=n-i-1;
            
            int j=i;
            while(j<n && lastZeros[j]<reqZeros){
                j++;
                
            }
            if(j==n){
                return -1;
            }
            swaps+=j-i;
            while(j>i){
                swap(lastZeros[j],lastZeros[j-1]);
                j--;
            }
        }
        return swaps;
    }
};