// Last updated: 8/16/2026, 7:01:05 PM
class Solution {
public:
    int maxScore(string s) {
        //brute force approach --- O(n^2)
        // int n=s.length();
        // int result=INT_MIN;
        // for(int i=0;i<=n-2;i++){
        //     int zerocount=0;
        //     for(int j=0;j<=i;j++){
        //         if(s[j]=='0'){
        //             zerocount++;
        //         }
        //     }
        //     int onecount=0;
        //     for(int j=i+1;j<n;j++){
        //         if(s[j]=='1'){
        //             onecount++;
        //         }
        //     }
        //     result= max(result,zerocount+onecount);   
        // }
        // return result;


        //Better approach
        int n=s.length();
        int result=INT_MIN;
        int zeros=0;
        int ones=0;
        int totalones=count(begin(s),end(s),'1');
        for(int i=0;i<=n-2;i++){
            if(s[i]=='1'){
                ones++;
            }
            else{
                zeros++;
            }
            int rightones=totalones-ones;
            result=max(result,zeros+rightones);
        }
        return result;
    }
};