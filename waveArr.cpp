#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> wave(vector<int> &A) {
	sort(A.begin(), A.end());

	for(int i = 0; i < A.size(); i++)
	{
		if(i%2 !=0)
		{
			int tmp = A[i-1];
			A[i-1] = A[i];
			A[i] = tmp;
		}
	}

	return A;
}

int main()
{
	vector<int> A = {1, 2, 3, 4, 5};
	auto ans = wave(A);
	for(auto i: ans)
	{
		cout << i << " ";
	}cout << endl;
	return 0;
}