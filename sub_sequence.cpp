#include <iostream>

using namespace std;

// A larger, b smaller
bool LSS(string a, string b)
{
	if(b == "")
	{return true;}
	if(a == "")
	{return false;}

	if(a[0] == b[0])
	{return LSS(a.substr(1), b.substr(1));}
	else 
	{return LSS(a.substr(1), b);}
}

int main()
{
	string S = "abppplee";
	string D[5] = {"able", "ale", "apple", "bale", "kangaroo"};
	string ans = "";
	for(auto i: D)
	{
		if(LSS(S, i)){ans = ans.size() < i.size() ? i : ans;}
	}

	cout << ans << endl;
	return 0;
}