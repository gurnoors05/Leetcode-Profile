// Last updated: 8/16/2026, 7:06:45 PM
class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int count = 0;
        int n = strs.size();
        int m = strs[0].size();
        for (int col = 0; col < m; col++) {
            for (int row = 0; row < n - 1; row++) {
                if (strs[row][col] > strs[row + 1][col]) {
                    count++;
                    break;
                }
            }
        }

        return count;
        
    }
};