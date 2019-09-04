#include <iostream>
#include <vector>
#include <map>
#include <unordered_set>

using namespace std;

class Solution {
    struct node
    {
        int val;
        bool visiting;
        bool visited;
        unordered_set<int> neigh;
        
        node(){visiting = false; visited = false;}
    };
    unordered_set<int> done;
public:
    
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        if(numCourses <= 0){return true;}
        if(prerequisites.size() <= 0){return true;}
        node* arr[numCourses];
        for(int i = 0; i< numCourses; i++){arr[i] = new node();arr[i]->val = i;}
        for(auto i: prerequisites){arr[i.first] -> neigh . insert(i.second);}

        // for(auto i: arr)
        // {
        // 	cout << i -> val << " => ";
        // 	for(auto j: i->neigh)
        // 	{
        // 		cout<< j << ", ";
        // 	} cout << endl;
        // }
        
        bool ans = false;
        for(int i = 0; i< numCourses; i++)
        {
        	ans = ans || isCycle(arr, i, numCourses);
        	if(!ans == false){return false;}
        }
        return !ans;
    }

    bool isCycle(node* arr[], int curr, int size)
    {
    	if(done.count(curr) > 0){return false;}
    	if(arr[curr] -> visiting){return true;}
    	arr[curr]->visiting = true;
    	bool ans = false;
    	for(auto i: arr[curr]->neigh){if(isCycle(arr, i, size)){ans = true;}}
    	arr[curr]->visiting = false;
    	arr[curr]->visited  = true;
    	cout << curr << " -> ";
    	if(ans == false){done.insert(curr);}
    	return ans;
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