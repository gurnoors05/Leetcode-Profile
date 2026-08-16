// Last updated: 8/16/2026, 6:55:53 PM
class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(asteroids.begin(),asteroids.end());
        long long currMass=mass;
        for(int i=0;i<asteroids.size();i++){
            if(currMass<asteroids[i]){
                return false;
            }
            currMass+=asteroids[i];
        }
        return true;
    }
};