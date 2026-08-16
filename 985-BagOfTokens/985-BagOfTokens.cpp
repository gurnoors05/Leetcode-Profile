// Last updated: 8/16/2026, 7:06:39 PM
class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int maxScore=0;
        sort(begin(tokens),end(tokens));
        int i=0;
        int j=tokens.size()-1;
        int currScore=0;
        while(i<=j){
            if(power>=tokens[i]){
                currScore++;
                maxScore=max(maxScore,currScore);
                power-=tokens[i];
                i++;
            }
            else if(currScore>=1){
                
                    power+=tokens[j];
                    currScore-=1;
                    j--;
                
            }
            else{
                return maxScore;
            }
        }
        return maxScore;
    }
};