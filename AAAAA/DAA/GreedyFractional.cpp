#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int greedy(vector<vector<int>>& arr, int W) {
    for (vector<int>& item : arr) {
        item.push_back(item[0] / item[1]); // Calculate ratio and add it to the vector
    }

    sort(arr.begin(), arr.end(), [](const vector<int>& a, const vector<int>& b) {
        return a[2] > b[2]; // Sort in descending order of ratios
    });

    int maxProfit = 0;
    int newW = W;

    for (int i = 0; i < arr.size(); i++) {
        int wt = arr[i][1];
        int profit = arr[i][0];
        if (newW >= wt) {
            newW -= wt;
            maxProfit += profit;
        } else {
            maxProfit += (newW * arr[i][2]); // Add fraction of the item to the profit
            break;
        }
    }

    return maxProfit;
}

int main() {
    vector<vector<int>> arr = {{100, 20}, {120, 30}, {60, 10}};
    int W = 50;

    cout << greedy(arr, W) << endl;

    return 0;
}
