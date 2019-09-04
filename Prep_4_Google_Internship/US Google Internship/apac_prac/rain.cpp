#include <iostream>
#include <map>
#include <vector>
#include <queue>
#include <limits.h>

using namespace std;

bool valid(pair<int, int> p, int r, int c)
{
	if(p.first < 0 || p.second < 0 || p.first >= r || p.second >= c){return false;}
	return true;
}

bool isEdge(pair<int, int> p, int r, int c)
{
	if(p.first == 0 || p.second == 0 || p.first == r-1 || p.second == c-1){return true;}
	return false;
}

int BFS(pair<int, int> pos, int** arr, int r, int c, vector<pair<int, int> >& neighs)
{
	int visited[r][c] = {0};

	int me = arr[pos.first][pos.second];
	int minMax = INT_MAX;

	queue<pair<int, int> > q;
	q.push(pos);
	visited[pos.first][pos.second] = 1;

	while(!q.empty())
	{
		auto elem = q.front(); q.pop();


		pair<int, int> ns[4];
		ns[0] = make_pair(elem.first, elem.second + 1);
		ns[1] = make_pair(elem.first + 1, elem.second);
		ns[2] = make_pair(elem.first, elem.second - 1);
		ns[3] = make_pair(elem.first - 1, elem.second);




		for(int i = 0; i < 4; i++)
		{
			if(valid(ns[i], r, c))
			{
				if(arr[ns[i].first][ns[i].second] < arr[pos.first][pos.second]){return 0;}
				int temp = arr[ns[i].first][ns[i].second];
				if(temp < minMax && temp > me){minMax = temp;}
			}

			if(valid(ns[i], r, c) && arr[elem.first][elem.second] == arr[ns[i].first][ns[i].second] && !visited[ns[i].first][ns[i].second])
			{
				visited[ns[i].first][ns[i].second] = 1;
				q.push(ns[i]);
				neighs.push_back(ns[i]);
			}
		}
	}


	if(isEdge(pos, r, c)){return 0;}
	for(auto k: neighs){

		if(isEdge(k, r, c)){return 0;}
	}
	return minMax == INT_MAX ? 0 : minMax; 
	return minMax;
}

int giveMinNeigh(pair<int, int>pos, int** arr, int r, int c)
{
	vector<pair<int, int> > neighs;

	int minMax = BFS(pos, arr, r, c, neighs);
	// cout << pos.first << " " << pos.second << " minMax: " << minMax<< endl;
	// cout << minMax << " <= " << pos.first << " " << pos.second << endl;

	int prev = arr[pos.first][pos.second];

	if(minMax > 0)
	{	
		arr[pos.first][pos.second] = minMax;
		for(auto k : neighs)
		{
			arr[k.first][k.second] = minMax;
		}

		return (minMax - prev)*(neighs.size()+1);
	}
	return 0;

}

int main()
{
	int tt = 0;
	cin >> tt;
	for(int t = 0; t < tt; t++)
	{
		int r  = 0, c = 0;
		cin >> r >> c;
		int** arr = new int*[r];
		for(int i = 0; i < r; i++){arr[i] = new int[c];}
	    
		for(int i = 0; i < r; i++)
		{
			for(int j = 0; j < c; j++)
			{
				cin >> arr[i][j];
			}
		}

	    map<int, vector<pair<int, int> > > m;

	    for(int i = 0; i < r; i ++)
	    {
	        for(int j = 0; j < c; j++)
	        {
	            if(m.find(arr[i][j]) == m.end())
	            {
	                pair<int, int> p = {i, j};
	                m[arr[i][j]] = {p};
	            }
	            else
	            {
	                pair<int, int> p = {i, j};
	                m[arr[i][j]].push_back(p);
	            }
	        }
	    }


	    int ans = 0;
	    for(auto h: m)
	    {
	    	for(auto pos: h.second)
	    	{
	    		int n = giveMinNeigh(pos, arr, r, c); //will report minMax neigh and update neighbors
	    		ans += n;
	    		// if(n > 0){cout << pos.first << " " << pos.second << " | " << arr[pos.first][pos.second]<< endl;}
	    	}
	    }

	    cout << "Case #" << t+1 << ": " << ans << endl;
	}

    return 0;
}