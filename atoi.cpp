#include <iostream>
#include <limits.h>
using namespace std;

int atoi1(const string A) {
    string cleanString = "";
    bool isMinus = false;
    
    for(int i = 0; i < A.size(); i++)
    {
        if((A[i] == '+')&& (i == 0)){continue;}
        if((A[i] - '0' < 0 || A[i] - '0' > 9) && A[i] != '-'){break;}
        if((i != 0) && A[i] == '-'){break;}
        if(A[i] == '-'){isMinus = true; continue;}
        cleanString += string(1, A[i]);
    }
    int ans = 0;
    int unit = 1;
    for(int i = cleanString.size()-1; i >= 0; i--)
    {
        int temp = ((cleanString[i] - '0')*unit);
        ans += temp;
        // cout << ans << endl;
        int oldUnit = unit;
        unit *= 10;
        if(temp < 0 || ans < 0 || unit < 0){return isMinus ? INT_MIN : INT_MAX;}

        if(unit / 10 != oldUnit){return isMinus ? INT_MIN : INT_MAX;}
    }
    
    return isMinus ? -1*ans : ans;
}

int main()
{
    
    string a = "5121478262";
    cout << "Answer: " << atoi1(a) << endl;
    return 0;
}