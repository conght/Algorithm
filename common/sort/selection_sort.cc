#include <bits/stdc++.h>

using namespace std;

//template <typename T>
void SelectionSort(vector<int>& input) {
    if (input.size() <= 1) {
        return ;
    }

    for (int i=0; i<input.size()-1; i++) {
        int min = input[i];
        int index = i;
        for (int j=i+1; j<input.size(); j++) {
            if (min > input[j]) {
                min = input[j];
                index = j;
            }
        }
        if (index != i) {
            int tmp = input[i];
            input[i] = input[index];
            input[index] = tmp;
        }
    }

    return;
}

int main() {
    return 0;
}