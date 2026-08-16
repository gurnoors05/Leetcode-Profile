// Last updated: 8/16/2026, 6:50:57 PM
class Solution {
public:
    char kthCharacter(long long k, vector<int>& operations) {
        if(k==1){
            return 'a';
        }
        int currOperation=0;
        int n=operations.size();
        long length=1;
        long long newK;
        for(int i=0;i<operations.size();i++){
            length*=2;
            if(k<=length){
                currOperation=operations[i];
                newK=k-length/2;
                break;
            }
        }
        char ch=kthCharacter(newK,operations);
        if(currOperation==0){
            return ch;
        }
        if(ch=='z'){
            return 'a';
        }
        return (char)ch+1;
    }
};