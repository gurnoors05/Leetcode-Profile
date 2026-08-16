// Last updated: 8/16/2026, 6:59:55 PM
class Solution {
public:
    char findKthBit(int n, int k) {
        if(n==1){
            return '0';
        }
        int length=(1<<n)-1; // Or 2^n-1
        if(k<ceil(length/2.0)){
            return findKthBit(n-1,k);
        }
        else if(k==ceil(length/2.0)){
            return '1';
        }
        else{
            char ch=findKthBit(n-1,length-(k-1));
            return ch=='0'?'1':'0';
        }

    }
};