// #include <bits/stdc++.h>
// using namespace std;
// #define ll long long

// int main(){
    
//     vector<float> profit= {100, 60 ,120};
//     vector<float> weight= {20,10, 30 };

//     int n=3;
//     int m =50;

//     vector<float> pw(n);
//     for(int i=0 ;i<n; i++){
//         pw[i] = profit[i]/weight[i];
//     }
//     reverse(pw.begin(), pw.end());

//     int Tp=0;
//     int i;
//     for(i=0; i<n; i++){
//         if(m>0 && weight[i]<=m){
//             m-=weight[i];
//             Tp+=profit[i];
//         }
//         else
//             break;
//     }
//     // 6 5 4
//     if(m>0){
//         Tp+=m*pw[i];
//     }
//     cout << "Profit: " << Tp << endl;	
// 	return 0;
// }


// #include <iostream>
// #include <vector>
// #include <algorithm>

// using namespace std;

// int knapsack(int capacity, const vector<int>& weights, const vector<int>& values, int n) {
//     vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, 0));

//     for (int i = 1; i <= n; ++i) {
//         for (int w = 1; w <= capacity; ++w) {
//             if (weights[i - 1] <= w) {
//                 dp[i][w] = max(values[i - 1] + dp[i - 1][w - weights[i - 1]], dp[i - 1][w]);
//             } else {
//                 dp[i][w] = dp[i - 1][w];
//             }
//         }
//     }

//     return dp[n][capacity];
// }

// int main() {
//     int capacity = 50;
//     vector<int> weights = {10, 20, 30};
//     vector<int> values = {60, 100, 120};
//     int n = weights.size();

//     int max_value = knapsack(capacity, weights, values, n);
//     cout << "Maximum value: " << max_value << endl;

//     return 0;
// }

// #include <iostream>
// #include <vector>
// #include <algorithm>

// using namespace std;

// int knapsack(int capacity, const vector<int>& weights, const vector<int>& values, int n) {
//     vector<int> dp(capacity + 1, 0);

//     for (int i = 0; i < n; ++i) {
//         for (int w = capacity; w >= weights[i]; --w) {
//             dp[w] = max(dp[w], values[i] + dp[w - weights[i]]);
//         }
//     }

//     return dp[capacity];
// }

// int main() {
//     int capacity = 50;
//     vector<int> weights = {10, 20, 30};
//     vector<int> values = {60, 100, 120};
//     int n = weights.size();

//     int max_value = knapsack(capacity, weights, values, n);
//     cout << "Maximum value: " << max_value << endl;

//     return 0;
// }

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int greedy(vector<vector<int>>& arr, int W) {
    sort(arr.begin(), arr.end(), [](const vector<int>& a, const vector<int>& b) {
        return a[2] < b[2];
    });

    int maxProfit = 0;
    int newW = W;
    int i;
    for (i = arr.size() - 1; i >= 0; i--) {
        int wt = arr[i][1];
        int profit = arr[i][0];
        if (W > 0 && wt <= newW) {
            newW -= wt;
            maxProfit += profit;
        } else {
            break;
        }
    }

    if (W > 0) {
        int ratio = arr[i][2];
        maxProfit += (newW * ratio);
    }

    return maxProfit;
}

int main() {
    vector<vector<int>> arr = {{100, 20, 5}, {120, 30, 4}, {60, 10, 6}};
    int W = 50;

    cout << greedy(arr, W) << endl;

    return 0;
}
