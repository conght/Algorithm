#include <bits/stdc++.h>

using namespace std;

template <unsigned N>
struct  fibonacci
{
    enum {
        val = fibonacci<N-1>::val + fibonacci<N-2>::val
    };
};

template <>
struct fibonacci<0>
{
    enum {
        val = 0
    };
};

template <>
struct fibonacci<1>
{
    enum {
        val = 1
    };
};

int main() {
    cout << fibonacci<2>::val << endl;
    return 0;
}