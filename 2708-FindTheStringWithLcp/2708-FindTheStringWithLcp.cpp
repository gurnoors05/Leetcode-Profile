// Last updated: 8/16/2026, 6:53:33 PM
class Solution {
public:
    string findTheString(vector<vector<int>>& lcp) {
        int n=lcp.size();
        string s(n,'a');
        for(int i=0;i<n;i++){
            // s[i] fill karna hai
            bool matched=false;
            vector<bool> forbidden(n,false);
            for(int j=0;j<i;j++){
                if(lcp[j][i]==0){
                    forbidden[s[j]-'a']=true;
                    continue;
                }
                matched=true;
                s[i]=s[j];
                break;
            }
            if(matched){
                continue;
            }
            for(int idx=0;idx<26;idx++){
                if(forbidden[idx]){
                    continue;
                }
                s[i]=char(idx+'a');
                break;
            }
        }
        // checking by again makeing Lcp matrix using string
        if(makeLCP(s)==lcp){
            return s;
        }
        return "";
    }
    vector<vector<int>> makeLCP(string s){
        int n=s.length();
        vector<vector<int>> ans(n,vector<int>(n));
        for(int i=0;i<n;i++){
            ans[i][n-1]=ans[n-1][i]=(s[i]==s[n-1])?1:0;
        }
        for(int i=n-2;i>=0;i--){
            for(int j=n-2;j>=0;j--){
                if(s[i]==s[j]){
                    ans[i][j]=1+ans[i+1][j+1];
                }
                else{
                    ans[i][j]=0;
                }
            }
        }
        return ans;
    }
};