#include <iostream>
#include <vector>
using namespace std;

vector<int> maxset(vector<int> &A) {
	double max = 0;
	double maxI= 0;
	double maxJ= 0;
	double i = 0;
	double j = 0;
	double m = 0;
	A.push_back(-1);


	for(int k = 0; k < A.size(); k++)
	{
		if(m + A[k] >= m)
		{
			j = k;
			m = m + A[k];
		}
		else if((m + A[k] < m) )//|| k == A.size()-1)
		{
			if(m > max)
			{
				cout << "Here: " << " "<< i << " "<< j << " " << m<<endl; 
				maxI = i;
				maxJ = j;
				max = m;
				m = 0;
			}
			else if(m == max)
			{
				if((j-i) > (maxJ-maxI))
				{
					maxI = i;
					maxJ = j;
					max = m;
					m = 0;
				}

			}
			if (m < max)
			{
				m = 0;
			}
			i = k + 1;
			j = i;
		}
	}

	vector<int> ans = {};
	if(A[maxI] < 0){return ans;}
	for(int k = maxI; k <= maxJ; k++)
	{
		ans.push_back(A[k]);
	}
	return ans;
}


int main()
{
	// vector<int> A = {24831, 53057, 19790, -10679, 77006, -36098, 75319, -45223, -56760, -86126, -29506, 76770, 29094, 87844, 40534, -15394, 18738, 59590, -45159, -64947, 7217, -55539, 42385, -94885, 82420, -31968, -99915, 63534, -96011, 24152, 77295 };
	vector<int> A = {72, 5, 1, -1, 77, -3, 73};
	auto B = maxset(A);
	for(auto i: B){
		cout << i << " ";
	}cout << endl;
	return 0;
}