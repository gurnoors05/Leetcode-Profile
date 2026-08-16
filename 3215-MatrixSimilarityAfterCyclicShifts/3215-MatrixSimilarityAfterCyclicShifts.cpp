// Last updated: 8/16/2026, 6:52:33 PM
class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int n=mat.size();
        int m=mat[0].size();
        k=k%m;
        if(k == 0) { //no shifting
            return true;
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int currIdx=j;
                int futureIdx;
                if(i%2==0){
                    futureIdx=(j+k)%m;
                }
                else{
                    futureIdx=(j-k+m)%m;
                }
                if(mat[i][currIdx]!=mat[i][futureIdx]){
                    return false;
                }
            }
        }
        return true;
    }
};