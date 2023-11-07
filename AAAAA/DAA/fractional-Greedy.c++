


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


