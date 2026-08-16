// Last updated: 8/16/2026, 7:07:06 PM
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int i=0;
        int j=0;
        int n=fruits.size();
        unordered_map<int,int> mp;
        int count=0;
        while(j<n){
            mp[fruits[j]]++;
            if(mp.size()<=2){
                count=max(count,j-i+1);
            }
            else{
                mp[fruits[i]]--;
                if(mp[fruits[i]]==0){
                    mp.erase(fruits[i]);
                }
                i++;
            }
            j++;
        }
        return count;
    }
};