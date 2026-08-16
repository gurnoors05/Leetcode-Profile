// Last updated: 8/16/2026, 6:51:07 PM
class Solution {
public:
    vector<long long> countKConstraintSubstrings(string s, int k, vector<vector<int>>& queries) {
        int n=s.size();
        vector<int> leftSubstring(n);
        vector<int> rightSubstring(n);
        int l=0;
        int r=0;
        int count0=0;
        int count1=0;
        while(r<n){
            if(s[r]=='0'){
                count0++;
            }
            else{
                count1++;
            }
            while(count0>k && count1>k){
                if(s[l]=='0'){
                    count0--;
                }
                else{
                    count1--;
                }
                l++;
            }
            leftSubstring[r]=l;
            r++;
        }

        l=n-1;
        r=n-1;
        count0=0;
        count1=0;
        while(r>=0){
            if(s[r]=='0'){
                count0++;
            }
            else{
                count1++;
            }
            while(count0>k && count1>k){
                if(s[l]=='0'){
                    count0--;
                }
                else{
                    count1--;
                }
                l--;
            }
            rightSubstring[r]=l;
            r--;
        }
        vector<int> validSubstr(n,0);
        for(int i=0;i<n;i++){
            validSubstr[i]=i-leftSubstring[i]+1;
        }
        vector<long long> cumulativeSubstring(n,0);
        cumulativeSubstring[0]=validSubstr[0];
        for(int i=1;i<n;i++){
            cumulativeSubstring[i]=cumulativeSubstring[i-1]+validSubstr[i];
        }


        vector<long long> ans;
        for(int i=0;i<queries.size();i++){
            int low=queries[i][0];
            int high=queries[i][1];
            int validRight=min(rightSubstring[low], high);
            long long length=validRight-low+1;
            long long result=length*(length+1)/2;
            result+=cumulativeSubstring[high]-cumulativeSubstring[validRight];
            ans.push_back(result);
        }
        return ans;
    }
};