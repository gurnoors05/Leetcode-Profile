// Last updated: 8/16/2026, 6:59:05 PM
class Solution {
public:
    bool closeStrings(string word1, string word2) {
        int n=word1.length();
        int m=word2.length();
        if(n!=m){
            return false;
        }
        vector<int> freq1(26,0);
        vector<int> freq2(26,0);
        for(int i=0;i<word1.length();i++){
            int char1=word1[i]-'a';
            int char2=word2[i]-'a';
            freq1[char1]++;
            freq2[char2]++;
        }
        for(int i=0;i<26;i++){
            if(freq1[i] != 0 && freq2[i] != 0){
                continue;
            } 
            
            if(freq1[i] == 0 && freq2[i] == 0){
                continue;
            } 
            
            return false;
        }
        sort(begin(freq1), end(freq1));
        sort(begin(freq2), end(freq2));
        
        return freq1 == freq2;
        
    }
};