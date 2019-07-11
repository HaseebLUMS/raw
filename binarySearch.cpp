#include <iostream>

using namespace std;

int BinarySearch(int *arr, int n, int t) {
	int l = 0, r = n;
	while ( l < r ) {
		int mid = l + (r-l)/2;
		if ( arr[mid] >= t )
			r = mid;
		else
			l = mid + 1;
	}
	return l;
}


int BinarySearch(int* arr, int s, int num, int prefix){
	int mid = s/2;
	if(s%2){mid+=1;}
	if(s <= 1){if(arr[mid] == num){return prefix + mid;}return -1;}
	if(arr[mid] == num){return prefix + mid;}
	else{
		if(arr[mid] < num){return BinarySearch(arr+mid, s-mid, num, mid);}
		else{return BinarySearch(arr, mid, num, prefix);}
	}
}


int main()
{
	int s = 6;
	int arr[6] = {1, 20, 30, 40, 50};
	cout << BinarySearch(arr, s, 66, 0) << endl;

	return 0;
}