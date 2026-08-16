// Last updated: 8/16/2026, 7:03:07 PM
class Solution {
public:
    int max_score=INT_MIN;
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        vector<int> freq(26,0);
        for(int i=0;i<letters.size();i++){
            freq[letters[i]-'a']++;
        }
        solve(words,freq,score,0,0);
        return max_score;
    }
    void solve(vector<string>& words,vector<int> &freq,vector<int>& score,int currScore,int i){
        max_score=max(max_score,currScore);
        if(i>=words.size()){
            return;
        }
        int scoreNow=0;
        int j;
        bool canTake = true;
        for(j=0;j<words[i].length();j++){
            if (freq[words[i][j] - 'a'] == 0) {
                canTake = false;
                break;
            }
            scoreNow+=score[words[i][j]-'a'];
            freq[words[i][j]-'a']--;
        }
        
        if(canTake){
            solve(words,freq,score,currScore+scoreNow,i+1);
        }
        for (int k = 0; k < j; k++) {
            freq[words[i][k] - 'a']++;
        }
        solve(words,freq,score,currScore,i+1);
    }
};