// Last updated: 8/16/2026, 6:57:27 PM
class Solution {
public:
    vector<int> getBiggestThree(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> d1(m,vector<int>(n));
        vector<vector<int>> d2(m,vector<int>(n));

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                d1[i][j] = grid[i][j];
                if(i>0 && j>0)
                    d1[i][j] += d1[i-1][j-1];
            }
        }

        for(int i=0;i<m;i++){
            for(int j=n-1;j>=0;j--){
                d2[i][j] = grid[i][j];
                if(i>0 && j+1<n)
                    d2[i][j] += d2[i-1][j+1];
            }
        }

        set<int> st;

        auto addToSet = [&](int val){
            st.insert(val);
            if(st.size()>3)
                st.erase(st.begin());
        };

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){

                addToSet(grid[i][j]);

                for(int side=1;i-side>=0 && i+side<m && j-side>=0 && j+side<n;side++){

                    int sum=0;

                    int top_r=i-side, top_c=j;
                    int right_r=i, right_c=j+side;
                    int bottom_r=i+side, bottom_c=j;
                    int left_r=i, left_c=j-side;

                    sum += d1[right_r][right_c];
                    if(top_r-1>=0 && top_c-1>=0)
                        sum -= d1[top_r-1][top_c-1];

                    sum += d2[bottom_r][bottom_c];
                    if(right_r-1>=0 && right_c+1<n)
                        sum -= d2[right_r-1][right_c+1];

                    sum += d1[bottom_r][bottom_c];
                    if(left_r-1>=0 && left_c-1>=0)
                        sum -= d1[left_r-1][left_c-1];

                    sum += d2[left_r][left_c];
                    if(top_r-1>=0 && top_c+1<n)
                        sum -= d2[top_r-1][top_c+1];

                    sum -= grid[top_r][top_c];
                    sum -= grid[right_r][right_c];
                    sum -= grid[bottom_r][bottom_c];
                    sum -= grid[left_r][left_c];

                    addToSet(sum);
                }
            }
        }

        return vector<int>(st.rbegin(), st.rend());
    }
};