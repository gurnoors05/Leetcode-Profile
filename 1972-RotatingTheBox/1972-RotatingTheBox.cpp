// Last updated: 8/16/2026, 6:57:37 PM
class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
        int m=boxGrid.size();
        int n=boxGrid[0].size();
        vector<vector<char>> result(n,vector<char>(m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                result[i][j]=boxGrid[j][i];
            }
        }
         for(vector<char>& row : result) {
            reverse(begin(row), end(row));
        }
        for(int j=0;j<m;j++){
            int spaceRow=n-1;
            for(int i=n-1;i>=0;i--){
                if(result[i][j]=='*'){
                    spaceRow=i-1;
                    continue;
                }
                else if(result[i][j]=='#'){
                    result[i][j]='.';
                    result[spaceRow][j]='#';
                    spaceRow--;
                }
            }
        }
        return result;
        
    }
};