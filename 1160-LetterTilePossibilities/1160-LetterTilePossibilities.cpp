// Last updated: 8/16/2026, 7:04:59 PM
class Solution {
public:
    int numTilePossibilities(string tiles) {
        int n=tiles.size();
        string curr="";
        unordered_set<string> result;
        vector<bool> used(n,false);
        solve(tiles,curr,result,used);
        return result.size()-1;
    }
    void solve(string tiles,string curr,unordered_set<string> &result,vector<bool> &used){
        result.insert(curr);
        for(int i=0;i<tiles.size();i++){
            if(used[i]){
                continue;
            }
            used[i]=true;
            curr.push_back(tiles[i]);
            solve(tiles,curr,result,used);
            used[i]=false;
            curr.pop_back();
        }

    }
};