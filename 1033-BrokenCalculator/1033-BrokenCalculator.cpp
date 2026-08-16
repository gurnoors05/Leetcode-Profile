// Last updated: 8/16/2026, 7:06:10 PM
class Solution {
public:
    int brokenCalc(int startValue, int target) {
        if(startValue>=target){
            return startValue-target;
        }
        if(target%2==0){
            return 1+brokenCalc(startValue,target/2);
        }
        return 1+brokenCalc(startValue,target+1);
    }
};