#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


void nextPermutation(vector<int> &A) {
	int a = -1;
	int b = -1;
    for(int i = A.size()-1; i >= 0; i--)
    {
    	for(int j = i; j >=0; j--)
    	{
    		if(A[j] < A[i])
    		{
    			if(j > b){
    				b = j;
    				a = i;
    			}
    		}
    	}
    }

    if(a == -1)
    {
    	sort(A.begin(), A.end());
    	return;
    }


    int temp = A[a];
    A[a] = A[b];
    A[b] = temp;


    if((a - b > 1) || a < A.size()-1)
    {
    	sort(A.begin() + b +1, A.end());
    }

}

int main()
{
	vector<int> A = {1, 2, 3};
	nextPermutation(A);
	for(auto i: A)
	{
		cout << i << " ";
	}cout << endl;
	return 0;
}