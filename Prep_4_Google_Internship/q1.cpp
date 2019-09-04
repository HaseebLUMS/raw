#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>

using namespace std;

int solve(int* flavors, int f, int* options, int o, vector<int> ans, int amount);

int main()
{
	int amount = 0;
	cin >> amount;

	int f = 0;
	cin >> f;
	int flavors[f] = {0};

	string trash = "";
	for(int i = 0; i < f; i++)
	{

		cin >> trash >> flavors[i];
	}

	int o = 0;
	cin >> o;
	int options[o] = {0};
	for(int i = 0; i < o; i++)
	{
		cin >> trash >> options[i];
	}

	vector<int> ans2;
	int ans = solve(flavors, f, options, o, ans2, amount);
	cout << ans << endl;
	return 0;
}

int abs(int i){return i < 0 ? -1*i : i;}

int solve(int* flavors, int f, int* options, int o, vector<int> ans, int amount)
{
	vector<int> options_ex;
	for(int i = 0; i < o; i++)
	{
		options_ex.push_back(options[i]);
		for(int j = 0; j < o; j++)
		{
			if(i == j){continue;}
			else{
				options_ex.push_back(options[i] + options[j]);
			}
		}
	}

	sort(options_ex.begin(), options_ex.end());

	for(int i = 0; i < f; i++)
	{
		ans.push_back(flavors[i]);
		for(int j = 0; j < options_ex.size(); j++)
		{
			ans.push_back(flavors[i] + options_ex[j]);
		}
	}

	sort(ans.begin(), ans.end());

	int diff = INT_MAX;
	int 
	for(int i = 0; i < ans.size(); i++)
	{
		int temp = abs(amount - ans[i]) ;
		cout << temp << endl;
		if(temp < diff)
		{
			diff = temp;
		}
	}

	return diff;
}