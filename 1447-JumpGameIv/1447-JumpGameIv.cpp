// Last updated: 8/16/2026, 7:02:20 PM
class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n=arr.size();
       unordered_map<int,vector<int>> mp;
        for(int i=0;i<arr.size();i++){
            mp[arr[i]].push_back(i);
        }
        vector<bool> visited(arr.size(),false);
        visited[0]=true;
        queue<int> q;
        int level=0;
        q.push(0);
        while(!q.empty()){
            int size=q.size();
            while(size--){
                int i=q.front();
                q.pop();
                if(i==n-1){
                    return level;
                }
                int left=i-1;
                int right=i+1;
                if(left>=0 && !visited[left]){
                    q.push(left);
                    visited[left]=true;
                }
                if(right<n && !visited[right]){
                    q.push(right);
                    visited[right]=true;
                }
                for(auto& it:mp[arr[i]]){
                    if(!visited[it]){
                        visited[it]=true;
                        q.push(it);
                    }
                }
                mp.erase(arr[i]);
            }
            level++;
        }
        return -1;
    }
};