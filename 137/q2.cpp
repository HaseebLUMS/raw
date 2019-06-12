#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

/*

Given a string S of lowercase letters, a duplicate removal consists of choosing two adjacent and equal letters, and removing them.

We repeatedly make duplicate removals on S until we no longer can.

Return the final string after all such duplicate removals have been made.  It is guaranteed the answer is unique.

 

Example 1:

Input: "abbaca"
Output: "ca"
Explanation: 
For example, in "abbaca" we could remove "bb" since the letters are adjacent and equal, and this is the only possible move.  The result of this move is that the string is "aaca", of which only "aa" is possible, so the final string is "ca".

 */

string removeDuplicates(string str) {
	stack<char> s;
	s.push(str[0]);
	for(int i = 1; i < str.length(); i++)
	{
		if(!s.empty() && s.top() == str[i]){
			s.pop();
		}
		else{
			s.push(str[i]);
		}
	}

	string ans = "";
	while(!s.empty()){
		ans = s.top() + ans;
		s.pop();
	}

	return ans;
}

int main()
{
	string a = "abbaca";
	cout << removeDuplicates(a) << endl;
	return 0;
}