// Last updated: 8/16/2026, 7:03:48 PM
class Solution {
public:
    int maxNumberOfBalloons(string text) {
       vector<int> count(26,0);
        for(int i=0;i<text.length();i++){
            count[text[i]-'a']++;
        }
        return min({
            count['b'-'a'],
            count['a'-'a'],
            count['l'-'a']/2,
            count['o'-'a']/2,
            count['n'-'a']
        });


    }
};