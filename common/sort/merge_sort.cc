#include <bits/stdc++.h>

using namespace std;

void Merge(vector<int>& a, vector<int>& aux, int lo, int mid, int hi) {
    int i = lo;
    int j = mid + 1;

    for (int k=0; k<a.size(); k++)
        aux[k] = a[k];

    for (int k=0; k<a.size(); k++) {
        if (i > mid) a[k] = aux[j++];
        else if (j > hi) a[k] = aux[i++];
        else if (aux[i] > aux[j]) a[k] = aux[j++];
        else a[k] = aux[i++];
    }
}

void Sort(vector<int>& a, vector<int>& aux, int lo, int hi) {
    if (hi <= lo) return;

    int mid = (lo + hi) / 2;

    Sort(a, aux, lo, mid);
    Sort(a, aux, mid+1, hi);
    Merge(a, aux, lo, mid, hi);
}

void MergeSort(vector<int>& input) {
    if (input.size() <= 1) {
        return ;
    }

    vector<int> aux(input.size(), 0);
    Sort(a, aux, 0, input.size());
}

int main() {
    return 0;
}