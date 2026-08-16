// Last updated: 8/16/2026, 6:59:28 PM
class Solution {
public:
    int maxDepth(string s) {
        int count=0;
        int maxCount=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='('){
                count++;
                maxCount=max(maxCount,count);
            }
            else if(s[i]==')'){
                count--;
            }
        }
        return maxCount;
    }
};