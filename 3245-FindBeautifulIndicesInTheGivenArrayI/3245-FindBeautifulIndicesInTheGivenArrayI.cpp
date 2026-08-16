// Last updated: 8/16/2026, 6:52:20 PM
class Solution {
public:
    vector<int> beautifulIndices(string s, string a, string b, int k) {
        int n=s.length();
        vector<int> i_indices=KMP(a,s);
        vector<int> j_indices=KMP(b,s);
        vector<int> result;
        for(int i=0;i<i_indices.size();i++){
            int left_limit=max(0,i_indices[i]-k);
            int right_limit=min(n-1,i_indices[i]+k);
            auto it=lower_bound(begin(j_indices),end(j_indices),left_limit);
            if(it!=j_indices.end() && *it<=right_limit){
                result.push_back(i_indices[i]);
            }
        }
        return result;
    }
    vector<int> KMP(string pattern,string text){
        int n=text.length();
        int m=pattern.length();
        vector<int> lps(m,0);
        computeLPS(pattern,lps);
        vector<int> result;
        int i=0;
        int j=0;
        while(i<n){
            if(text[i]==pattern[j]){
                
                i++;
                j++;
            }
            if(j==m){
                result.push_back(i-j);
                j=lps[j-1];
            }
            else if(i<n && text[i]!=pattern[j]){
                if(j!=0){
                    j=lps[j-1];
                }
                else{
                    i++;
                }
            }
        }
        return result;
    }
    void computeLPS(string pattern,vector<int>& lps){
        lps[0]=0;
        int i=1;
        int length=0;
        while(i<pattern.size()){
            if(pattern[i]==pattern[length]){
                length++;
                lps[i]=length;
                i++;
            }
            else{
                if(length!=0){
                    length=lps[length-1];
                }
                else{
                    lps[i]=0;
                    i++;
                }
            }
        }
    }

};