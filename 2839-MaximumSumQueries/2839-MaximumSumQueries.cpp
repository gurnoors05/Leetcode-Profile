// Last updated: 8/16/2026, 6:53:20 PM
class NumArray{
    public:
    vector<int> tree;
    int n;
    NumArray(int n){
        this->n = n;
        tree.resize(4*n, -1);
    }
    void build(int pos, int val, int tl, int tr, int node) {
        if (tl == tr) {
            tree[node] = max(tree[node], val);
            return;
        }
        int mid = (tl + tr) >> 1;

        if (pos <= mid)
            build(pos, val, tl, mid, 2 * node + 1);
        else
            build(pos, val, mid + 1, tr, 2 * node + 2);

        tree[node] = max(tree[2 * node + 1], tree[2 * node + 2]);
    }

    void update(int val, int index) {
        build(index, val, 0, n - 1, 0);
    }
    int query(int tl, int tr, int ql, int qr, int index){
        if (ql>tr || qr<tl) return -1;
        if (ql<=tl && qr>=tr) return tree[index];
        int mid = (tl+tr)>>1;
        int left = query(tl, mid, ql, qr, 2*index+1); //left
        int right = query(mid+1, tr, ql, qr, 2*index+2); //right    
        return max(left, right);
    }
};
class Solution {
public:
    vector<int> maximumSumQueries(vector<int>& nums1, vector<int>& nums2, vector<vector<int>>& queries) {
        for(int i=0;i<queries.size();i++){
            queries[i].push_back(i);
        }
        sort(queries.begin(),queries.end(),[&](auto &a,auto &b){
            return a[0]>b[0];
        });
        vector<pair<int,int>> vec;
        for(int i=0;i<nums1.size();i++){
            vec.push_back({nums1[i],nums2[i]});
        }
        sort(vec.begin(),vec.end(),[&](auto &a,auto &b){
            return a.first>b.first;
        });
        sort(nums2.begin(), nums2.end());
        nums2.erase(unique(nums2.begin(), nums2.end()), nums2.end());

        NumArray* root=new NumArray(nums2.size());
        int k=0;
        vector<int> result(queries.size());
        for(int i=0;i<queries.size();i++){
            int x=queries[i][0];
            int y=queries[i][1];
            int index=queries[i][2];
            while(k<vec.size() && vec[k].first>=x){
                int y_index=findBinarySearch(vec[k].second,nums2);
                root->update(vec[k].first + vec[k].second,y_index);
                k++;
            }
            int y_index2=findBinarySearch(y,nums2);
            int ans=root->query(0,nums2.size()-1,y_index2,nums2.size()-1,0);
            result[index]=ans;
        }
        return result;

    }
    int findBinarySearch(int y,vector<int>& nums){
        int index=lower_bound(nums.begin(),nums.end(),y)-nums.begin();
        return index;
    }
};