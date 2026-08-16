// Last updated: 8/16/2026, 6:57:04 PM
class Solution {
public:
    long long MOD = 1e9 + 7;

    long long solve(long long base, long long exp) {
        if (exp == 0) return 1;

        long long half = solve(base, exp / 2);

        if (exp % 2 == 0) {
            return (half * half) % MOD;
        } else {
            return (base * half % MOD * half % MOD) % MOD;
        }
    }

    int countGoodNumbers(long long n) {
        long long even = solve(5, (n + 1) / 2);
        long long odd  = solve(4, n / 2);

        return (even * odd) % MOD;
    }
};