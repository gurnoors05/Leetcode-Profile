// Last updated: 8/16/2026, 6:53:58 PM
class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int n=words.size();
        int result=INT_MAX;
        for(int i=0;i<n;i++){
            if(words[i]==target){
                int fromStart=abs(i-startIndex);
                int fromEnd=n-fromStart;
                result=min({result,fromStart,fromEnd});
            }
        }
        return result == INT_MAX ? -1 : result;
    }
};