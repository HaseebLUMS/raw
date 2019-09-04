#include <iostream>
#include <vector>

using namespace std;

void pretify(int A, int row, vector<vector<int> > ans, vector<int>& tmp)
{
    if(row == 0)
    {
        for(int i = 0; i < 2*A - 1; i++)
        {
            tmp.push_back(A);
        }
        return;
    }
    
    auto prev = ans[row-1];
    // cout << "For " << row << " Prev" << endl;
    // for(auto i : prev){cout << i << " ";}cout << endl;
    
    for(int i = 0; i < 2*A - 1; i++)
    {
        int to_push = prev[i];
        if(i >= row && i < (2*A-1)-row)
        {
            to_push = to_push - 1;
        }
        tmp.push_back(to_push);
    }
    
    return;
}

vector<vector<int> > prettyPrint(int A) {
    vector<vector<int> > ans;
    for(int i = 0; i < A; i++)
    {
        vector<int> tmp;
        pretify(A, i, ans, tmp);
        // cout << "For " << i << " :" << endl;
        // for(auto k : tmp){cout << k << " ";}cout << endl;
        ans.push_back(tmp);
    }
    
    
    for(int i = A; i < 2*A - 1; i++)
    {
        vector<int> tmp;
        for(int j = 0; j < 2*A - 1; j++)
        {
            tmp.push_back(ans[(2*A-1) - i-1][j]);
        }
        ans.push_back(tmp);
    }
    
    return ans;
}

int main()
{
	int A = 0;
	auto ans = prettyPrint(A);
	for(auto i : ans)
	{
		for(auto j : i)
		{
			cout << j << " ";
		}
		cout << endl;
	}
	return 0;
}