#include <iostream>
#include <stack>
using namespace std;


bool isRedundant(string str)
{
	if(str == "()"){return true;}
	stack<int> s;
	int c = 0;
	int prev = -1;
	for(auto i: str)
	{
		if(i == '('){s.push(c);}
		else if(i == ')')
		{
			if(s.top() == prev){return true;}
			prev = s.top();
			s.pop();
		}
		else{
			c++;
		}
	}
	return false;
}

int main()
{
	string str = "()";
	cout << isRedundant(str) << endl;
	return 0;
}



 