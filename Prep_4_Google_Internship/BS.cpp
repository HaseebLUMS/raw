#include <iostream>
using namespace std;
int BS(int* arr, int n, int t);
int main()
{
	int arr[6] = {10, 20, 30, 40, 50, 60};
	cout << BS(arr, 6, 61) << endl;
	return 0;
}

int BS(int* arr, int n, int t)
{
	int l = 0, r = n;
	while(l <= r)
	{
		int mid = l + ((r-l)/2);
		if(arr[mid] == t){return mid;}
		else if (arr[mid] < t){l = mid+1;}
		else{r = mid-1;}
		
	}
	return -1;
}
