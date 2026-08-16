// Last updated: 8/16/2026, 7:04:14 PM
class Solution {
public:
    string breakPalindrome(string palindrome) {
        int n=palindrome.length();
        if(n==1){
            return "";
        }
        for(int i=0;i<n/2;i++){
            if(palindrome[i]!='a'){
                palindrome[i]='a';
                return palindrome;
            }
        }
        palindrome[n-1]='b';
        return palindrome;
    }
};