#include <iostream>
#include <vector>
#include <map>

using namespace std;

vector<int> BS(vector<int> A,int B)
{
	int l = 0, r = A.size()-1;
	int ans_left = -1;
	while(l <= r)
	{
		int mid = l + ((r-l)/2);
		if(A[mid] == B){ans_left = mid; r = mid-1;}
		else if (A[mid] < B){l = mid+1;}
		else{r = mid-1;}
		
	}

	l = 0, r = A.size()-1;
	int ans_right = -1;
	while(l <= r)
	{
		int mid = l + ((r-l)/2);
		if(A[mid] == B){ans_right = mid; l = mid + 1;}
		else if (A[mid] < B){l = mid+1;}
		else{r = mid-1;}
		
	}

	return {ans_left, ans_right};
}


int main()
{
	vector<int> A = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10 };
	int B = 8;
	auto ans = BS(A, B);
	cout << ans[0] << ans[1] << endl;
	return 0;
}