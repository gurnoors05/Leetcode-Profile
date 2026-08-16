// Last updated: 8/16/2026, 6:53:17 PM
class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& health, string directions) {
        int n=positions.size();
        vector<int> indices(n);
        for(int i=0;i<n;i++){
            indices[i]=i;
        }
        auto lambda=[&](int i,int j){
            return positions[i]<positions[j];
        };
        sort(begin(indices),end(indices),lambda);
        stack<int> st;
        for(int i=0;i<n;i++){
            int currIdx=indices[i];
            if(directions[currIdx]=='R'){
                st.push(currIdx);
            }
            else{
                while(!st.empty() && health[currIdx]>0){
                    int topIdx=st.top();
                    st.pop();
                    if(health[topIdx]>health[currIdx]){
                        health[currIdx]=0;
                        health[topIdx]-=1;
                        st.push(topIdx);
                    }
                    else if(health[topIdx]<health[currIdx]){
                        health[topIdx]=0;
                        health[currIdx]-=1;
                    }
                    else{
                        health[topIdx]=0;
                        health[currIdx]=0;
                    }
                }
            }
           
            
        }
         vector<int> ans;
            for(int i=0;i<n;i++){
                if(health[i]>0){
                    ans.push_back(health[i]);
                }
            }
            return ans;
    }
};