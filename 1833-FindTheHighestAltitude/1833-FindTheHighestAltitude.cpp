// Last updated: 8/16/2026, 6:58:22 PM
class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int maxi=0;
        int sum=0;
        for(int i=0;i<gain.size();i++){
            sum+=gain[i];
            maxi=max(maxi,sum);
        }
        return maxi;
    }
};