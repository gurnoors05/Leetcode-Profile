// Last updated: 8/16/2026, 7:05:44 PM
class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        unordered_map<char,vector<char>> mp;
        string result;
        for(int i=0;i<s1.size();i++){
            char u=s1[i];
            char v=s2[i];
            mp[u].push_back(v);
            mp[v].push_back(u);
        }
        for(int i=0;i<baseStr.size();i++){
            vector<int> visited(26,0);
            result.push_back(dfs(mp,visited,baseStr[i]));
        }
        return result;
    }
    char dfs(unordered_map<char,vector<char>> &mp,vector<int>& visited,char u){
        char minChar=u;
        visited[u-'a']=1;
        for(char& v:mp[u]){
            if(visited[v-'a']==0){
                minChar=min(minChar,dfs(mp,visited,v));
            }
        }
        return minChar;
    }
};