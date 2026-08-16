// Last updated: 8/16/2026, 7:10:36 PM
class Solution {
public:

    // It is similar to ques no. 209, but in this ques we have negative numbers also. If we apply previous ques method , then it gives wrong ans. Check for eg [84, -37, 37, 40, 95]
    int shortestSubarray(vector<int>& nums, int k) {
        int r=0;
        deque<int> dq;
        int n=nums.size();
        vector<long long> cumulativeSum(n,0);
        int result=INT_MAX;
        while(r<n){
            if(r==0){
                cumulativeSum[r]=nums[r];
            }
            else{
                cumulativeSum[r]=nums[r]+cumulativeSum[r-1];
            }
            if(cumulativeSum[r]>=k){
                result=min(result,r+1);
            }
            while(!dq.empty() && cumulativeSum[r]-cumulativeSum[dq.front()]>=k){
                result=min(result,r-dq.front());
                dq.pop_front();
            }
            while(!dq.empty() && cumulativeSum[r]<=cumulativeSum[dq.back()]){
                dq.pop_back();
            }
            dq.push_back(r);
            r++;
        }
        return result==INT_MAX?-1:result;
    }
};