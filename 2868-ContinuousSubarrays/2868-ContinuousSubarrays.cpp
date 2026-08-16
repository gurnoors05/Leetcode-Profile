// Last updated: 8/16/2026, 6:53:09 PM
class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> min_heap;
        priority_queue<pair<int,int>, vector<pair<int,int>>> max_heap;
        int l=0;
        int r=0;
        long long count=0;
        int n=nums.size();
        while(r<n){
            max_heap.push({nums[r],r});
            min_heap.push({nums[r],r});
            while(abs(max_heap.top().first - min_heap.top().first)>2){
                l++;
                while(!max_heap.empty() && max_heap.top().second<l){
                    max_heap.pop();
                }
                while(!min_heap.empty() && min_heap.top().second<l){
                    min_heap.pop();
                }
            }
            count+=r-l+1;
            r++;
        }
        return count;

    }
};