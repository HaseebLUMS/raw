#include <iostream>
#include <vector>
#include <map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        graph g = buildGraph(numCourses, prerequisites);
        vector<bool> todo(numCourses, false), done(numCourses, false);
        for (int i = 0; i < numCourses; i++) {
            if (!done[i] && !acyclic(g, todo, done, i)) {
                return {};
            }
        }
        reverse(topo.begin(), topo.end());
        return topo;
    }
private:
    typedef vector<vector<int>> graph;
    vector<int> topo;
    
    graph buildGraph(int numCourses, vector<pair<int, int>>& prerequisites) {
        graph g(numCourses);
        for (auto p : prerequisites) {
            g[p.second].push_back(p.first);
        }
        return g;
    }
    
    bool acyclic(graph& g, vector<bool>& todo, vector<bool>& done, int node) {
        if (todo[node]) {
            return false;
        }
        if (done[node]) {
            return true;
        }
        todo[node] = done[node] = true;
        for (int v : g[node]) {
            if (!acyclic(g, todo, done, v)) {
                return false;
            }
        }
        topo.push_back(node);
        todo[node] = false;
        return true;
    }
};
int main()
{
	Solution s;
	vector<pair<int, int>> pr = {};
	pr.push_back(make_pair(2, 0));
	pr.push_back(make_pair(1, 0));
	pr.push_back(make_pair(3, 1));
	pr.push_back(make_pair(3, 2));
	pr.push_back(make_pair(1, 3));

	bool ans = s.canFinish(4, pr);
	cout << endl<< ans << endl;
	return 0;
}

// 4
// [[2,0],[1,0],[3,1],[3,2],[1,3]]