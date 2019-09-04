#include <iostream>
#include <vector>
using namespace std;

//2**n


void make_combs(int* arr, int n, int k, int i,vector<vector<int> >& all_combinations, vector<int> tmp)
{
	if(tmp.size() >= k){all_combinations.push_back(tmp); return;}

	for(int j = i+1; j < n; j++)
	{
		vector<int> tmp2(tmp);
		tmp2.push_back(arr[j]);
		make_combs(arr, n, k, j, all_combinations, tmp2);
	}
}

void choose(int* arr, int n, int k, vector<vector<int> >& all_combinations)
{
	for(int i = 0; i < n; i++)
	{
		make_combs(arr, n, k, i, all_combinations, {arr[i]});
	}
}

int main()
{
	int arr[4] = {0, 1, 2, 3};
	int n = 4;
	vector<vector<int> > all_combinations;

	for(int k = 1; k <= n; k++)
	{
		choose(arr, n, k, all_combinations);
	}

	for(auto i : all_combinations)
	{
		for(auto k: i){
			cout << k << " ";
		}cout << endl;
	}

	cout << "Total: " << all_combinations.size() << endl;
	return 0;
}