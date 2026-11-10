int climbStairs(int n, int* costs, int costsSize) {
    int dp[n+1], min, temp, i, j;

    for(i=0, dp[0]=0; i<costsSize; i++) {
        for(j=1, min=dp[i]+1; i-j>=0&&j<=2; j++) {
            temp=dp[i-j]+((j+1)*(j+1));
            min=min<=temp?min:temp;
        } dp[i+1]=min+costs[i];
    }

    return dp[n];
}