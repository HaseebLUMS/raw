#include <iostream>
#include <algorithm>
#include <vector>
#include <map>


using namespace std;

vector<int> prevPermOpt1(vector<int>& A) {
    
    map<int, vector<int> > m;
    for(int i = 0; i < A.size(); i++)
    {
        if(m.find(A[i]) == m.end())
        {
            m[A[i]] = {i};
        }
        else{
            m[A[i]].push_back(i);
        }
    }
    
    for(auto i : m)
    {
        sort(i.second.begin(), i.second.end());
    }
    
    // for(auto i : m)
    // {
    //     cout << i.first << " : ";
    //     for(auto j : i.second){
    //         cout << j << " ";
    //     }
    //     cout << endl;
    // }

    for(int i = A.size()-1; i >= 0; i--)
    {
    	auto t = m.find(A[i]);
    	auto tt = t->second[t->second.size()-1]; 
    	if(++t == m.end()){continue;}
    	auto v = t->second;

    	int vk = 0;
    	for(int k = v.size()-1; k >= 0; k--)
    	{
    		if(v[k] < tt){vk = v[k];break;}
    	}
    	int temp = A[tt];
    	A[tt] = A[vk];
    	A[vk] = temp;
    	break;
    }
    
    return A;
}
int main()
{
	vector<int> v = {1, 1, 5};
	auto vv = prevPermOpt1(v);
	for(auto i : vv){cout << i << " ";}cout << endl;
	return 0;
}