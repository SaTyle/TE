#include <iostream>
#include <vector>
using namespace std;

int knapSackrecur(int W, int N, vector<int> &v, vector<int> &w, vector<vector<int>> &dp)
{

    if (N == 0 || W == 0) return 0;

    if (dp[N][W] != -1)  return dp[N][W];

    if (w[N] <= W)
        return dp[N][W] = max(v[N] + knapSackrecur(W - w[N], N - 1, v, w, dp), knapSackrecur(W, N - 1, v, w, dp));

    else  return dp[N][W] = knapSackrecur(W, N - 1, v, w, dp);
    
}

int main()
{
    vector<int> w = {2, 5, 1, 3, 4};
    vector<int> v = {15, 14, 10, 45, 30};
    int N = w.size();
    int W = 7;
    
    vector<vector<int>> dp(N + 1, vector<int>(W + 1, -1));

    cout <<  knapSackrecur(W, N - 1, v, w, dp) << endl;
    
}