#include <iostream>
#include <vector>
#include <set>
#include <limits.h>
#include <string>

using namespace std;

int ab(int i)
{
	if(i < 0){return -1*i;}
	return i;
}

int dis(int i, int j, int x, int y)
{
	return ab(x-i) + ab(y-j);
}


int main()
{
	int tt = 0;
	cin >> tt;
	for(int t = 0; t < tt; t++)
	{

		int r = 0, c = 0;
		cin >> r >> c;
		if(r <= 0 || c <= 0){cout << "Case #" << t+1 << ": 0" << endl;}
		int arr[r][c];
		int mindis[r][c];

		set<string> store;
		vector<pair<int, int>> vec;
		for(int i = 0; i< r; i++)
		{
			string data = ""; cin >> data;
			for(int j = 0; j< c; j++)
			{
				int item = data[j] - '0';
				
				if(item == 1){store.insert(to_string(i) + "," + to_string(j)); pair<int, int> p = make_pair(i, j); vec.push_back(p);}
			}
		}
		//for(auto p: vec){cout << p.first << ", " << p.second << endl;}
		pair<int, int> maxdis;
		int max = INT_MIN;
		vector<pair<int, int>> same;
		for(int i = 0; i< r; i++)
		{
			for(int j = 0; j< c; j++)
			{
				//if(i == 1 && j == 1){cout << "w " << endl;}else{cout << "nw" << endl;}
				if(store.find(to_string(i)+ "," + to_string(j)) != store.end()){continue;}
				int min = INT_MAX;
				for(auto p: vec)
				{
					int d = dis(i, j, p.first, p.second);
					if(d < min){
						min = d;
					}
					
				}
				mindis[i][j] = min;
				if(max < min && min < INT_MAX)
				{
					max = min;
					maxdis = make_pair(i, j);
				}
			}
		}
		/*========*/
		
		store.insert(to_string(maxdis.first) + "," + to_string(maxdis.second));
		vec.push_back(maxdis);
		
		//pair<int, int> maxdis;
		if(max == INT_MIN){cout << "Case #" << t+1 << ": "<< 0 << endl; continue;}
		max = INT_MIN;
		for(int i = 0; i< r; i++)
		{
			for(int j = 0; j< c; j++)
			{
				if(store.find(to_string(i) + "," + to_string(j)) != store.end()){continue;}
				int min = INT_MAX;
				for(auto p: vec)
				{
					int d = dis(i, j, p.first, p.second);
					min = d < min ? d : min;
				}
				mindis[i][j] = min;
				if(max < min && min < INT_MAX)
				{
					max = min;
					maxdis = make_pair(i, j);
				}
			}
		}
		cout << "Case #" << t+1 << ": "<< max << endl;
		/*========*/


		// if(max == INT_MIN){cout << "Case #" << t+1 << ": "<< 0 << endl;}
		// else{
		// 	int mx = INT_MIN;
		// 	for(int i = 0; i< r; i++)
		// 	{
		// 		for(int j = 0; j< c; j++)
		// 		{
		// 			if(store.find(i + "," + j) != store.end()){continue;}
		// 			int curr = dis(maxdis.first, maxdis.second, i, j);
		// 			int tmp = curr < mindis[i][j] ? curr : mindis[i][j];
		// 			mx = tmp > mx ? tmp : mx;
		// 		}
		// 	}
		// 	cout << "Case #" << t+1 << ": " << mx << endl;
		// }
	}

	return 0;
}