// Last updated: 8/16/2026, 7:00:14 PM
class Solution {
    public String restoreString(String s, int[] indices) {
        // char arr[]=new char[s.length()];
        // for(int i=0;i<s.length();i++){
        //     arr[indices[i]]=s.charAt(i);
        // }
        // String ans=new String(arr);
        // return ans;

        StringBuilder l=new StringBuilder(s);
        for(int i=0;i<indices.length;i++){
            int index=indices[i];
            l.setCharAt(index,s.charAt(i));
        }
        return l.toString();

    }
}