// Last updated: 8/16/2026, 6:56:49 PM
class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        // int n=nums.size();
        // unordered_set<int> st;
        // for(string& s:nums){
        //     st.insert(stoi(s,0,2));
        // }
        // string result="";
        // for(int number=0;number<=n;number++){
        //     if(st.find(number)==st.end()){
        //         result = bitset<16>(number).to_string();
        //         break;
        //     }
        // }
        // return result.substr(16-n);

        int n=nums.size();
        unordered_set<string> st;
        string temp="";
        solve(n,st,temp);
        for(auto& s:nums){
            if(st.find(s)!=st.end()){
                st.erase(s);
            }
        }
        return *st.begin();
    }
    void solve(int n,unordered_set<string>& st,string &temp){
        if(temp.length()==n){
            st.insert(temp);
            return;
        }
        temp.push_back('1');
        solve(n,st,temp);
        temp.pop_back();

        temp.push_back('0');
        solve(n,st,temp);
        temp.pop_back();
    }
};