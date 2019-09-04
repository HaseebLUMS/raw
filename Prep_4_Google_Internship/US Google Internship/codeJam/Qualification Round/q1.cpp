#include <iostream>
#include <string>

using namespace std;

int main()
{
    int t = 0; cin >> t;
    for(int i = 0; i < t; i++)
    {
        long long int num = 0;
        cin >> num;
        string dum = to_string(num);
        string str1 = "";
        string str2 = "";
        
        for(int k = 0; k< dum.length(); k++)
        {
            if(dum[k] == '4')
            {
                str1 += "2";
                str2 += "2";
            }
            else
            {
                str1 += dum.substr(k, 1);
                str2 += "0";
            }
        }
        cout << "Case #" << i+1 << ": " << stoll(str1, nullptr, 10) << " " << stoll(str2, nullptr, 10) << endl;
        
    }
    return 0;
}