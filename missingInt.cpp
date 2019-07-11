#include <iostream>
#include <vector>
using namespace std;

void print(vector<int> A)
{
    cout << "State: "<< endl;
    for(auto i: A)
    {
        cout << i << " ";
    }cout << endl;
}

void swap(int a, int b, vector<int>& A)
{
    int temp = A[a];
    A[a] = A[b];
    A[b] = temp;
    return;
}

int firstMissingPositive(vector<int> &A) {
    for(int i = 0; i < A.size(); i++)
    {
        while(A[i] != i+1)
        {
            if(A[i] == 0){break;}
            if(A[i] < 1 || A[i] > A.size())
            {
                A[i] = 0;
            }
            else
            {//in rane
            	if(A[i] == A[A[i]-1]){
            		A[i] = 0;
            		break;
            	}
                swap(i, A[i]-1, A);
                // print(A);
            }

        }
    }

    for(int i = 0; i < A.size(); i++)
    {
        if(A[i] == 0){
            return i+1;
        }
    }
    return A.size()+1;
}

int main()
{
    vector<int> A = {1, 1, 1};
    int ans = firstMissingPositive(A);
    cout << "Ans: " << ans << endl;
    return 0;
}