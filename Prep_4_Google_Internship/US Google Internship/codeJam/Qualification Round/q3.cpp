#include <bits/stdc++.h> 
#include <unordered_map>
using namespace std; 

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
		int limit = 0;
		cin >> limit;
		

		int n = 0;
		cin >> n;
		int cipher[n];
		for(int i = 0; i< n; i++){cin >> cipher[i];}

		vector<int> ans;
		vector<pair<int, int>> ans2; //prime, index in input
		
		int f = memo[cipher[0]].first;
		int s = memo[cipher[0]].second;
		int ff = memo[cipher[1]].first;
		int ss = memo[cipher[1]].second;
		int last = ss;

		if(f == ff)
		{
			ans.push_back(s); ans.push_back(f); ans.push_back(ss); last = ss;
			//ans2[s] = 0; ans2[f] = 1; ans2[ss] = 2;
			ans2.push_back(make_pair(s, 0));
			ans2.push_back(make_pair(f, 1));
			ans2.push_back(make_pair(ss, 2));
		}
		else if(f == ss)
		{
			ans.push_back(s); ans.push_back(f); ans.push_back(ff); last = ff;
			//ans2[s] = 0; ans2[f] = 1; ans2[ff] = 2;
  			ans2.push_back(make_pair(s, 0));
  			ans2.push_back(make_pair(f, 1));
  			ans2.push_back(make_pair(ff, 2));
		}
		else if(s == ff)
		{
			ans.push_back(f); ans.push_back(s); ans.push_back(ss); last = ss;
			//ans2[f] = 0; ans2[s] = 1; ans2[ss] = 2;
			ans2.push_back(make_pair(f, 0));
			ans2.push_back(make_pair(s, 1));
			ans2.push_back(make_pair(ss, 2));
		}
		else if(s == ss)
		{
			ans.push_back(f); ans.push_back(s); ans.push_back(ff); last = ff;
			//ans2[f] = 0; ans2[s] = 1; ans2[ff] = 2;
			ans2.push_back(make_pair(f, 0));
			ans2.push_back(make_pair(s, 1));
			ans2.push_back(make_pair(ff, 2));
		}

		int ind = 3;
		for(int i = 2; i< n; i++)
		{
			f = memo[cipher[i]].first;
			s = memo[cipher[i]].second;

			if(f == last)
			{
				ans.push_back(s); last = s;
				//ans2[s] = ind++;
				ans2.push_back(make_pair(s, ind++));
			}
			else 
			{
				ans.push_back(f); last = f;
				//ans2[f] = ind++;
				ans2.push_back(make_pair(f, ind++));
			}
		}


	    sort(ans2.begin(), ans2.end());
		int size = ind-1;
		//for(auto i: ans2){cout << i.first << " " << i.second << endl;}
		
		vector<char> final(ans2.size(), '-');
		unordered_set<int> us;
		int term = 0;
		unordered_map<int, char> charAssign;
		for(int i = 0; i< ans2.size(); i++)
		{
			if(us.find(ans2[i].first) == us.end())
			{
				final[ans2[i].second] = term + 65;
				charAssign[ans2[i].first] = term +65;
				us.insert(ans2[i].first);
				term++;
			}
			else
			{
				final[ans2[i].second] = charAssign[ans2[i].first];
			}
			//cout << final[ans2[i].second] ;
		}

		cout << "Case #" << tt+1 << ": ";
		for(auto i: final)
		{	
			if(i != '-'){
				cout << i ;
			}
		}cout << endl;
	}
	return 0; 
} 
