// Last updated: 8/16/2026, 6:49:47 PM
class Solution {
public:
    int totalWaviness(int num1, int num2) {
        int waviness=0;
        for(int i=num1;i<=num2;i++){
            waviness+=solve(i);
        }
        return waviness;
    }
    int solve(int num){
        string s=to_string(num);
        int len=s.length();
        if(len<3){
            return 0;
        }
        int ans=0;
        for(int i=1;i<=len-2;i++){
            if(s[i]>s[i+1] && s[i]>s[i-1]){
                ans++;
            }
            if(s[i]<s[i+1] && s[i]<s[i-1]){ //valley
                ans++;
            }
        }
        return ans;
    }
};