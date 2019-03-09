#include <iostream>
#include <time.h>
#include <cstdlib>
#include <ctime>

//int size_of_array;//here

struct Miner
{
	bool up;
	bool down;
	bool left;
	bool right;
};
struct mine_index
{
	int row;
	int column;
	


};
class Mine
{
public:

	bool **map;//hee as well
	int **copy_mine;
	int size_of_array;
	//#######    ATTENTION   #########//
	// size of array is a GLOBAL VARIABLE and it needs to be cin from main
	Mine()
	{

		 size_of_array=5;
		 srand(time(0));

		map = new bool*[size_of_array];
		for(int n=0; n< size_of_array; n++)
			map[n] = new bool[size_of_array];

		for(int i=0; i<size_of_array; i++)
		{
			for(int j=0; j<size_of_array; j++)
			{
               /* int a=(rand()%2);*/
                int a = rand()%2;
                map[i][j]=a;
			}
		}
	}

	Mine(int m)
	{
		 size_of_array=m;

		map = new bool*[size_of_array];
		for(int n=0; n< size_of_array; n++)
			map[n] = new bool[size_of_array];

		 std::cout << size_of_array << std::endl;
		for(int i=0; i<size_of_array; i++)
		{
			for(int j=0; j<size_of_array; j++)
			{
                /*bool a=(rand()%(2));*/
                int a = rand()%2;
                map[i][j]=a ;
			}
		}
	}

	Mine(int** p, int m)
	{
		 size_of_array=m;

		map = new bool*[size_of_array];
		for(int n=0; n< size_of_array; n++)
			map[n] = new bool[size_of_array];

		for(int i=0; i<size_of_array; i++)
		{
			for(int j=0; j<size_of_array; j++)
			{
                /*bool a=(rand()%(2));*/
                
                map[i][j] = p[i][j];
			}
		}
	}






	int can_solve(Miner man, mine_index starting_point, mine_index ending_point);
	int zero_it(int x1, int y1);
	int can_solve2(Miner man, int x1, int y1, int x2, int y2);


};
