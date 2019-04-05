#include <iostream>
#include <unordered_map>

using namespace std;
//LSS with no duplicates

int LSS(string str)
{
	if (str.size() < 1){return 0;}
	unordered_map<char, int> hash;
	int p = 0, q = 0;
	int ans = 0;
	int n = str.size();
	while(p < n && q < n)
	{
		if(hash.find(str[q]) == hash.end())
		{
			hash[str[q]] = 1;
			q++;
		}
		else
		{
			hash.erase(str[p]);
			p++;
		}
		ans < (q-p) ? ans = (q-p) : ans = ans;
	}
	return ans;
}


int main()
{
	string str = "ABCBDEF";
	cout << LSS(str) << endl;
	return 0;
}
