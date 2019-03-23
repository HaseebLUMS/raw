#include <iostream>
using namespace std;

int main()
{
	int arrival[5]   = {1, 3, 3, 5, 9};
	int departure[5] = {2, 7, 7, 6, 11};

	//merge => [1A, 2D, 3A, 3A, 4D, 5A, 6D, 7D, 9A, 11D]

	int total_log = 0;
	int max = 0;
	int i = 0, j = 0;
	while(i < 5 && j < 5)
	{
		if(arrival[i] < departure[j])
		{
			total_log++;
			i++;
		}
		else
		{
			total_log--;
			j++;
		}


		total_log > max ? max = total_log : max = max;
	}

	cout << max << endl;
	return 0;
}