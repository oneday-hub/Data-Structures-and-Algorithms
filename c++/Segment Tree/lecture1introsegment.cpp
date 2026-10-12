// lecture 1 : Segment Tree | Introduction | Basics | Build Segment Tree |


// To build segment tree taking case of problem range sum problem : 

#include <bits/stdc++.h>
using namespace std;

void buildSegmentTree(int i, int l, int r, vector<int> &arr, vector<int> &segmentTree){

    // base case : leaf node
    if(l == r){
        segmentTree[i] = arr[l];
        return;
    }

    // find middle
    int mid = l + (r - l) / 2;

    // Build left child
    buildSegmentTree(2*i + 1, l, mid, arr, segmentTree);

    // Build right child
    buildSegmentTree(2*i + 2, mid + 1, r, arr, segmentTree);

    // combine left and right child
    segmentTree[i] = segmentTree[2*i + 1] + segmentTree[2*i + 2];
}

int main() {
    vector<int> arr = {2, 1, 5, 3, 4, 7, 6, 8};

    int n = arr.size();

    // Allocate (4*n) space to segment tree : 
    vector<int> segmentTree(4 * n);


    // Build segment tree : 

    //               i, l, r
    buildSegmentTree(0, 0, n-1, arr, segmentTree);

    cout << "Segment Tree : ";

    for(int i = 0; i < 2 * n - 1; i++){
        cout << segmentTree[i] << " ";
    }
    cout << endl;

    return 0;
}