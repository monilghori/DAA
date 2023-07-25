#include <iostream>
#include <vector>

using namespace std;

int sequential_search(vector<int> v, int target) {
    /*
     * Returns the index of the target in the given vector, or -1 if not found.
     */
    for (int i = 0; i < v.size(); i++) {
        if (v[i] == target) {
            return i;
        }
    }
    return -1;
}

int main() {
    vector<int> v = {1, 2, 3, 4, 5};
    int target = 3;
    int index = sequential_search(v, target);
    if (index == -1) {
        cout << "Target not found" << endl;
    } else {
        cout << "Target found at index " << index << endl;
    }
    return 0;
}