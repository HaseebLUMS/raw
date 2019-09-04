#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker);
int max(int a, int b){return a> b? a : b;}
int main()
{
	vector<int> difficulty = {2, 4, 6, 8, 10};
	vector<int> profit     = {10, 20, 30, 40, 50};
	vector<int> worker     = {4, 5, 6, 7};
	cout << maxProfitAssignment(difficulty, profit, worker) << endl;
	return 0;
}

int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
    
    int size = 100000;
    int arr[size];
    int prev = 0;

    for(int i = 0; i< size; i++){arr[i] = 0;}
    for(int i = 0; i < difficulty.size(); i++){arr[difficulty[i]] = max(profit[i], arr[difficulty[i]]);}
    for(int i = 0; i < size; i++){if(arr[i] != 0 && arr[i] > prev){prev = arr[i];}arr[i] = prev;}

    int p = 0;
	for(int i = 0; i< worker.size(); i++)
	{
		p += arr[worker[i]];
	}
	return p;
    return 0;
}
