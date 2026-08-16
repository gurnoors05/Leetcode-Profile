// Last updated: 8/16/2026, 7:01:40 PM
class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        int n=events.size();
        sort(events.begin(),events.end());
        priority_queue<int,vector<int>, greater<int>> pq;
        int i=0;
        int day=0;
        int count=0;
        while(i<n || !pq.empty()){
            if(pq.empty()){
                day=events[i][0];
            }
            while(i<n && events[i][0]==day){
                pq.push(events[i][1]); // push ending date
                i++;
            }
            while(!pq.empty() && day>pq.top()){
                pq.pop();
            }
            if(!pq.empty()){
                pq.pop();
                count++;
                day++;
            }

        }
        return count;
    }
    
};