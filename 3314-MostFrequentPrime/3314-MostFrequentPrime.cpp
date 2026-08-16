// Last updated: 8/16/2026, 6:52:08 PM
class Solution {
public:
    unordered_map<int,int> mp;
    vector<vector<int>> directions={{-1,0},{1,0},{0,-1},{0,1},{-1,-1},{1,1},{-1,1},{1,-1}};
    int mostFrequentPrime(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
               for(auto& dir:directions){
                int x=i;
                int y=j;
                long long num=0;
                while(x>=0 && x<n && y>=0 && y<m){
                    num=num*10+mat[x][y];
                    x=x+dir[0];
                    y=y+dir[1];
                    if(num>10 && isPrime(num)){
                        mp[num]++;
                    }
                }
                
               }
            }
        }
        int ans=-1;
        int maxi=INT_MIN;
        for(auto& m:mp){
            if(m.second>maxi){
                ans=m.first;
                maxi=m.second;
            }
             else if(m.second == maxi){
                ans = max(ans, m.first);
            }
        }
        return ans;
    }
    bool isPrime(int n){
        if(n<2){
            return false;
        }
        for(int i=2;i*i<=n;i++){
            if(n%i==0){
                return false;
            }
            
        }
        return true;
    }
  
};