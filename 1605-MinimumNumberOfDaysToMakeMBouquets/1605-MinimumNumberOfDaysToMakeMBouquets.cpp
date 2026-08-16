// Last updated: 8/16/2026, 7:00:28 PM
class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        if((long long)m * k > bloomDay.size()){
            return -1;
        }
        int left=1;
        int right=*max_element(bloomDay.begin(),bloomDay.end());
        int ans=-1;
        while(left<=right){
            int mid=left+(right-left)/2;
            if(canMakeAll(mid,bloomDay,m,k)){
                right=mid-1;
                ans=mid;
            }
            else{
                left=mid+1;
            }
        }
        return ans;
    }
    bool canMakeAll(int mid,vector<int>& bloomDay,int m,int k){
        int bouquets = 0;
        int flowers = 0;

        for(int i=0;i<bloomDay.size();i++){

            if(bloomDay[i] <= mid){
                flowers++;

                if(flowers == k){
                    bouquets++;
                    flowers = 0;
                }
            }
            else{
                flowers = 0;
            }
        }

        return bouquets >= m;
    }
};