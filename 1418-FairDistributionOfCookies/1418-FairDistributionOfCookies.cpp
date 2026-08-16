// Last updated: 8/16/2026, 7:02:40 PM
class Solution {
public:
    int result=INT_MAX;
    int distributeCookies(vector<int>& cookies, int k) {
        vector<int> children(k,0);
        solve(cookies,k,children,0);
        return result;
    }
    void solve(vector<int>& cookies,int k,vector<int>& children,int idx){
        if(idx>=cookies.size()){
            int maxi=INT_MIN;
            for(int i=0;i<children.size();i++){
                maxi=max(maxi,children[i]);
            }
            result=min(result,maxi);  
            return;       
        }
        for(int i=0;i<k;i++){
            children[i]+=cookies[idx];
            solve(cookies,k,children,idx+1);
            children[i]-=cookies[idx];
        }
    }

};