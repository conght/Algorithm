

#include <iostream>
#include <vector>


using namespace std;

int find_end(int root, int parent, vector<vector<int> >& edges)
{
    if (edges[root].size() == 1 && edges[root][0] == parent)
    {
        return root;
    }

    int next = root;
    for (int i=0;i<edges[root].size();i++)
        if (edges[root][i] != parent)
        {
            next = edges[root][i];
            break;
        }
    return find_end(next, root, edges);
}

void solution()
{
    int n,a,b;
    cin >> n;

    vector<vector<int> > edges(n+1);

    for (int i=0;i<n-1;i++)
    {
        cin >> a >> b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }

    int root = 0;
    for (int i=1;i<=n;i++)
    {
        if (edges[i].size()>2)
        {
            if (root == 0)
                root = i;
            else if (root != i)
            {
                cout << "No" << endl;
                return;
            }
        }
    }

    if (n == 2)
    {
        cout << "Yes" << endl << 1 << endl << edges[1][0] << " " << edges[2][0] << endl;
        return;
    }

    if (root == 0)
    {
        for (int i=1;i<n;i++)
        {
            if(edges[i].size() == 2)
            {
                root = i;
                break;
            }
        }
    }

    // std::vector<bool> v(n+1);
    // for (int i=0;i<=n;i++)
    //     v[i] = false;
    // v[root] = true;
    cout << "Yes" << endl;
    cout << edges[root].size() << endl;
    for (int i=0;i<edges[root].size();i++)
    {
        int end = find_end(edges[root][i], root, edges);
        cout << root << " " << end << endl;
    }
    return;
}

int main()
{
    solution();
}