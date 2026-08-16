// Last updated: 8/16/2026, 6:57:00 PM
class Solution {
    public int[] getConcatenation(int[] nums) {
        int arr[]=new int[2*nums.length];
        for(int i=0;i<nums.length;i++){
            arr[i]=nums[i];
        }
        for(int i=0;i<nums.length;i++){
            arr[i+(nums.length)]=nums[i];
        }
        return arr;
    }
}