#include <bits/stdc++.h>

using namespace std;

/*void InsertSort(vector<int>& input) {
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
*/

template <class RandomAccessIterator>
void InsertSort(RandomAccessIterator first,
                RandomAccessIterator last) {

    for (RandomAccessIterator i = first;
         i != last;
         i++) {
        for (RandomAccessIterator j=i;
             j != first && *j < *(j-1); j--) {
            swap(*(j-1), *j);
        }
    }
    return;
}

int main() {
    std::vector<int> v = {3, 2, 1};
    InsertSort(v.begin(), v.end());
    for (auto i : v) {
        cout << i << endl;
    }
    return 0;
}