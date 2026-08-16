// Last updated: 8/16/2026, 7:04:25 PM
class Solution {
public:
    int tribonacci(int n) {
        if(n==0){
            return 0;
        }
        if(n==1 || n==2){
            return 1;
        }
        int prev_3=0;
        int prev_2=1;
        int prev_1=1;
        for(int i=3;i<=n;i++){
            int curr=prev_3+prev_2+prev_1;
            prev_3=prev_2;
            prev_2=prev_1;
            prev_1=curr;
        }
        return prev_1;
    }
};