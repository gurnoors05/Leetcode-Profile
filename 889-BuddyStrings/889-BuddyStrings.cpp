// Last updated: 8/16/2026, 7:10:41 PM
class Solution {
public:
    bool buddyStrings(string s, string goal) {
        if(s.length()!=goal.length()){
            return false;
        }
        if(s==goal){
            return checkFreq(s);
        }
        vector<int> indices;
        
        for(int i = 0; i < s.length(); i++) {
            if(s[i] != goal[i]) {
                indices.push_back(i);
            }
        }
        if(indices.size() != 2){
            return false;
        }
        int first  = indices[0];
        int second = indices[1];
        
        swap(s[first], s[second]);
        return s==goal;
    }
    bool checkFreq(string &s) {
        int arr[26] = {0};
        for(char &ch : s) {
            arr[ch-'a']++;
            if(arr[ch-'a'] > 1) {
                return true;
            }
        }
        
        return false;
    }
};