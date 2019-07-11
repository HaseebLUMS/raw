#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

bool func(pair<int, int> l, pair<int, int> r)
{
	return l.second < r.second;
}

int main()
{
	pair<int, int> a = {1, 3};
	pair<int, int> b = {3, 1};
	pair<int, int> arr[2] = {a, b};

	for(auto i: arr)
	{
		cout << i.first << "|" << i.second << " ";
	}cout << endl;

	sort(arr, arr+2, func);

	for(auto i: arr)
	{
		cout << i.first << "|" << i.second << " ";
	}cout << endl;

	return 0;
}