// Last updated: 8/16/2026, 6:58:06 PM
class Solution {
public:
    int minOperations(string s) {
        // int count=0;
        // int n=s.length();
        // for(int i=0;i<n;i++){
        //     if(((s[i]-'0') ^ (i&1))==1){
        //         count++;
        //     }
        // }
        // return min(count,n-count);
        int count1 = 0; // pattern 0101
        int count2 = 0; // pattern 1010

        for(int i = 0; i < s.size(); i++){
            
            if(i % 2 == 0){
                if(s[i] != '0') count1++;
                if(s[i] != '1') count2++;
            }
            else{
                if(s[i] != '1') count1++;
                if(s[i] != '0') count2++;
            }
        }

        return min(count1, count2);
    }
};