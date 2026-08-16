// Last updated: 8/16/2026, 7:07:27 PM
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l=1;
        int r=*max_element(piles.begin(),piles.end());
      
        int ans=r;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(canEatAll(piles,mid,h)){
                r=mid-1;
                ans=mid;
            }
            else{
                l=mid+1;

            }
        }
        return ans;
    }
    bool canEatAll(vector<int>& piles,int mid,int h){
       long long hours=0;
       for(int i=0;i<piles.size();i++){
           hours += (piles[i] + mid - 1) / mid;
       }
       return hours<=h;
    }
};