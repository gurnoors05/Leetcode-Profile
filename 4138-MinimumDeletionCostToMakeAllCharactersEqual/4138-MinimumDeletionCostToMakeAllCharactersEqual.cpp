// Last updated: 8/16/2026, 6:49:35 PM
class Solution {
public:
    long long minCost(string s, vector<int>& cost) {
        vector<long long> freq(26, 0);
        long long totalSum = 0;

        for (int i = 0; i < s.size(); i++) {
            totalSum += cost[i];
            freq[s[i] - 'a'] += cost[i];
        }

        long long mini = LLONG_MAX;
        for (int i = 0; i < 26; i++) {
            if (freq[i] > 0) {
                mini = min(mini, totalSum - freq[i]);
            }
        }

        return mini;
    }
};