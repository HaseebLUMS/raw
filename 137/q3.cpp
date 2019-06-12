#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <vector>

using namespace std;
/*

Given a list of words, each word consists of English lowercase letters.

Let's say word1 is a predecessor of word2 if and only if we can add exactly one letter anywhere in word1 to make it equal to word2.  For example, "abc" is a predecessor of "abac".

A word chain is a sequence of words [word_1, word_2, ..., word_k] with k >= 1, where word_1 is a predecessor of word_2, word_2 is a predecessor of word_3, and so on.

Return the longest possible length of a word chain with words chosen from the given list of words.

 

Example 1:

Input: ["a","b","ba","bca","bda","bdca"]
Output: 4
Explanation: one of the longest word chain is "a","ba","bda","bdca".
 */

bool in(string a , string b){
	if(a.length() + 1 != b.length()){return false;}
	int arr[255] = {0};
	for(int i = 0; i < b.length(); i++)
	{
		arr[b[i]] = 1;
	}

	bool ans = true;
	for(int i = 0; i < a.length(); i++)
	{
		if(arr[a[i]] != 1){ans = false;}
	}
	return ans;
}

int longestStrChain(vector<string>& words) {
	int maxInt = 0;
	int minInt = 100000;
	map<int, vector<string> > m;
	for(auto i : words)
	{
		if(i.length() > maxInt){maxInt = i.length();}
		if(i.length() < minInt){minInt = i.length();}

		if(m.find(i.length()) != m.end()){
			m[i.length()].push_back(i);
		}
		else{
			vector<string> v = {i};
			m[i.length()] = v;
		}
	}

	map<string, int> m2;
	auto v2 = m[maxInt];
	for(auto v2e : v2)
	{
		m2[v2e] = 1;
	}


	int ans = 1;
	for(int i = maxInt-1; i >= minInt; i--)
	{
		// if(m.find(i) == m.end()){continue;} //focus later
		vector<string> vec1 = m[i+1];
		vector<string> vec2 = m[i];

		for(auto k : vec2)
		{
			for(auto l : vec1)
			{
				if(in(k, l)){
					if(m2.find(k) != m2.end())
					{
						m2[k] = max(m2[k], m2[l] + 1);
						if(m2[k] > ans){ans = m2[k];}
					}
					else{
						m2[k] = m2[l] + 1;
						if(m2[k] > ans){ans = m2[k];}
					}
				}
				else{
					if(m2.find(k) == m2.end()){m2[k] = 1;}
				}
			}
		}
	}



	return ans;
}

int max(int a, int b){return a > b? a : b;}

int main()
{
	// vector<string> a = {"sgtnz","sgtz","sgz","ikrcyoglz","ajelpkpx","ajelpkpxm","srqgtnz","srqgotnz","srgtnz","ijkrcyoglz"};
	vector<string> a = {"ksqvsyq","ks","kss","czvh","zczpzvdhx","zczpzvh","zczpzvhx","zcpzvh","zczvh","gr","grukmj","ksqvsq","gruj","kssq","ksqsq","grukkmj","grukj","zczpzfvdhx","gru"};
	cout << longestStrChain(a) << endl;
	return 0;
}