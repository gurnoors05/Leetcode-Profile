// Last updated: 8/16/2026, 7:01:59 PM
class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(),arr.end(), [](int &a,int &b){
            int bitCount1 = __builtin_popcount(a);
            int bitCount2 = __builtin_popcount(b);
            return bitCount1!=bitCount2 ? bitCount1<bitCount2:a<b;
        });
        return arr;

    }
};