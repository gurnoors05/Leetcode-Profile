// Last updated: 8/16/2026, 7:01:25 PM
class Solution {
public:

    void solve(int n, string result, char prev, vector<string>& ans) {

        if(result.length() == n){
            ans.push_back(result);
            return;
        }

        string s = "abc";

        for(int i=0;i<3;i++){
            if(s[i] != prev){

                result.push_back(s[i]);

                solve(n, result, s[i], ans);

                result.pop_back();
            }
        }
    }

    string getHappyString(int n, int k) {

        vector<string> ans;

        solve(n,"",'#',ans);

        sort(ans.begin(), ans.end());

        if(ans.size() >= k)
            return ans[k-1];

        return "";
    }
};