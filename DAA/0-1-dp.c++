#include <iostream>
#include <cstring>
using namespace std;

int knapSackDP(int val[], int wt[], int W, int n, int dp[][1001]) {
    if (W == 0 || n == 0) {
        return 0;
    }
    
    if(dp[n][W] != -1) {
        return dp[n][W];
    }

    if (wt[n - 1] <= W) {
        int ans1 = val[n - 1] + knapSackDP(val, wt, W - wt[n - 1], n - 1, dp);
        int ans2 = knapSackDP(val, wt, W, n - 1, dp);
        dp[n][W] = max(ans1, ans2);
        return dp[n][W];
    }
    else {
        dp[n][W] = knapSackDP(val, wt, W, n - 1, dp);
        return dp[n][W];
    }
}

int main() {
    int val[] = {15, 14, 10, 45, 30};
    int wt[] = {2, 5, 1, 3, 4};
    int W = 7;
    int dp[6][1001];
    memset(dp, -1, sizeof(dp));

    cout << knapSackDP(val, wt, W, 5, dp) << endl;

    return 0;
}
