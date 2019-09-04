#include <iostream>

using namespace std;
int max(int i, int j){return i >= j ? i : j;}

int main()
{
    int t = 0;
    cin >> t;
    for(int i = 0; i< t; i++)
    {
        int n = 0;
        cin >> n;
        string wall = "";
        cin >> wall;
        int ans = -1;
        int mid = (n+1)/2;
        int tot = 0;
        for(int j = 0; j <  n; j++)
        {
            tot += (wall[j] - '0');
            if (j >= mid   ){tot -= (wall[j - mid] - '0');}
            if (j+1 >= mid){ans = max(ans, tot);}
        }
        cout << "Case #" << i+1<< ": " << ans << endl;
    }
    return 0;
}