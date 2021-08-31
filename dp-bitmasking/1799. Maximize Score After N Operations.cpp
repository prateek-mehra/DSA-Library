/*We need to do the full search for this one. For each i, we try every pair from the remaining numbers. Fortunately, the number of pairs in this problem is limited to 7.

Nonetheless, we need to do memoisation to avoid TLE. We can track numbers that we used using a bit mask, and also use that bitmask for the memoisation. For 14 numbers, we will have 2 ^ 14 = 16384 possible combinations.*/

int dp[8][16384] = {};
int maxScore(vector<int>& n, int i = 1, int mask = 0) {
    if (i > n.size() / 2)
        return 0;
    if (!dp[i][mask])
        for (int j = 0; j < n.size(); ++j)
            for (auto k = j + 1; k < n.size(); ++k) {
                int new_mask = (1 << j) + (1 << k);
                if ((mask & new_mask) == 0)
                    dp[i][mask] = max(dp[i][mask], i * __gcd(n[j], n[k]) + maxScore(n, i + 1, mask + new_mask));
            }
    return dp[i][mask];
}
