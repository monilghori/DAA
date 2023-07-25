#include <iostream>
#include <vector>

using namespace std;

void selection_sort(vector<int>& v) {
    /*
     * Sorts the given vector in ascending order using selection sort.
     */
    for (int i = 0; i < v.size() - 1; i++) {
        int min_index = i;
        for (int j = i + 1; j < v.size(); j++) {
            if (v[j] < v[min_index]) {
                min_index = j;
            }
        }
        if (min_index != i) {
            swap(v[i], v[min_index]);
        }
    }
}

int main() {
    vector<int> v = {5, 2, 4, 6, 1, 3};
    selection_sort(v);
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
    return 0;
}