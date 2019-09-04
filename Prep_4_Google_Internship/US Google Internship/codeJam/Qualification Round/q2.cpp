#include <iostream>

using namespace std;

int main()
{
    int t = 0;
    cin >> t;
    for(int i = 0; i< t; i++)
    {
        int dem = 0; cin >> dem;
        string p = ""; cin >> p;
        string pp = "";
        for(int k = 0; k< p.length(); k++)
        {
            if(p[k] == 'E'){pp += "S";}
            else {pp += "E";}
        }
        cout << "Case #" << i+1 << ": " << pp << endl;
    }
    return 0;
}