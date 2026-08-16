// Last updated: 8/16/2026, 6:49:46 PM
class Solution {
public:
    vector<vector<string>> wordSquares(vector<string>& words) {
        vector<vector<string>> ans;
        for(int i=0;i<words.size();i++){
            for(int j=0;j<words.size();j++){
                if(i==j){
                    continue;
                }
                if(words[i][0]!=words[j][0]){
                    continue;
                }
                for(int k=0;k<words.size();k++){
                    if(k==i || j==k){
                        continue;
                    }
                    if(words[i][3]!=words[k][0]){
                        continue;
                    }

                    for(int d=0;d<words.size();d++){
                        if(d==k || d==j || d==i){
                            continue;
                        }
                        if(words[d][0]!=words[j][3]){
                            continue;
                        }
                        if(words[d][3]!=words[k][3]){
                            continue;
                        }
                        ans.push_back({
                            words[i],
                            words[j],
                            words[k],
                            words[d]
                        });
                    }
                }
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};