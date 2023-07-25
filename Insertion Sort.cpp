#include <iostream>
#include <vector>

using namespace std;

void insertion_sort(vector<int>& v) {
    /*
     * Sorts the given vector in ascending order using insertion sort.
     */
    for (int i = 1; i < v.size(); i++) {
        int key = v[i];
        int j = i - 1;
        while (j >= 0 && v[j] > key) {
            v[j + 1] = v[j];
            j--;
        }
        v[j + 1] = key;
    }
}

int main() {
    vector<int> v = {5, 2, 4, 6, 1, 3};
    insertion_sort(v);
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
    return 0;
}
