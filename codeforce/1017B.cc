#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main() {

    int n = 0;
    cin >> n;
    string A, B;

    cin >> A >> B;

    int total_one, total_zero, one, zero;
    for (int i=0;i<n;i++) {
        if (A[i] == '0') {
            total_zero ++ ;
            if (B[i] == '0')
                zero ++;
        }
        else {
            total_one ++ ;
            if (B[i] == '0')
                one++;
        }
    }

    int result = 0;
    result = one * total_zero + zero * total_one - one*zero;

    cout << result << endl;
}