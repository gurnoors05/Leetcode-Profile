// Last updated: 8/16/2026, 6:55:49 PM
class Solution {
public:
    const int M=1e9+7;
    int numberOfWays(string corridor) {
        vector<int> sCount;
        for(int i=0;i<corridor.length();i++){
            if(corridor[i]=='S'){
                sCount.push_back(i);
            }
        }
        if (sCount.size() == 0 || sCount.size() % 2 != 0){
            return 0;
        }
        int prev_element=sCount[1];
        long long result=1;
        for(int i=2;i<sCount.size();i+=2){
            int spaces=sCount[i]-prev_element;
            result=(result*spaces)%M;
            prev_element=sCount[i+1];
        }
        return result;
    }
};