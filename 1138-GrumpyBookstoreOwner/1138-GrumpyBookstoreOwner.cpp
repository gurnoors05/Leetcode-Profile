// Last updated: 8/16/2026, 7:05:06 PM
class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int l=0;
        int r=0;
        int n=customers.size();
        int noOfUnsatisfied=0;
        int maxi=0;
        int lastIndex=0;
        while(r<n){
            if(grumpy[r]==1){
                noOfUnsatisfied+=customers[r];
            }
            
            if((r-l+1)>minutes){
                if(grumpy[l]==1){
                    noOfUnsatisfied-=customers[l];
                }
                l++;
            }
            if((r-l+1)==minutes){

                if(noOfUnsatisfied>maxi){
                    maxi=noOfUnsatisfied;
                    lastIndex=l;
                }
            }
            r++;

        }
         for (int i = lastIndex; i < lastIndex + minutes && i < n; i++) {
            grumpy[i] = 0;
        }

        // Step 3: Calculate final satisfied customers
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (grumpy[i] == 0) {
                ans += customers[i];
            }
        }

       
        return ans;
    }
};