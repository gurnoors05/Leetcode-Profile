// Last updated: 8/16/2026, 6:50:33 PM
class Solution {
public:
    // TLE
    // int maxDistance(int side, vector<vector<int>>& points, int k) {
    //     int n=points.size();
    //     int l=0;
    //     int r=2*side;
    //     int result=-1;
    //     while(l<=r){
    //         int mid=l+(r-l)/2;
    //         vector<int> chosen;
    //         if(check(mid,points,k,0,chosen)){
    //             result=mid;
    //             l=mid+1;
    //         }
    //         else{
    //             r=mid-1;
    //         }
    //     }
    //     return result;
    // }
    // bool check(int mid,vector<vector<int>>& points, int k,int i,vector<int>& chosen){
    //     if(chosen.size()>=k){
    //         return true;
    //     }
    //     for(int p=i;p<points.size();p++){
    //         bool valid=true;
    //         for(int idx:chosen){
    //             if(manhattanDis(points[p], points[idx]) < mid){
    //                 valid=false;
    //                 break;
    //             }
    //         }
    //         if(!valid){
    //             continue;
    //         }
    //         chosen.push_back(p);
    //         if(check(mid,points,k,p+1,chosen)){
    //             return true;
    //         }
    //         chosen.pop_back();
    //     }
    //     return false;
    // }
    // int manhattanDis(vector<int>& p1, vector<int>& p2) {
    //     return abs(p1[0] - p2[0]) + abs(p1[1] - p2[1]);
    // }


    int maxDistance(int side, vector<vector<int>>& points, int k) {
        int n=points.size();
        long long perimeter=4LL*side;
        vector<long long> position(n);
        for(int i=0;i<n;i++){
            position[i]=get1D(side,points[i][0],points[i][1]);
        }
        sort(position.begin(),position.end());
        vector<long long> doubledRotated(2*n);
        for(int i=0;i<n;i++){
            doubledRotated[i]=position[i];
            doubledRotated[i+n]=position[i]+perimeter;
        }
        int l=0;
        int r=2*side;
        int result=-1;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(check(mid,doubledRotated,k,points,side)){
                l=mid+1;
                result=mid;
            }
            else{
                r=mid-1;
            }
        }
        return result;
    }
    bool check(int mid,vector<long long> &doubled,int k,vector<vector<int>>& points,int side){
        long long perimeter=4LL*side;
        int n=points.size();
        for(int i=0;i<points.size();i++){
            int idx=i;
            int count=1;
            long long lastPos=doubled[idx];
            for(int j=2;j<=k;j++){
                long long target=lastPos+mid;
                auto it=lower_bound(begin(doubled)+i+1,begin(doubled)+i+n, target);
                if(it==begin(doubled)+i+n){
                    break;
                }
                idx=it-begin(doubled);
                lastPos=doubled[idx];
                count++;
            }
            if(count==k && doubled[i]+perimeter-lastPos>=mid){
                return true;
            }
        }
        return false;
    }
    long long get1D(int side, int x, int y) {
        if(y == 0) return x;

        if(x == side) return side + y;

        if(y == side) return 3LL * side - x;

        return 4LL * side - y;
    }
};