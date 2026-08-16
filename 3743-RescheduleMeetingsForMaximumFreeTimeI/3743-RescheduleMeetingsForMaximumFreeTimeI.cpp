// Last updated: 8/16/2026, 6:50:41 PM
class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        vector<int> freeArray;
        int n=startTime.size();
        freeArray.push_back(startTime[0]);
        for(int i=1;i<n;i++){
            freeArray.push_back(startTime[i]-endTime[i-1]);
        }
        freeArray.push_back(eventTime - endTime[n-1]);
        int l=0;
        int r=0;
        int sum=0;
        int window_size=k+1;
        int maxSum=INT_MIN;
        while(r<freeArray.size()){
            sum+=freeArray[r];
            if(l<freeArray.size() && (r-l+1)>window_size){
                sum-=freeArray[l];
                l++;
            }
            maxSum=max(maxSum,sum);
            r++;
        }
        return maxSum;
    }
};