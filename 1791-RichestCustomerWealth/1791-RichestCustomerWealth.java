// Last updated: 8/16/2026, 6:58:52 PM
class Solution {
    public int maximumWealth(int[][] accounts) {
        int max=0;
        for(int i=0;i<accounts.length;i++){
            int sum=0;
            
            for(int j=0;j<accounts[i].length;j++){
                sum+=accounts[i][j];
            }
            if(sum>max){
                max=sum;
            }
            
        }
        return max;
    }
}