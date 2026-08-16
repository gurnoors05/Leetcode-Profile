// Last updated: 8/16/2026, 6:54:04 PM
class Solution {
public:
    int bestClosingTime(string customers) {
        int n=customers.size();
        vector<int> prefix(customers.size()+1);
        vector<int> suffix(customers.size()+1);
        prefix[0]=0;
        prefix[n]=0;
        for(int i=0;i<customers.size();i++){
            if(customers[i]=='N'){
                prefix[i+1]=prefix[i]+1;
            }
            else{
                prefix[i+1]=prefix[i];
            }
        }
        for(int i=n-1;i>=0;i--){
            if(customers[i]=='Y'){
                suffix[i]=suffix[i+1]+1;
            }
            else{
                suffix[i]=suffix[i+1];
            }
        }
        int mini=INT_MAX;
        int ans=-1;
        for(int i=0;i<=n;i++){
            int penalty=prefix[i]+suffix[i];
            if(mini>penalty){
                mini=penalty;
                ans=i;
            }
        }
        return ans;
    }
};