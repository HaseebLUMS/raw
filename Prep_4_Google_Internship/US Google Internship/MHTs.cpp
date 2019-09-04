#include <iostream>
#include <map>
#include <vector>

using namespace std;
struct node
{
	int id;
	vector<int> children;
};

vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges)
{
	node arr[n];
}


int main()
{
	int n = 4;
	vector<pair<int, int>> vec = {make_pair(1, 0), make_pair(1, 2), make_pair(1, 3)};
	vector<int> ans = findMinHeightTrees(n, vec);
	return 0;
}

/*

n = 4, edges = [[1, 0], [1, 2], [1, 3]]
*/