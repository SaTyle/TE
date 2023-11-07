#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <climits>

using namespace std;

const int INF = INT_MAX;

int tsp(int mask, int pos, vector<vector<int>>& graph, vector<vector<int>>& dp) {
    int n = graph.size();

    if (mask == (1 << n) - 1) return graph[pos][0]; // Return to the starting city

    if (dp[mask][pos] != -1) return dp[mask][pos];

    int ans = INF;
    for (int city = 0; city < n; ++city) {
        if ((mask & (1 << city)) == 0) { // If city is not visited
            ans = min(ans, graph[pos][city] + tsp(mask | (1 << city), city, graph, dp));
        }
    }

    return dp[mask][pos] = ans;
}

int main() {
    int n; // Number of cities
    cin >> n;

    vector<vector<int>> graph(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> graph[i][j];
        }
    }

    // dp[mask][i] stores the minimum cost to visit all cities in the mask and end in city i
    vector<vector<int>> dp(1 << n, vector<int>(n, -1));

    cout << "Minimum cost of visiting all cities: " <<  tsp(1, 0, graph, dp); // Start 0


    return 0;
}
