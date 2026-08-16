// Last updated: 8/16/2026, 7:03:29 PM
class Solution {
public:
    
    int minCostToMoveChips(vector<int>& position) {
        vector<int> index(2, 0); // Only need even and odd counts
        return solve(position, index);
    }

    int solve(vector<int> &position, vector<int>& index) {
        for (int i = 0; i < position.size(); i++) { // Fix indexing
            index[position[i] % 2]++; // Count even and odd positions
        }

        return min(index[0], index[1]); // Minimum cost to move chips
    }

};