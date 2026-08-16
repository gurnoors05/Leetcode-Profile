// Last updated: 8/16/2026, 6:55:18 PM
class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        int n=capacity.size();
        vector<int> vec(n);
        for(int i=0;i<n;i++){
            vec[i]=capacity[i]-rocks[i];
        }
        sort(begin(vec),end(vec));
        int count=0;
        for(int i=0;i<n;i++){
            if(vec[i]<=additionalRocks){
                additionalRocks-=vec[i];
                count++;
            }
            else{
                break;
            }
        }
        return count;
    }
};