// Last updated: 8/16/2026, 7:01:09 PM
class Solution {
    public List<Boolean> kidsWithCandies(int[] candies, int e) {
        int max=0;
        for(int i=0;i<candies.length;i++){
            if(candies[i]>max){
                max=candies[i];
            }
        }
        ArrayList<Boolean> l=new ArrayList<>();
        for(int i=0;i<candies.length;i++){
            if(candies[i]+e>=max){
                l.add(true);
            }
            else{
                l.add(false);
            }
        }
        return l;
    }
};