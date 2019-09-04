#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        vector<vector<pair<int, int>>> graph;
        for(int i = 0; i< N; i++)
        {
        	graph.push_back({});
        }

        for(auto i: times)
        {
        	graph[i[0]].push_back(make_pair(i[1], i[2]));
        }

        

    }
};


int main()
{
	Solution s;
	vector<vector<int>> times = {{0, 1, 5}, {1, 2, 3}};
	s.networkDelayTime(times, 3, 0);
	return 0;
}