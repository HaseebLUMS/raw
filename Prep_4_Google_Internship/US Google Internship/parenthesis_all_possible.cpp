#include <iostream>
#include <vector>

using namespace std;

vector<string> ans;

void parens(int l, int r, string str)
{
	if(l <= 0 && r <= 0){ans.push_back(str); return;}

	if(l > 0){parens(l-1, r+1, str + "(");}
	if(r > 0){parens(l, r-1, str + ")");}

}

int main()
{
	parens(5, 0, "");
	for(auto i: ans)
	{
		cout << i << endl;
	}
}
