// Last updated: 8/16/2026, 7:02:31 PM
class Solution {
public:
    vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos, vector<vector<int>>& friends, int id, int level) {
        vector<int> visited(friends.size(),false);
        queue<pair<int,int>> q;
        unordered_map<string,int> freq;
        q.push({id,0});
        vector<int> ans;
        visited[id]=true;
        while(!q.empty()){
            int friendId=q.front().first;
            int lvl=q.front().second;
            q.pop();
            if(lvl==level){
                ans.push_back(friendId);
            }
            for(auto& v:friends[friendId]){
                if(!visited[v]){
                    visited[v]=true;
                    q.push({v,lvl+1});
                }
            }
        }
        for(auto& id:ans){
            for(auto& video:watchedVideos[id]){
                freq[video]++;
            }
        }
        vector<pair<int,string>> temp;
        for(auto x:freq){
            temp.push_back({x.second,x.first});
        }
        sort(temp.begin(),temp.end());
        vector<string> result;
        for(auto [frequency,video]:temp){
            result.push_back(video);
        }
        return result;

    }
};