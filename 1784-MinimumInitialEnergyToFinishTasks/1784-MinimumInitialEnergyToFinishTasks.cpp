// Last updated: 8/16/2026, 6:59:00 PM
class Solution {
public:
    int minimumEffort(vector<vector<int>>& tasks) {
        int l=0;
        int r=1e9;
        sort(begin(tasks),end(tasks),[](auto& t1,auto& t2){
            int diff1=t1[1]-t1[0];
            int diff2=t2[1]-t2[0];
            return diff1>diff2;
        });
        int result=-1;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(solve(tasks,mid)){
                result=mid;
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return result;
    }
    bool solve(vector<vector<int>>& tasks,int mid){
        for(auto &task : tasks) {
            int actual  = task[0];
            int minimum = task[1];

            if(minimum > mid) {
                return false;
            }

            mid -= actual;
        }

        return true;
    }
};