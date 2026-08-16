// Last updated: 8/16/2026, 6:51:24 PM
class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int l=0;
        int r=0;
        int n=colors.size();
        vector<int> merged(2*n);
        for(int i=0;i<n;i++){
            merged[i]=colors[i];
        }
        for(int i=0;i<n;i++){
            merged[i+n]=colors[i];
        }
        int ans=0;
        while(r<2*n){
             if (r > 0 && merged[r] == merged[r - 1]) {
                l = r; 
            }
            if((r-l+1)==k){
                if(l<n){
                    ans++;
                }
        
                l++;
            }
            r++;
        }
        return ans;
    }
};