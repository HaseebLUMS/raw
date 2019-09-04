#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main()
{
	int tt = 0;
	cin >> tt;
	for(int t = 0; t < tt; t++)
	{

		int s = 0, b = 0;
		cin >> s >> b;
		// vector<pair<int, int>> bvec;
		vector<bool> seats (s, false); 
		multimap<int, pair<int, int>> bmap;
		for(int i = 0; i< b; i++)
		{
			pair<int, int> bpair;
			cin >> bpair.first >> bpair.second;
			bmap.insert(pair<int, pair<int, int>> (bpair.second-bpair.first + 1, bpair));
		}
		int ans = s;
		for(auto i: bmap)
		{
			int min = 0;
			for(int j = i.second.first; j <= i.second.second; j++)
			{
				if(!seats[j])
				{
					seats[j] = true;
					min ++;
				}
			}
			ans = min < ans ? min : ans;
		}

		cout << "Case #" << t +1 << ": " << ans << endl;
	}
	return 0;
}


/*
5 3
1 2
3 4
2 5


*/