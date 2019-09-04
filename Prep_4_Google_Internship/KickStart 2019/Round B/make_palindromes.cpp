#include <iostream>
#include <map>
using namespace std;

int main()
{
	int t = 0;
	cin >> t;
	for(int tt = 0; tt < t; tt++)
	{
		int N = 0, Q = 0;
		cin >> N >> Q;
		string str = ""; cin >> str;
		int ans = 0;
		for(int i = 0; i < Q; i++)
		{
			int a = 0, b = 0;
			cin >> a >> b;
			map<char, int> m;
			string s = str.substr(a-1, b-a+1);
			for(int k = 0; k < s.length(); k++)
			{
				if(m.find(s[k]) == m.end())
				{
					m[s[k]] = 1;
				}
				else
				{
					m[s[k]] += 1;
				}
			}
			bool tmp = true;
			int of = 0;
			for(auto k: m)
			{
				if(s.length() % 2 == 0) //even
				{
					if(k.second % 2 != 0){tmp = false;}
				}
				else
				{
					if(k.second % 2 != 0){of++;}
					if(of > 1){tmp = false;}
				}
			}
			if(tmp){ans++;}

		}
		cout << "Case #" << tt+1 << ": " <<  ans << endl;
	}
}