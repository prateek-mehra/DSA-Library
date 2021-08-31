// Time: O(N!)
// Space: O(N)
class Solution {
    vector<int> used;
    bool dfs(vector<int> &ans, int i) {
        if (i == ans.size()) return true; // filled all the numbers, found the answer
        if (ans[i]) return dfs(ans, i + 1); // this index is already filled, continue to fill the next index.
        for (int j = used.size() - 1; j > 0; --j) { // try each number in decending order from n -1 to 1.
            if (used[j]) continue; // j is already used, skip
            if (j != 1 && (i + j >= ans.size() || ans[i + j])) continue; // we can't fill `ans[i + j]` either because `i + j` is out of bound or `ans[i + j]` is already filled. Skip.
            used[j] = 1; // mark number `j` as used.
            ans[i] = j; // fill `ans[j]` and `ans[i + j]` (if needed) with `j`.
            if (j != 1) ans[i + j] = j;
            if (dfs(ans, i + 1)) return true;
            ans[i] = 0; // this filling is invalid, backtrack and try the next number.
            if (j != 1) ans[i + j] = 0;
            used[j] = 0;
        }
        return false;
    }
public:
    vector<int> constructDistancedSequence(int n) {
        vector<int> ans(2 * n - 1);
        used.assign(n + 1, 0); // numbers 1 ~ n are unused initially
        dfs(ans, 0); // try filling numbers from index 0.
        return ans;
    }
};
