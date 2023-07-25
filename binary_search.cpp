#include <iostream>
#include <vector>

using namespace std;

int binary_search(vector<int> v, int target) {
    /*
     * Returns the index of the target in the given sorted vector, or -1 if not found.
     */
    int left = 0;
    int right = v.size() - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (v[mid] == target) {
            return mid;
        } else if (v[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}

int main() {
    vector<int> v = {1, 2, 3, 4, 5};
    int target = 3;
    int index = binary_search(v, target);
    if (index == -1) {
        cout << "Target not found" << endl;
    } else {
        cout << "Target found at index " << index << endl;
    }
    return 0;
}