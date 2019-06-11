#include <iostream>
using namespace std;

int change(int* coins, int N, int i)
{
	if(N == 0)         {return 1;}
	if(N >  0 && i < 0){return 0;}
	if(N <  0)         {return 0;}
	
	int without = change(coins, N, i-1);
	int with    = change(coins, N - coins[i], i);

	return with + without;
}


int main()
{
	int N = 4;
	int coins[] = {1, 2, 3};

	int ways = change(coins, N, N-1);

	cout << "Total Changes: " << ways << endl;
	return 0;
}