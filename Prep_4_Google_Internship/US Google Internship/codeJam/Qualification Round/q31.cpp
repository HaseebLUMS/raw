#include <iostream>
#include <bits/stdc++.h> 

using namespace std;

int SieveOfAtkin(int limit, vector<int>& primes);

int main()
{
	vector<int> primes; 
	SieveOfAtkin(10000+1, primes);
	unordered_map<int, pair<int, int>> memo;
	for(auto i: primes)
	{
		for(auto j: primes)
		{
			memo[(i) * (j)] = make_pair(i, j);
		}
	}

	int t = 0; cin >> t;
	for(int tt = 0; tt < t; tt++)
	{
		int n = 0;
		cin >> n;


		int l = 0;
		cin >> l;
		int cipher[l];
		for(int i = 0; i< l; i++){cin >> cipher[i];}

		multimap<int, int> um; //prime, index in input
		unordered_map<int, int> rum;//index in input, prime
		vector<int> pp;



		int f = memo[cipher[0]].first;int s = memo[cipher[0]].second;
		if(l == 1)
		{
			if(f == s){
				cout << "Case #" << tt+1 << ": " << "A" << " " << "A" << endl;
			}
			else{
				cout << "Case #" << tt+1 << ": " << "A" << " " << "B" << endl;
			}
			continue;
		}
		int ff = memo[cipher[1]].first;int ss = memo[cipher[1]].second;
		int last = ss;

		//cout << cipher[1] << " -- " << ff << " " << ss << endl;

		if(f == ff)
		{
			um.insert(make_pair(s, 0));
			um.insert(make_pair(f, 1));
			um.insert(make_pair(ss, 2));
		

			rum[0] = s; rum[1] = f; rum[2] = ss;
			last = ss;
		}
		else if(f == ss)
		{
			um.insert(make_pair(s, 0));
			um.insert(make_pair(f, 1));
			um.insert(make_pair(ff, 2));
			

			rum[0] = s; rum[1] = f; rum[2] = ff;
			last = ff;
		}
		else if(s == ff)
		{
			um.insert(make_pair(f, 0));
			um.insert(make_pair(s, 1));
			um.insert(make_pair(ss, 2));
			

			rum[0] = f; rum[1] = s; rum[2] = ss;
			last = ss;
		}
		else if(s == ss)
		{
			um.insert(make_pair(f, 0));
			um.insert(make_pair(s, 1));
			um.insert(make_pair(ff, 2));


			rum[0] = f; rum[1] = s; rum[2] = ff;
			last = ff;
		}

		int ind = 3;
		for(int i = 2; i< l; i++)
		{
			f = memo[cipher[i]].first;
			s = memo[cipher[i]].second;

			if(f == last)
			{
				um.insert(make_pair(s, ind)); pp.push_back(s);
				rum[ind] = s;
				ind++;
				last = s;
			}
			else 
			{
				um.insert(make_pair(f, ind)); pp.push_back(f);
				rum[ind] = f;
				ind++;
				last = f;
			}
		}

		//for(auto i: um){cout << i.first << " ";}cout << endl;

		unordered_map<int, char> charAss;
		int term = 0;
		for(auto i: um)
		{
			if(charAss.find(i.first) == charAss.end())
			{
				charAss[i.first] = term + 65;
				term++;
			}
		}

		cout << "Case #" << tt+1 << ": ";
		for(int i = 0; i< l+1; i++)
		{
			cout << charAss[rum[i]];
		}
		cout << endl;

	}
	return 0;
}


int SieveOfAtkin(int limit, vector<int>& primes) 
{ 
	int ind = 0;
	if(limit > 3)
	{
		primes.push_back(2);
		primes.push_back(3);
	}
	else if(limit > 2)
	{
		primes.push_back(2);
	}


	bool sieve[limit]; 
	for (int i = 0; i < limit; i++) 
		sieve[i] = false; 
	for (int x = 1; x * x < limit; x++) { 
		for (int y = 1; y * y < limit; y++) { 
			
			int n = (4 * x * x) + (y * y); 
			if (n <= limit && (n % 12 == 1 || n % 12 == 5)) 
				sieve[n] ^= true; 

			n = (3 * x * x) + (y * y); 
			if (n <= limit && n % 12 == 7) 
				sieve[n] ^= true; 

			n = (3 * x * x) - (y * y); 
			if (x > y && n <= limit && n % 12 == 11) 
				sieve[n] ^= true; 
		} 
	} 

	for (int r = 5; r * r < limit; r++) { 
		if (sieve[r]) { 
			for (int i = r * r; i < limit; i += r * r) 
				sieve[i] = false; 
		} 
	} 

	for (int a = 5; a < limit; a++) 
	{
		if (sieve[a])
		{
			primes.push_back(a);
		}
	}
} 
