// Last updated: 8/16/2026, 7:07:20 PM
class Solution {
public:
    string decodeAtIndex(string s, int k) {
        int n=s.length();
        long long size=0;
        for(char& ch:s){
            if(isdigit(ch)){
                size=size*(ch-'0');
            }
            else{
                size+=1;
            }
        }
        for(int i=n-1;i>=0;i--){
            k=k%size;
            if(k==0 && isalpha(s[i])){
                return string(1,s[i]);
            }
            if(isalpha(s[i])){
                size-=1;
            }
            else{
                size=size/(s[i]-'0');
            }
        }
        return "";
    }
};