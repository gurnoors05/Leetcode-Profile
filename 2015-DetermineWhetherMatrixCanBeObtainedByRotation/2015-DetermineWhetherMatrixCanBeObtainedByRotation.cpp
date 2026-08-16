// Last updated: 8/16/2026, 6:57:23 PM
class Solution {
public:
    // First Transpose then rotate matrix
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        for(int i=0;i<4;i++){
            if(mat==target){
                return  true;
            }
            rotate(mat);
        }
        return false;
    }
    void rotate(vector<vector<int>>& mat){
        for(int i=0;i<mat.size();i++){
            for(int j=i;j<mat[0].size();j++){
                swap(mat[i][j],mat[j][i]);
            }
        }
        for(int i=0;i<mat.size();i++){
            reverse(mat[i].begin(),mat[i].end());
        }
    }
};