class Solution
{
public:
    int solve(string &s, int left, int right, vector<vector<int>> &dp){
        if (left == right)
            return 1;
        if (dp[left][right] != -1)
            return dp[left][right];
        int ans = INT_MAX, tmp;
        for (int k = left; k < right; k++){
            tmp = solve(s, left, k, dp) + solve(s, k + 1, right, dp);
            ans = min(ans, tmp);
        }
        if (s[left] == s[right])
            ans--;
        dp[left][right] = ans;
        return ans;
    }
    int strangePrinter(string s)
    {
        int n= s.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return solve(s, 0, n- 1, dp);
    }
};