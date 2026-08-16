// Last updated: 8/16/2026, 6:53:57 PM
class Solution {
public:
    // int result=INT_MAX;
    // int takeCharacters(string s, int k) {
    //     int n=s.length();
    //     vector<int> chars(3,0);
        
    //     solve(s,k,n,0,n-1,chars,0);
    //     return result==INT_MAX?-1:result;
    // }
    // void solve(string& s,int k,int n,int i,int j,vector<int> &chars,int minutes){
    //     if(chars[0]>=k && chars[1]>=k && chars[2]>=k){
    //         result=min(result,minutes);
    //         return;
    //     }
    //     if(i>j || minutes>result){
    //         return;
    //     }
    //     chars[s[i]-'a']++;
    //     solve(s,k,n,i+1,j,chars,minutes+1);
    //     chars[s[i]-'a']--;
    //     chars[s[j]-'a']++;
    //     solve(s,k,n,i,j-1,chars,minutes+1);
    //     chars[s[j]-'a']--;
    // }


    int takeCharacters(string s, int k) {
        int n=s.size();
        int l=0;
        int r=0;
        vector<int> chars(3);
        int max_length=INT_MIN;
        for(int i=0;i<n;i++){
            chars[s[i]-'a']++;
        }
         if (chars[0] < k || chars[1] < k || chars[2] < k) {
            return -1;
        }
        while(r<n){
            chars[s[r]-'a']--;
            
                while(l<=r && (chars[0]<k || chars[1]<k || chars[2]<k)){
                    chars[s[l]-'a']++;
                    l++;
                }
            
            int not_deleted=r-l+1;
            max_length=max(max_length,not_deleted);
            r++;
        }
        return n-max_length;
    }
};