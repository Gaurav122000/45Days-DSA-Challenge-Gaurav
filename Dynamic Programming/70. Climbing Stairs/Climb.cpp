class Solution {
public:
    int climbStairs(int n) {
        if(n==1) return 1;

        int dp[n+1]; // creating a dp storage
        dp[1] = 1;
        dp[2] = 2;

        for(int i = 3; i<=n; i++){ // it's only gonna run for 3 <  
            dp[i] = dp[i-1] + dp[i-2]; // subtracting steps from the given value, first ' - ' 1 steps then 2 steps
        }

        return dp[n];
    }
};