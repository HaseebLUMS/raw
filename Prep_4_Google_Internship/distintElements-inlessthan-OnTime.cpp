#include <iostream>

using namespace std;

vector<int> distinct(vector<int>& vec, int l, int r){
	
}

int main()
{
	vector<int> vec = {1, 1, 1, 2, 2, 2};
	auto ans = distinct(vec, 0, vec.size()-1);
	cout << "Answer: ";
	for(auto i: ans){
		cout << i << " ";
	}cout << endl;
	return 0;
}