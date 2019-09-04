#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

int* memo;
pair<bool, vector<string> > wb(string A, unordered_set<string> s, int ind)
{
	if(ind >= A.size()){return true;}
	bool ans = false;
	if(memo[ind] == -1)
	{
		for(int i = ind; i < A.size(); i++)
		{
			if(s.find(A.substr(ind, (i-ind+1))) != s.end())
			{
				auto p = wb(A, s, i+1);
				if(p.first){ans = true;}
			}
		}
		memo[ind] = ans;

	}
	else{
		ans = memo[ind];
	}

	return ans;
}

int wordBreak(string A, vector<string> &B) {
	memo = new int[A.size()+1];
	for(int i = 0; i < A.size()+1; i++)
	{
		memo[i] = -1;
	}
    unordered_set<string> s;
    for(auto b: B){s.insert(b);}
    return wb(A, s, 0);
    return 0;
}


int main()
{
	//vector<string> vec = {"bbba", "aaaa", "abaa", "aba", "aabaaa", "baabbaab", "bbbabbbaaa", "abaabbbbba", "abaa", "aba", "bbabbbbabb", "aab", "baaabbbaaa", "b", "baba", "aaba", "baaba", "abb", "aaaa", "baaabbbaa", "ab"};

	//cout << wordBreak("babbbbaabbaabaabaabaaabaababaaaabbbbbabbaabbabbbbababaabbabbbabbbaaabaababaaaababbbbabbbbbbaaaabaaabaabbbaaaabaaabbbaabababbbaaaabbabbbabaaabbbabaaabbbaaaaaabaabbabbaabbbbbaababbbbabbabbaabbbabaababaaaabbaabbbaabaabbbbbbaabbbaaaabbaaaaaabaabbaababbbabbbbbbaabbaabbbabbbaabbbaaaabbbaaaabbbabbaababaaabbababbaabbabbabaabbbbaaaabbaababababbbbbabbbbabbaaabbaabaaaaabbaaaaaaaaaaababaaabbbaababbbbbbbabbababbaabbaaaababbbabbaaabbbbbabbbaabbaaaaabbbbbbabbbbbabbabbbabbabbababbabaabaabbabababbababaababbaababbabaabbaaaabbbaa", vec) << endl;
	vector<string> vec = {"a", "aab", "aaa"};
	cout << wordBreak("aabaaaa", vec) << endl;
	return 0;
}