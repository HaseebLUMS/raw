#include <iostream>

using namespace std;


string solution(string &S, int K) {
    // write your code in C++14 (g++ 6.2.0)
    int t = 0;
    string tmp = S;
    for(int i = 0; i< S.length(); i++){
        if(S[i] == '-'){t++;}
    }
    
    char arrS[S.length()-t];
    int c = 0;
    for(int i = 0; i < S.length(); i++){
        if(tmp[i] != '-'){
            if(tmp[i] >= 97 && tmp[i] <= 122){tmp[i] -= 32;}
            arrS[c++] = tmp[i];
        }
    }
    string target = "";
    int k = K;
    for(int i = c-1; i>= 0; i--){
        target = arrS[i]+ target;
        k--;
        if(k == 0 && i > 0){
            
            target = "-" + target;
            k = K;
        }
    }
    return target;
}


int main(){
    string test = "q-w123QW";
    cout << solution(test, 2) << endl;
}