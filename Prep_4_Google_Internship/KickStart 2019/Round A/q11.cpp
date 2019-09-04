#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
using namespace std;

int main()
{
	int tt = 0;
	cin >> tt; 
	for(int t = 0; t < tt; t++)
	{
		int n = 0, p = 0;
		cin >> n >> p;
		vector<int> vec;
		for(int i = 0; i < n; i++)
		{
			int skill = 0;
			cin >> skill;
			vec.push_back(skill);
		}

		sort(vec.begin(), vec.end());
		int arr[p];
		int tmp = p;
		int ans = INT_MAX;
		for(int i = 0; i<= vec.size()-p; i++)
		{
			for(int j = i; j < i+p; j++)
			{
				arr[j-i] = vec[j];
			}
			int train = 0;
			for(int j = p-2; j >= 0; j--)
			{
				train += (arr[p-1] - arr[j]);
				
			}

			ans = train < ans ? train : ans;
		}
		cout << "Case #"<< t+1<< ": " << ans << endl;
	}
	return 0;
}