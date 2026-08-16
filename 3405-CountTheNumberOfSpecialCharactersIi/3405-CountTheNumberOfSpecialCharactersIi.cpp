// Last updated: 8/16/2026, 6:51:45 PM
class Solution {
public:
    int numberOfSpecialChars(string word) {
        int n=word.length();
        vector<int> lastLowerOcc(26,-1);
        vector<int> firstUpperOcc(26,INT_MAX);
        for(int i=0;i<n;i++){
            if(word[i]>='a' && word[i]<='z'){
                lastLowerOcc[word[i]-'a']=i;
                
            }
            else{
                firstUpperOcc[word[i] - 'A'] = min(firstUpperOcc[word[i] - 'A'], i);
            }
        }
        int count=0;
        for(int i = 0; i < 26; i++) {
            if(lastLowerOcc[i] != -1 && firstUpperOcc[i] != INT_MAX && lastLowerOcc[i] < firstUpperOcc[i]) {
                count++;
            }
        }
        return count;
    }
};