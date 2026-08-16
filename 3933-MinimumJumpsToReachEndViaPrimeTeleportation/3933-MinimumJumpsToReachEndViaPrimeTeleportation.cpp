// Last updated: 8/16/2026, 6:50:17 PM
class Solution {
public:
    int minJumps(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,vector<int>> mp;
        int max_element=INT_MIN;
        for(int i=0;i<n;i++){
            mp[nums[i]].push_back(i);
             max_element = max(max_element, nums[i]);
        }
        vector<bool> isPrime=sievePrime(max_element);
        queue<int> q;
        q.push(0);
        vector<bool> visited(n);
        visited[0]=true;
        unordered_set<int> seen;
        int level=0;
        while(!q.empty()){
            int size=q.size();
            while(size--){
                int i=q.front();
                q.pop();
                if(i==n-1){
                    return level;
                }
                if(i-1>=0 && !visited[i-1]){
                    q.push(i-1);
                    visited[i-1]=true;
                }
                if(i+1<n && !visited[i+1]){
                    q.push(i+1);
                    visited[i+1]=true;
                }
                if(!isPrime[nums[i]] || seen.count(nums[i])){
                    continue;
                }
                for(int mul=nums[i];mul<=max_element;mul+=nums[i]){
                    if(mp.find(mul)!=mp.end()){
                        for(auto& m:mp[mul]){
                            if(!visited[m]){
                                q.push(m);
                                visited[m]=true;
                            }
                        }
                    }
                }
                seen.insert(nums[i]);
            }
            level++;
        }
        return -1;

    }
    vector<bool> sievePrime(int maxElement){
         vector<bool> isPrime;
         isPrime.resize(maxElement+1, true);

        isPrime[0] = false;
        isPrime[1] = false;

        for(int num = 2; num*num <= maxElement; num++) {
            if(isPrime[num]) {

                for(int multiple = num*num; multiple <= maxElement; multiple += num) {
                    isPrime[multiple] = false;
                }
            }
        }
        return isPrime;
    }
};