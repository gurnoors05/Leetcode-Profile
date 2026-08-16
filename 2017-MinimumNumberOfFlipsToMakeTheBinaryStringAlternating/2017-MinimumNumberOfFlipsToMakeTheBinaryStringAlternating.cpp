// Last updated: 8/16/2026, 6:57:20 PM
class Solution {
public:
    int minFlips(string s) {
        int n=s.length();
        s+=s;
        string s1;
        string s2;
        for(int i=0;i<2*n;i++){
            if(i%2==0){
                s1+="1";
                s2+="0";
            }
            else{
                s1+="0";
                s2+="1";
            }
        }
        int i=0;
        int j=0;
        int ans1=0;
        int ans2=0;
        int result=INT_MAX;
        while(j<2*n){
            if(s[j]!=s1[j]){
                ans1++;
            }
            if(s[j]!=s2[j]){
                ans2++;
            }
            if(j-i+1>n){
                if(s[i]!=s1[i]){
                    ans1--;
                }
                if(s[i]!=s2[i]){
                    ans2--;
                }
                i++;
            }
            if(j-i+1==n){
                result=min({result,ans1,ans2});
            }
            j++;
        }
        return result;
    }
};