// Last updated: 8/16/2026, 7:00:57 PM
class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        priority_queue<pair<int,int>, vector<pair<int,int>>> maxHeap;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> minHeap;
        int l=0;
        int r=0;
        int n=nums.size();
        int max_length=0;
        while(r<n){
            maxHeap.push({nums[r],r});
            minHeap.push({nums[r],r});
            while(maxHeap.top().first-minHeap.top().first>limit){
                l=min(maxHeap.top().second,minHeap.top().second) + 1;
                while(maxHeap.top().second<l){
                    maxHeap.pop();
                }
                while(minHeap.top().second<l){
                    minHeap.pop();
                }

            }
            int length=r-l+1;
            max_length=max(max_length,length);
            r++;

        }
        return max_length;
    }
};