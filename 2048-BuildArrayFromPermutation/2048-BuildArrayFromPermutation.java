// Last updated: 8/16/2026, 6:57:07 PM
class Solution {
    public int[] buildArray(int[] nums) {
        int arr[]=new int[nums.length];
        for(int i=0;i<nums.length;i++){
            arr[i]=nums[nums[i]];
           
        }
        return arr;
        

    }
}