// Last updated: 8/16/2026, 6:55:59 PM
class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int prevCount=0;
        int result=0;
        for(int i=0;i<bank.size();i++){
            int currCount=0;
            for(char &ch: bank[i]){
                if(ch=='1'){
                    currCount++;
                }
            }
            result+=prevCount*currCount;
            prevCount=currCount==0?prevCount:currCount;

        }
        return result;
    }
};