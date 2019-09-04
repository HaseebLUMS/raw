#include <iostream>
#include <limits.h>
#include <vector>
#include <queue>

using namespace std;

struct node
{
	int v;
	vector<int> neigh;
	int temp;
};


int solve(node* nodes, int n);
int BFS(node* nodes, int n, int curr);

int main()
{
	int n = 0;
	cin >> n;

	node nodes[n];
	for(int i = 0; i < n; i++)
	{
		nodes[i].v = i;
		nodes[i].temp = 0;
		nodes[i].neigh = {};
	}


	for(int i = 0; i < n-1; i++)
	{
		int a = 0, b = 0;
		cin >> a >> b;
		nodes[a-1].neigh.push_back(b-1);
		nodes[b-1].neigh.push_back(a-1);
	}

	int ans = solve(nodes, n);
	cout << ans << endl;
	return 0;
}

int BFS(node* nodes, int n, int curr)
{
	for(int i = 0; i < n; i++){nodes[i].temp = 0;}
	
	int visited[n] = {0};

	queue<int> q;
	visited[curr] = 1;
	q.push(curr);

	int max = 0;

	while(!q.empty())
	{
		int t = q.front(); 
		q.pop();

		if(nodes[t].temp > max)
		{
			max = nodes[t].temp;
		}

		vector<int> ns = nodes[t].neigh;

		for(auto i : ns)
		{
			if(visited[i] == 0)
			{
				visited[i] = 1;
				nodes[i].temp = nodes[t].temp + 1;
				q.push(i);
			}
		}

	}

	return max;
}

int solve(node* nodes, int n)
{
	int ans = INT_MAX;
	for(int i = 0; i < n; i++)
	{
		int temp = BFS(nodes, n , i);
		if(temp < ans){ans = temp;}
	}
	return ans;
}