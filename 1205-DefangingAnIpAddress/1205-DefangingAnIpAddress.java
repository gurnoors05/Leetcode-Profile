// Last updated: 8/16/2026, 7:04:36 PM
class Solution {
    public String defangIPaddr(String address) {
        // return address.replace(".","[.]");

        StringBuilder s=new StringBuilder();
        // for(int i=0;i<address.length();i++){
        //     char ch=address.charAt(i);
        //     if(ch=='.'){
        //         s.append("[.]");
        //     }
        //     else{
        //         s.append(ch);
        //     }
        // }
        for(char ch:address.toCharArray()){
             if(ch=='.'){
                s.append("[.]");
            }
            else{
                s.append(ch);
            }
        }
        return s.toString();

    }
}