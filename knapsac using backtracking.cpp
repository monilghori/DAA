#include <iostream>
#include <vector>

using namespace std;

int knapsack(vector<int>& values, vector<int>& weights, int capacity, int index, int currentValue) {
    /*
     * Solves the knapsack problem using backtracking.
     * Returns the maximum possible value that can be obtained by filling the knapsack with items.
     */
    if (capacity < 0) {
        return 0;
    }
    if (index == values.size()) {
        return currentValue;
    }
    int take = knapsack(values, weights, capacity - weights[index], index + 1, currentValue + values[index]);
    int skip = knapsack(values, weights, capacity, index + 1, currentValue);
    return max(take, skip);
}

int main() {
    vector<int> values = { 10, 40, 30, 50 };
    vector<int> weights = { 5, 4, 6, 3 };
    int capacity = 10;
    int maxValue = knapsack(values, weights, capacity, 0, 0);
    cout << "The maximum possible value is: " << maxValue << endl;
    return 0;
}
