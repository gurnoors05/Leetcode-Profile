// Last updated: 8/16/2026, 6:57:47 PM
class Solution {
public:
    bool checkIfPangram(string sentence) {
        unordered_map<char,int> mp;
        for(int i=0;i<sentence.size();i++){
            mp[sentence[i]]++;
        }
        return mp.size()==26;
    }
};