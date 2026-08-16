// Last updated: 8/16/2026, 7:00:30 PM
class Solution {
    public int[] runningSum(int[] nums) {
        int arr[]=new int[nums.length];
        // for(int i=0;i<nums.length;i++){
        //     int sum=0;
        //     for(int j=0;j<=i;j++){
        //         sum+=nums[j];
        //     }
        //     arr[i]=sum;
        // }
        // return arr;
        int sum=0;
        for(int i=0;i<nums.length;i++){
            sum+=nums[i];
            arr[i]=sum;
        }
        return arr;
    }
}