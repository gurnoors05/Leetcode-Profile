// Last updated: 8/16/2026, 6:55:52 PM
class Solution {
public:
    int minimumCost(vector<int>& cost) {
        int n=cost.size();
        sort(cost.begin(),cost.end());
        int total=0;
        for(int i=n-1;i>=0;i-=3){ // i-=3
            total+=cost[i];
            if(i-1>=0){
                total+=cost[i-1];
            }
        }
        return total;
    }
};