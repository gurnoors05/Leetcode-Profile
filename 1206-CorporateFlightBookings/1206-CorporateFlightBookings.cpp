// Last updated: 8/16/2026, 7:04:33 PM
class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> difference(n,0);
        for(auto& b:bookings){
            int l=b[0]-1;
            int r=b[1]-1;
            int val=b[2];
            difference[l]+=val;
           if(r+1<n){
            difference[r+1]-=val;
           }
        }
        for(int i=1;i<n;i++){
            difference[i]+=difference[i-1];
        }
        return difference;
    }
};