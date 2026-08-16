// Last updated: 8/16/2026, 6:52:04 PM
class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        sort(capacity.begin(),capacity.end());
        int total=0;
        for(int i=0;i<apple.size();i++){
            total+=apple[i];
        }
        int i=capacity.size()-1;
        int boxes=0;
        while(i>=0){
            if(total>0){
                total-=capacity[i];
                boxes++;
            }
            else{
                break;
            }
            i--;
        }
        return boxes;
    }
};