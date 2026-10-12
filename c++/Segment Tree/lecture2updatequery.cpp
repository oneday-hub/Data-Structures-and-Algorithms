// lecture 2 : Segment Tree | Update Query |


#include <bits/stdc++.h>
using namespace std;

void buildSegmentTree(int i, int l, int r, vector<int> &arr, vector<int> &segmentTree) {
    // Base case: leaf node
    if (l == r) {
        segmentTree[i] = arr[l];
        return;
    }

    int mid = l + (r - l) / 2;

    buildSegmentTree(2 * i + 1, l, mid, arr, segmentTree);
    buildSegmentTree(2 * i + 2, mid + 1, r, arr, segmentTree);

    segmentTree[i] = segmentTree[2 * i + 1] + segmentTree[2 * i + 2];
}

void updateSegmentTree(int index, int value, int i, int l, int r, vector<int> &arr, vector<int> &segmentTree) {
    // Base case: target leaf node
    if (l == r) {
        arr[index] = value;
        segmentTree[i] = value;
        return;
    }

    int mid = l + (r - l) / 2;

    // Find the subtree containing index
    if (index <= mid) {
        updateSegmentTree(index, value, 2 * i + 1, l, mid, arr, segmentTree);
    } else {
        updateSegmentTree(index, value, 2 * i + 2, mid + 1, r, arr, segmentTree);
    }

    // Recalculate the current node
    segmentTree[i] = segmentTree[2 * i + 1] + segmentTree[2 * i + 2];
}

int main() {
    vector<int> arr = {2, 1, 5, 3, 4, 7, 6, 8};
    int n = arr.size();

    vector<int> segmentTree(4 * n);

    buildSegmentTree(0, 0, n - 1, arr, segmentTree);

    cout << "Before update: ";
    for (int i = 0; i < 2 * n - 1; i++) {
        cout << segmentTree[i] << " ";
    }
    cout << endl;

    // Change arr[2] from 5 to 10
    updateSegmentTree(2, 10, 0, 0, n - 1,
                      arr, segmentTree);

    cout << "After update:  ";
    for (int i = 0; i < 2 * n - 1; i++) {
        cout << segmentTree[i] << " ";
    }
    cout << endl;

    cout << "Updated array: ";
    for (int x : arr) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}

/*
this is the output : 

Before update: 36 11 25 3 8 11 14 2 1 5 3 4 7 6 8 
After update:  41 16 25 3 13 11 14 2 1 10 3 4 7 6 8 
Updated array: 2 1 10 3 4 7 6 8 
*/