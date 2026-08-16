// Last updated: 8/16/2026, 7:07:01 PM
class Solution {
public:
    int M=1e9+7;
    int sumSubarrayMins(vector<int>& arr) {
        int n=arr.size();
        vector<int> NSL=findNSL(arr);
        vector<int> NSR=findNSR(arr);
        long long sum = 0;

        for(int i = 0; i < n; i++){
            long long d1 = i - NSL[i];
            long long d2 = NSR[i] - i;

            long long total = (d1 * d2) % M;
            long long contribution = (arr[i] * total) % M;

            sum = (sum + contribution) % M;
        }
        return sum;
    }
    vector<int> findNSL(vector<int>& arr){
        vector<int> NSL(arr.size());
        stack<int> st;
        for(int i=0;i<arr.size();i++){
            if(st.empty()) {
                NSL[i] = -1;
            } else {
                while(!st.empty() && arr[st.top()] >arr[i]) //strictly less
                    st.pop();
                
                NSL[i] = st.empty() ? -1 : st.top();
            }
            st.push(i);
        }
        return NSL;
    }
    vector<int> findNSR(vector<int>& arr){
        int n=arr.size();
        vector<int> NSR(arr.size());
        stack<int> st;
        for(int i=arr.size()-1;i>=0;i--){
            if(st.empty()){
                NSR[i]=n;
            }
            else{
                while(!st.empty() && arr[i]<=arr[st.top()]){
                    st.pop();
                }
                NSR[i]= st.empty() ? n:st.top(); 
            }
            st.push(i);
        }
        return NSR;
    }
};