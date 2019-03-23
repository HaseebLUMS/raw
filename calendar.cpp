#include <iostream>
#include <map>
#include <set>
#include <vector>

using namespace std;

struct compare {
    bool operator()(const pair<int, int>& lhs, const pair<int, int>& rhs) {
        return lhs.first < rhs.first;
    }
};

class MyCalendarTwo {
public:
    multimap<int, int> m;
    bool a;
    MyCalendarTwo() {
        a = true;
    }
    
    bool book(int start, int end) {
        vector<int> arrival;
        vector<int> departure;

        multiset<pair<int, int>, compare> ms;// = new multiset<pair<int, int>, compare>;
        multimap<int, int>::iterator it;


        for(auto elem: m)
        {
            int s = elem.first, e = elem.second;
            ms.insert(make_pair(s, e));
        }

        ms.insert(make_pair(start, end));

        for (auto elem: ms)
        {
            arrival.push_back(elem.first);
            departure.push_back(elem.second);
        }

        bool v = valid(arrival, departure, arrival.size(), departure.size());
        if(v){m.insert(make_pair(start, end));return true;}
        return false;
    }

    bool valid(vector<int> arrival, vector<int> departure, int a, int d)
    {
        int total_log = 0;
        int max = 0;
        int i = 0, j = 0;
        while(i < a && j < d)
        {
            //if(arrival[i] == departure[j]){i++; j++;}
            if(arrival[i] < departure[j])
            {
                total_log++;
                i++;
            }
            else
            {
                total_log--;
                j++;
            }
            max = total_log > max ? total_log : max;
        }

        if(max >= 3){cout << "Failed" << endl; return false;}
        cout << "Success" << endl;
        return true;
    }
};

int main()
{
    MyCalendarTwo* mc = new MyCalendarTwo();
    mc -> book(10, 20);
    mc -> book(50, 60);
    mc -> book(10, 40);
    mc -> book(5, 15);
    mc -> book(5, 10);
    mc -> book(25, 55);
    return 0;
}