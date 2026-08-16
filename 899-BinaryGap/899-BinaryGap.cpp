// Last updated: 8/16/2026, 7:07:37 PM
class Solution {
public:
    int binaryGap(int n) {
        int position=0;
        int lastPosition=-1;
        int ans=0;
        while(n>0){
            if(n&1==1){
                if(lastPosition!=-1){
                    ans=max(ans,position-lastPosition);
                }
                lastPosition=position;
            }
            position++;
            n>>=1;
        }
        return ans;

    }
};