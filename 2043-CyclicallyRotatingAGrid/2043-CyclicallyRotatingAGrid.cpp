// Last updated: 8/16/2026, 6:57:09 PM
class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {

        int m = grid.size();
        int n = grid[0].size();

        int layers = min(m, n) / 2;

        for(int layer = 0; layer < layers; layer++) {

            vector<int> layerArr;

            int top = layer;
            int left = layer;
            int bottom = m - layer - 1;
            int right = n - layer - 1;

            // top
            for(int j = left; j <= right; j++) {
                layerArr.push_back(grid[top][j]);
            }

            // right
            for(int i = top + 1; i <= bottom - 1; i++) {
                layerArr.push_back(grid[i][right]);
            }

            // bottom
            for(int j = right; j >= left; j--) {
                layerArr.push_back(grid[bottom][j]);
            }

            // left
            for(int i = bottom - 1; i >= top + 1; i--) {
                layerArr.push_back(grid[i][left]);
            }

            int sz = layerArr.size();

            int idx = k % sz;

            // fill top
            for(int j = left; j <= right; j++) {
                grid[top][j] = layerArr[idx];
                idx = (idx + 1) % sz;
            }

            // fill right
            for(int i = top + 1; i <= bottom - 1; i++) {
                grid[i][right] = layerArr[idx];
                idx = (idx + 1) % sz;
            }

            // fill bottom
            for(int j = right; j >= left; j--) {
                grid[bottom][j] = layerArr[idx];
                idx = (idx + 1) % sz;
            }

            // fill left
            for(int i = bottom - 1; i >= top + 1; i--) {
                grid[i][left] = layerArr[idx];
                idx = (idx + 1) % sz;
            }
        }

        return grid;
    }
};