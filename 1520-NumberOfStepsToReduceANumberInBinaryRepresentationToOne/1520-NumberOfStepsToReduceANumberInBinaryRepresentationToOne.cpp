// Last updated: 8/16/2026, 7:01:17 PM
class Solution {
public:
    int numSteps(string s) {
        int op=0;
        while(s.length()!=1){
            int n=s.length();
            if(s[n-1]=='0'){// even
                op+=1;
                s.pop_back();
            }
            else{
                solveOdd(s);
                op++;
            }
        }
        return op;
    }
    void solveOdd(string &s){
        int i=s.length()-1;
        while(i>=0 && s[i]!='0'){
            s[i]='0';
            i--;
        }
        if(i<0){
            s='1'+s;
        }
        else{
            s[i]='1';
        }

    }
};