// Last updated: 8/16/2026, 7:05:47 PM
class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int left=0;
        int right=0;
        for(int i=0;i<weights.size();i++){
            right+=weights[i];
            left=max(left,weights[i]);
        }
        while(left<right){
            int mid=left+(right-left)/2;
            if(maxCapacity(weights,mid,days)){
                right=mid;
            }
            else{
                left=mid+1;
            }

        }
        return left;
    }
    bool maxCapacity(vector<int>& weights,int cap,int days){
        int reqDays=1;
        int currWeight=0;;
        for(int i=0;i<weights.size();i++){
            if(currWeight+weights[i]>cap){
                reqDays++;
                currWeight=weights[i];
            }
            else{
                currWeight+=weights[i];
            }
        }
        return reqDays<=days;
    }
};