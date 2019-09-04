#include <iostream>

using namespace std;

int main()
{
	int arr[] = {1, 4, 2, 3, 3, 1};
	int size = sizeof(arr)/sizeof(arr[0]);
	
	int ans = 1;

	for(int i = 0; i< size; i++)
	{

		for(int j = i; j< size; j++)
		{
			if(arr[i] == arr[j])
			{
				ans = (j-i + 1) > ans ? (j-i + 1) : ans;
			}
		}
	}
	cout << ans << endl;

	return 0;	
}