// Last updated: 8/16/2026, 6:50:00 PM
class Solution {
public:
    vector<vector<int>> t;
    int maxWalls(vector<int>& robots, vector<int>& distance, vector<int>& walls) {
        int n=robots.size();
        vector<pair<int,int>> robotDis(n);
        for(int i=0;i<n;i++){
            robotDis[i]={robots[i],distance[i]};
        }
        sort(robotDis.begin(),robotDis.end());
        sort(walls.begin(),walls.end());
        vector<pair<int,int>> range(n);
        for(int i=0;i<n;i++){
            int d=robotDis[i].second;
            int pos=robotDis[i].first;
            int leftLimit  = (i == 0)   ? 1   : robotDis[i-1].first+1;
            int rightLimit = (i == n-1) ? 1e9 : robotDis[i+1].first-1;
            int L=max(pos-d,leftLimit);
            int R=min(pos+d,rightLimit);
            range[i]={L,R};
        }
        t.assign(n+1, vector<int>(2, -1));
        return solve(robotDis,range,walls,0,0);
    }
    int solve(vector<pair<int,int>> &robotDis,vector<pair<int,int>> &range,vector<int>& walls,int i,int prevDir){
        int n=robotDis.size();
        if(i==n){
            return 0;
        }
        if(t[i][prevDir] != -1)
            return t[i][prevDir];
        int leftStart=range[i].first;
        if(prevDir == 1) { //prev robot fired bullet rtowards right
            leftStart = max(leftStart, range[i-1].second + 1);
        }
        int leftTake = countWalls(walls, leftStart, robotDis[i].first) 
                        + solve(robotDis, range, walls, i+1, 0);
                    
        int rightTake = countWalls(walls, robotDis[i].first, range[i].second) 
                        + solve(robotDis, range, walls, i+1, 1);

        
        return  t[i][prevDir] = max(leftTake, rightTake);

    }
    int countWalls(vector<int>& walls, int l, int r) {
        int left  = lower_bound(begin(walls), end(walls), l) - begin(walls);
        int right = upper_bound(begin(walls), end(walls), r) - begin(walls);

        return right - left;

    }
};