#include <iostream>
#include <vector>

using namespace std;

int sub_node_num(int root, int parent, vector<vector<int>>& edge, vector<int>& nodes, vector<bool>& visit)
{
	if (edge[root].size() == 1 && edge[root][0] == parent)
	{
		//nodes[root] = 1;
		visit[root] = true;
		return nodes[root];
	}

	if (visit[root])
		return nodes[root];

	for (int i=0;i<edge[root].size();i++)
	{
		if (edge[root][i] == parent)
			continue;
		if (visit[edge[root][i]])
			nodes[root] += nodes[edge[root][i]];
		else
		{
			nodes[root] += sub_node_num(edge[root][i], root, edge, nodes, visit);
		}
	}

	visit[root] = true;
	return nodes[root];
}

int main()
{
	int n;
	cin >> n;
	vector<vector<int>> edge(n+1);
	vector<int> nodes(n+1, 1);
	vector<bool> visit(n+1);
	for (int i=0;i<n-1;i++)
	{
		int p,q;
		cin >> p >> q;
		edge[p].push_back(q);
		edge[q].push_back(p);
	}

	sub_node_num(1, 0, edge, nodes, visit);

	//for (int i=1;i<=n;i++)
	//	cout << nodes[i] << endl;

}