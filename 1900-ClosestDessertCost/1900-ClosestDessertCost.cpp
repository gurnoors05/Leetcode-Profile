// Last updated: 8/16/2026, 6:58:02 PM
class Solution {
public:
    int t;
    int closestCost(vector<int>& baseCosts, vector<int>& toppingCosts, int target) {
        int ans=INT_MAX;
        t=target;
        for(int i=0;i<baseCosts.size();i++){
            int temp=solve(toppingCosts,baseCosts[i],target,0);
            ans=closest(temp,ans);
        }
        return ans;
    }
    int solve(vector<int>& toppingCosts,int currSum,int target,int idx){
        if(idx>=toppingCosts.size()){
            return currSum;
        }
        int a=solve(toppingCosts,currSum+toppingCosts[idx],target,idx+1);
        int b=solve(toppingCosts,currSum+(toppingCosts[idx]*2),target,idx+1);
        int c=solve(toppingCosts,currSum,target,idx+1);
        currSum=closest(a,closest(b,c));
        return currSum;
    }
    int closest(int a,int b){
        if(a==0){
            return b;
        }
        if(b==0){
            return a;
        }
        if(abs(t-a)==abs(t-b)){
            return a<b?a:b;
        }
        return abs(t-a)<abs(t-b)?a:b;
    }
};