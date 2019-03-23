#include <iostream>
#include <map>

using namespace std;


int max(int a, int b){return a>b? a: b;}

multimap<int, int> m;

int rob(int * arr, int j)
{
	if(j == 0){return arr[j];}
	if(j<0){return 0;}

	if(m.find(j) == m.end())
	{
		int ans =  max( (arr[j] + rob(arr, j-2)), (0+rob(arr, j-1)) );
		m.insert({j, ans});
		return ans;
	}
	else
	{
		return (m.find(j))->second;
	}
}


int main()
{
	int arr[] = {1, 2, 3, 1};
	int size = sizeof(arr)/sizeof(arr[0]);
	cout << rob(arr, size-1) << endl;
	return 0;
}