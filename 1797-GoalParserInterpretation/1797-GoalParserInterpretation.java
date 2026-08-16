// Last updated: 8/16/2026, 6:58:46 PM
class Solution {
    public String interpret(String command) {
        StringBuilder s1=new StringBuilder();
        char array[]=command.toCharArray();
       for(int i=0;i<array.length;i++){
        if(array[i]=='('){
            if(array[i+1]==')'){
                s1.append('o');
                
            }
            
        }
        else if(array[i]==')'){
            continue;
        }
        else{
            s1.append(array[i]);
        }
        
       }
        return s1.toString();
    }
}