//http://codeforces.com/contest/982/problem/B

#include <iostream>
#include <algorithm>
#include <vector>
#include <sstream>
#include <stack>

using namespace std;

typedef struct _seats
{
	int index = 0;
	int weight = 0;
} seats;

bool compare (seats i,seats j) { return (i.weight<j.weight); }

void solution()
{
    int n;
    cin >> n;

    std::vector<seats> seats_info(n);
    std::vector<int> result_array;
    for(int i=0;i<n;i++)
    {	
    	int w = 0;
        cin >> w;
        seats_info[i].index = i+1;
        seats_info[i].weight = w;
    }

    sort(seats_info.begin(), seats_info.end(), compare);

    int p = 0, q = n-1;

    stack<int> stk;
    string s;
    cin >> s;
    for (int i=0;i<2*n;i++)
    {
        if (s[i] == '0')
        {
        	//cout << p << endl;
        	cout  << seats_info[p].index;
        	stk.push(p);
        	if (p < n-1)
        	{
        		++p;
        	}
        	
        }
        if (s[i] == '1')
        {
        	//cout << q << endl;
        	q = stk.top();
        	stk.pop();
        	cout << seats_info[q].index;
        }
        if (i != 2*n - 1)
        	cout << ' ';
    }

}

int main()
{
    solution();
}