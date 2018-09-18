#include <bits/stdc++.h>

using namespace std;

//template <typename T>
void InsertSort(vector<int>& input) {
    if (input.size() <= 1) {
        return ;
    }

    for (int i=1; i<input.size(); i++) {
        for (int j=i; j>0 && input[j]<input[j-1]; j--) {
            int tmp = input[j-1];
            input[j-1] = input[j];
            input[j] = tmp;
        }
    }
    return;
}

int main() {
    return 0;
}