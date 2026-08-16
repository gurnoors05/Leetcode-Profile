// Last updated: 8/16/2026, 6:58:15 PM
class Solution {
public:
    vector<vector<int>> dp;

    int maxValue(vector<vector<int>>& events, int k) {
        sort(events.begin(), events.end()); // sort by start time
        int n = events.size();
        dp.assign(n, vector<int>(k+1, -1));
        return solve(events, 0, k);
    }

    int solve(vector<vector<int>>& events, int i, int k) {
        if (i >= events.size() || k == 0) return 0;
        if (dp[i][k] != -1) return dp[i][k];

        // Skip this event
        int skip = solve(events, i+1, k);

        // Take this event
        int next = findNext(events, events[i][1], i+1);
        int take = events[i][2] + solve(events, next, k-1);

        return dp[i][k] = max(skip, take);
    }

    // Binary search: first event with start > endTime
    int findNext(vector<vector<int>>& events, int endTime, int left) {
        int lo = left, hi = events.size();
        while (lo < hi) {
            int mid = (lo + hi) / 2;
            if (events[mid][0] > endTime) hi = mid;
            else lo = mid + 1;
        }
        return lo;
    }
};
