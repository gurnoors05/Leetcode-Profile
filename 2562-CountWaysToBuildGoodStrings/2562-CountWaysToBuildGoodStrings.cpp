// Last updated: 8/16/2026, 6:54:09 PM
class Solution {
public:
    int L,H;
    int Z,O;
    const int M=1e9+7;
    int solve(int length,vector<int> &t){
        if(length>H){
            return 0;
        }
        if(t[length]!=-1){
            return t[length];
        }
        bool add_one=false;
        if(length>=L && length<=H){
            add_one=true;
        }
        int append_zero=solve(length+Z,t);
        int append_one=solve(length+O,t);
        return t[length] = (add_one + append_zero + append_one)%M;

    }
    int countGoodStrings(int low, int high, int zero, int one) {
        L=low;
        H=high;
        Z=zero;
        O=one;
        vector<int> t(high+1,-1);
        return solve(0,t); //return solve("") -- means pass empty string
    }
};