#include <iostream>
#include <algorithm>

using namespace std;


int editDistance(string a, string b, int na, int nb)
{
	//if same:
	// do nothing and advance
	//if not same:
	// then do ops and choose minimum
	//ops:
	//	replace (not relevant here)
	//	cut
	//	add
	
	if(na < 0) {
		if(nb >= 0){return nb + 1;}
		return 0;
	}

	if(nb < 0 && na >= 0){return na+1;}

	if(a[na] == b[nb]) {return editDistance(a, b, na-1, nb-1);}

	int cut = 1 + editDistance(a, b, na, nb-1);
	int add = 1 + editDistance(a, b, na-1, nb);

	return cut < add ? cut : add;
}

int main()
{
	string a = "AAA";
	string b = "ABB";
	int ans = editDistance(a, b, a.length()-1, b.length()-1);
	cout << "Ans: " << ans << endl;
	return 0;
}