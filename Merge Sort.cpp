#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int>& v, int left, int mid, int right) {
    /*
     * Merges two subvectors of the vector: v[left..mid] and v[mid+1..right].
     * Assumes that both subvectors are already sorted.
     */
    vector<int> temp(right - left + 1);
    int i = left, j = mid + 1, k = 0;
    while (i <= mid && j <= right) {
        if (v[i] <= v[j]) {
            temp[k] = v[i];
            i++;
        } else {
            temp[k] = v[j];
            j++;
        }
        k++;
    }
    while (i <= mid) {
        temp[k] = v[i];
        i++;
        k++;
    }
    while (j <= right) {
        temp[k] = v[j];
        j++;
        k++;
    }
    for (i = left; i <= right; i++) {
        v[i] = temp[i - left];
    }
}

void merge_sort(vector<int>& v, int left, int right) {
    /*
     * Sorts the given vector in ascending order using merge sort.
     */
    if (left < right) {
        int mid = (left + right) / 2;
        merge_sort(v, left, mid);
        merge_sort(v, mid + 1, right);
        merge(v, left, mid, right);
    }
}

int main() {
    vector<int> v = {5, 2, 4, 6, 1, 3};
    merge_sort(v, 0, v.size() - 1);
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
    return 0;
}