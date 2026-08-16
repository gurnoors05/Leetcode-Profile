// Last updated: 8/16/2026, 6:52:30 PM
class Solution {
public:
    int countCompleteSubstrings(string word, int k) {
        int n=word.length();
        int lastIndex=0;
        int result=0;
        for(int i=1;i<=n;i++){
            if(i==n || abs(word[i]-word[i-1])>2){
                result+=solve(lastIndex,i-1,word,k);
                lastIndex=i;
            }
        }
        return result;
    }
    int solve(int start,int end,string &word,int k){
        int result=0;
        for(int noOfUniqueChar=1;noOfUniqueChar<=26 && noOfUniqueChar*k<=end-start+1 ; noOfUniqueChar++){
            vector<int> freq(26);
            int goodChar=0;
            int windowSize=noOfUniqueChar*k;
            int l=start;
            for(int r=start;r<=end;r++){
                freq[word[r]-'a']++;
                if(freq[word[r]-'a']==k){
                    goodChar++;
                }
                else if(freq[word[r]-'a']==k+1){
                    goodChar--;
                }
                if(r-l+1>windowSize){
                    if(freq[word[l]-'a']==k){
                        goodChar--;
                    }
                    else if(freq[word[l]-'a']==k+1){
                        goodChar++;
                    }
                    freq[word[l]-'a']--;
                    l++;
                }
                if(goodChar==noOfUniqueChar){
                    result++;
                }
            }
        }
        return result;
    }
};