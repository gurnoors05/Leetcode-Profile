// Last updated: 8/16/2026, 7:01:02 PM
class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        return solve(cardPoints,k);
    }
    int solve(vector<int> &cards,int k){
        int n=cards.size();
        int l=0;
        int r=n-1;
        int lSum=0;
        int rSum=0;
        int maxSum=0;
        for(int i=0;i<k;i++){
            lSum+=cards[i];
        }
        maxSum=lSum;
        for(int j=k-1;j>=0;j--){
            lSum-=cards[j];
            rSum+=cards[r];
            r--;
            maxSum=max(maxSum,lSum+rSum);
        }
        return maxSum;
    }
};