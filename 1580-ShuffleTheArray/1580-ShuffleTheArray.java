// Last updated: 8/16/2026, 7:00:37 PM
class Solution {
    public int[] shuffle(int[] nums, int n) {
        int arr[]=new int[2*n];
        int mid=(2*n)/2;
        int s=0;
        int in=0;
        for(int i=0;i<n;i++){
           arr[in++]=nums[s++];
           arr[in++]=nums[mid++];
        }
        return arr;

        
        
    }
}