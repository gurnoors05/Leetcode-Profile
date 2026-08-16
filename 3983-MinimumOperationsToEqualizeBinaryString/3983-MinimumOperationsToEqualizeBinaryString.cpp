// Last updated: 8/16/2026, 6:49:57 PM
class Solution {
public:
    int minOperations(string s, int k) {
        // int totalZeros=0;
        // int n=s.length();
        // for(int i=0;i<s.length();i++){
        //     if(s[i]=='0'){
        //         totalZeros++;
        //     }
        // }
        // if(totalZeros == 0) {
        //     return 0; //no operations required
        // }
        // queue<int> q;
        // vector<int> result(n+1,-1);
        // result[totalZeros]=0;
        // q.push(totalZeros);
        // while(!q.empty()){
        //     int z=q.front();
        //     q.pop();
        //     int f1=max(0,k-n+z);
        //     int f2=min(k,z);
        //     for(int f=f1;f<=f2;f++){
        //         int new_z=z+k-2*f;
        //         if(result[new_z]==-1){
        //             result[new_z]=result[z]+1;
        //             if(new_z==0){
        //                 return result[new_z];
        //             }
        //             q.push(new_z);
        //         }
                
        //     }
        // }
        // return -1;



        int n = s.length();

        int startZeros = 0;
        for(char &ch : s) {
            if(ch == '0')
                startZeros++;
        }

        if(startZeros == 0) {
            return 0; //no operations required
        }

        vector<int> operations(n+1, -1);
        //operations[z] = min operations required to reach state in which we have z 0s

        set<int> evenSet;
        set<int> oddSet;

        for(int count = 0; count <= n; count++) {
            if(count%2 == 0) {
                evenSet.insert(count);
            } else {
                oddSet.insert(count);
            }
        }

        queue<int> que;
        que.push(startZeros);
        operations[startZeros] = 0;
        if(startZeros % 2 == 0) {
            evenSet.erase(startZeros);
        } else {
            oddSet.erase(startZeros);
        }

        while(!que.empty()) {
            int z = que.front();
            que.pop();
            
            int min_new_z = z + k - 2*min(k, z);
            int max_new_z = z + k - 2*max(0, k-n+z);

            set<int> &currSet = (min_new_z%2 == 0) ? evenSet : oddSet;

            auto it = currSet.lower_bound(min_new_z);

            while(it != currSet.end() && *it <= max_new_z) {
                int newZ = *it;

                if(operations[newZ] == -1) {
                    operations[newZ] = operations[z] + 1;

                    if(newZ == 0) {
                        return operations[newZ];
                    }

                    que.push(newZ);
                }

                it = currSet.erase(it);
            }
        }

        return -1;
    }
};