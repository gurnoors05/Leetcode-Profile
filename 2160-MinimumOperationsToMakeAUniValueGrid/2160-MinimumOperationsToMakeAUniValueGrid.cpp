// Last updated: 8/16/2026, 6:56:30 PM
class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int n=grid.size();
        int m=grid[0].size();
        vector<int> vec;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                vec.push_back(grid[i][j]);
            }
        }
        int s=vec.size();
        sort(vec.begin(),vec.end());
        int target=vec[s/2];
        int ans=0;
        for(int num:vec){
            if((num%x)!=(target%x)){
                return -1;
            }
            ans+=abs(target-num)/x;
        }
        return ans;
    }
};