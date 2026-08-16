// Last updated: 8/16/2026, 6:56:52 PM
class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
        // We can solve by using simple LIS but it will give TLE
        // So now instead of storing length of LIS till particular index
        // We will store LIS[i]=x; where i+1 is length of LIS subsequence for that index and x is largest element in that LIS
        int n=obstacles.size();
        vector<int> LIS;
        vector<int> result(n,1);
        for(int i=0;i<obstacles.size();i++){
            int idx=upper_bound(begin(LIS),end(LIS),obstacles[i])-begin(LIS);
            if(idx==LIS.size()){
                LIS.push_back(obstacles[i]);
            }
            else{
                LIS[idx]=obstacles[i];
            }
            result[i]=idx+1;
        }
        return result;
    }
};