// Last updated: 8/16/2026, 6:51:30 PM
class Solution {
public:
    string compressedString(string word) {
        int i=0;
        int n=word.length();
        string comp="";
        while(i<n){
            int count=0;
            char ch=word[i];
            while(i<n && count<9 && word[i]==ch){
                i++;
                count++;
            }
            comp+=to_string(count)+ch;
        }
        return comp;
    }
};