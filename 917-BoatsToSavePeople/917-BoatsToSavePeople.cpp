// Last updated: 8/16/2026, 7:07:17 PM
class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(begin(people),end(people));
        int i=0;
        int j=people.size()-1;
        int score=0;
        while(i<=j){
            if(people[i]+people[j]<=limit){
                score++;
                i++;
                j--;
            }
            else{
                j--;
                score++;
            }
        }
        return score;
    }
};