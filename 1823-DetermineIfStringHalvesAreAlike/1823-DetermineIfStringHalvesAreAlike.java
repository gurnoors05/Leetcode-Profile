// Last updated: 8/16/2026, 6:58:29 PM
class Solution {
    public boolean halvesAreAlike(String s) {
        String s1=s.toLowerCase();
        StringBuilder s2=new StringBuilder();
        char arr[]=s1.toCharArray();
        int count1=0;
        for(int i=0;i<s1.length()/2;i++){
            if(arr[i]=='a' || arr[i]=='e' || arr[i]=='i' || arr[i]=='o' || arr[i]=='u'){
                count1++;
            }
        }
        int count2=0;
        for(int i=s1.length()/2;i<s1.length();i++){
            if(arr[i]=='a' || arr[i]=='e' || arr[i]=='i' || arr[i]=='o' || arr[i]=='u'){
                count2++;
            }
        }
        return count1==count2;
    }
}