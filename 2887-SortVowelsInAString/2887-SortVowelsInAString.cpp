// Last updated: 8/16/2026, 6:53:07 PM
class Solution {
public:
    string sortVowels(string s) {
        string temp="";
        for(int i=0;i<s.length();i++){
            if(isVowel(s[i])){
                temp.push_back(s[i]);
            }
        }
        sort(begin(temp),end(temp));
        int j=0;
        for(int i=0;i<s.length();i++){
            if(isVowel(s[i])){
                s[i]=temp[j];
                j++;
            }

        }
        return s;
    }
    bool isVowel(char ch) {
        ch = tolower(ch);
        return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
    }
};