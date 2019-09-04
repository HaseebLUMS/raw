#include <iostream>
using namespace std;


int TotalPaths(int** grid, int r, int c, int i, int j)
{
	if(i < 0 || j < 0 || i >= r || j >= c){return 0;}

	if((i == r-1) && (j == c-1)){return 1;}

	return TotalPaths(grid, r, c, i, j+1) + TotalPaths(grid, r, c, i+1, j);
}


int main()
{
	int r = 2, c = 2;
	int** grid = new int*[r];
	for(int i = 0; i < r; i++)
	{
		grid[i] = new int[c];
	}

	cout << TotalPaths(grid, r, c, 0, 0) << endl;
	return 0;
}
