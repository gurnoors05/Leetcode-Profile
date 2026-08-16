// Last updated: 8/16/2026, 6:54:42 PM
class Solution {
public:
    // Dry run is written in notebook
    int mostBooked(int n, vector<vector<int>>& meetings) {
        // vector<long long> lastAvailableTime(n,0);
        // vector<int> mostUsedRoom(n,0);
        // sort(begin(meetings),end(meetings));
        // for(int i=0;i<meetings.size();i++){
        //     int start=meetings[i][0];
        //     int end=meetings[i][1];
        //     bool found=false;
        //     long long earlyEndRoomTime=LLONG_MAX;
        //     int earlyEndRoom=-1;
        //     for(int j=0;j<n;j++){
        //         if(lastAvailableTime[j]<=start){
        //             lastAvailableTime[j]=end;
        //             found=true;
        //             mostUsedRoom[j]++;
        //             break;
        //         }
        //         if(lastAvailableTime[j]<earlyEndRoomTime){
        //             earlyEndRoomTime=lastAvailableTime[j];
        //             earlyEndRoom=j;
        //         }
        //     }
        //     if(!found){
        //         int duration=end-start;
        //         lastAvailableTime[earlyEndRoom]+=duration;
        //         mostUsedRoom[earlyEndRoom]++;
        //     }
        // }

        // int maxUsedRoom=-1;
        // int maxi=0;
        // for(int i=0;i<n;i++){
        //     if(maxi<mostUsedRoom[i]){
        //         maxi=mostUsedRoom[i];
        //         maxUsedRoom=i;
        //     }
        // }
        // return maxUsedRoom;


        // Using Priority Queue
        priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long ,int>>> lastAvailableTime; // Ending Time, room No
        priority_queue<int,vector<int> , greater<int>> availableRooms;
        vector<int> mostUsedRoom(n,0);
        sort(begin(meetings),end(meetings));
        for(int i=0;i<n;i++){
            availableRooms.push(i);
        }
        for(int i=0;i<meetings.size();i++){
            int start=meetings[i][0];
            int end=meetings[i][1];
            while(!lastAvailableTime.empty() && lastAvailableTime.top().first<=start){
                int room=lastAvailableTime.top().second;
                availableRooms.push(room);
                lastAvailableTime.pop();
            }
            if(!availableRooms.empty()){
                int lowestNumberRoom=availableRooms.top();
                availableRooms.pop();
                lastAvailableTime.push({end,lowestNumberRoom});
                mostUsedRoom[lowestNumberRoom]++;
            }
            else{ // No rooms Availble, so pop lowest ending time room
                int duration=end-start;
                long long lowestEndingTime=lastAvailableTime.top().first;
                int room=lastAvailableTime.top().second;
                lastAvailableTime.pop();
                lowestEndingTime+=duration;
                lastAvailableTime.push({lowestEndingTime,room});
                mostUsedRoom[room]++;
            }

        }
         int maxUsedRoom=-1;
        int maxi=0;
        for(int i=0;i<n;i++){
            if(maxi<mostUsedRoom[i]){
                maxi=mostUsedRoom[i];
                maxUsedRoom=i;
            }
        }
        return maxUsedRoom;

    }
};