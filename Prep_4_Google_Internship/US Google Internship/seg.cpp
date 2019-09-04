#include <iostream>

using namespace std;

void createSegmentTree(int* arr, int* segmentTree, int st, int en, int ind)
{
	if(st == en)
	{
		segmentTree[ind] = arr[st];
		return;
	}

	int mid = (st + en + 0.5)/2;

	createSegmentTree(arr, segmentTree, st, mid, 2*ind);
	createSegmentTree(arr, segmentTree, mid+1, en, 2*ind + 1);

	segmentTree[ind] = segmentTree[2*ind] + segmentTree[2*ind + 1];
	return;
}

int main(){
	int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int size = 1;
	for(; size < 10; size <<= 1);

	int segmentTree[2*size];
	for(int i = 0; i < 2*size; i++){segmentTree[i] = 0;}

	createSegmentTree(arr, segmentTree, 0, 9, 1);

	for(int i = 1; i < 2*size; i++)
	{
		cout << segmentTree[i] << " ";
	}cout << endl;
	return 0;
}