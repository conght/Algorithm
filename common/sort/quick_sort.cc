#include <bits/stdc++.h>

using namespace std;

namespace algorithm {

int Partition(vector<int>& a, int lo, int hi) {
    int i = lo;
    int j = hi + 1;
    int v = a[lo];

    while (true) {
        while (a[++i] < v) if (i == hi) break;
        while (a[--j] > v) if (j == lo) break;

        if (j < i) break;
        exch(a, i, j);
    }
    exch(a, lo, j);
}

void Sort(vector<int>& a, int lo, int hi) {
    if (lo >= hi) return;

    int mid = Partition(a, lo, hi);
    Sort(a, lo, mid-1);
    Sort(a, mid+1, hi);
}

void QuickSort(vector<int>& a) {
    if (input,size() <= 1) {
        return;
    }

    Sort(a, 0, a.size()-1);
}

};

int main() {
    return 0;
}
