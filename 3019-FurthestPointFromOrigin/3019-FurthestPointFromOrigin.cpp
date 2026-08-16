// Last updated: 8/16/2026, 6:52:56 PM
class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int n=moves.length();
        int l=0;
        int r=0;
        int empty=0;
        for(int i=0;i<n;i++){
            if(moves[i]=='L'){
                l++;
            }
            else if(moves[i]=='R'){
                r++;
            }
            else{
                empty++;
            }
        }
        int ans;
        if(l>=r){
            l+=empty;
            ans=l-r;
        }
        else{
            r+=empty;
            ans=r-l;
        }
        return ans;
    }
};