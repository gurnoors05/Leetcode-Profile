// Last updated: 8/16/2026, 6:53:54 PM
class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        vector<bool> prime(right+1,true);
        prime[1]=false;
        for(long long i=2;i*i<=right;i++){
            if(prime[i]){
                for(long long j=(long long)i*i;j<=right;j=j+i){
                    prime[j]=false;
                }
            }
        }
        int previous=-1;
        int mini=INT_MAX;
        int a=-1;
        int b=-1;
        for(int i=left;i<=right;i++){
            if(prime[i]){
                if(previous==-1){
                    previous=i;
                }
                else{
                   if((i-previous)<mini){
                    mini=i-previous;
                    a=previous;
                    b=i;
                   }
                    previous=i;
                }
            }
            
        }
        return {a,b};
    }
};