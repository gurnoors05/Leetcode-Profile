// Last updated: 8/16/2026, 6:53:37 PM
class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        vector<int> prefix(words.size()+1);
        prefix[0]=0;
        for(int i=0;i<words.size();i++){
            string it=words[i];
            int n=it.size();
            if((it[0]=='a' || it[0]=='e' || it[0]=='i' || it[0]=='o' || it[0]=='u') && (it[n-1]=='a' || it[n-1]=='e' || it[n-1]=='i' || it[n-1]=='o' || it[n-1]=='u')){
                prefix[i+1]=prefix[i]+1;
            }
            else{
                prefix[i+1]=prefix[i];
            }
        }
        for(int i=0;i<words.size()+1;i++){
            cout<<prefix[i]<<" ";
        }
        vector<int> ans;
        for(auto& q:queries){
            int i=q[0];
            int j=q[1];
            ans.push_back(prefix[j+1]-prefix[i]);
        }
        return ans;

    }
};