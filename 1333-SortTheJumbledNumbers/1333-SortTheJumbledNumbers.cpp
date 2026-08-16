// Last updated: 8/16/2026, 7:03:22 PM
class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        int n=nums.size();
        vector<pair<int,int>> vec;
        for(int i=0;i<n;i++){
            string num_str=to_string(nums[i]);
            string mapped_num=checkMappingNumber(num_str,mapping);
            int mappedNo=stoi(mapped_num);
            vec.push_back({mappedNo,i});
        }
        sort(begin(vec),end(vec));
        vector<int> result;
        for(int i=0;i<vec.size();i++){
            result.push_back(nums[vec[i].second]);
        }
        return result;
    }
    string checkMappingNumber(string num_str,vector<int>& mapping){
        string ans="";
        for(int i=0;i<num_str.length();i++){
            char ch=num_str[i];
            int mapped=mapping[ch-'0'];
            ans+=to_string(mapped);
        }
        return ans;
    }
};