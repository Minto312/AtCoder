#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define all(x) x.begin(),x.end()

int main(){
    int N;
    string str;
    cin >> N >> str;

    bool found_A = false, found_B = false, found_C = false;
    for (int i=0;i<N;i++){
        if (str[i] == 'A') found_A = true;
        if (str[i] == 'B') found_B = true;
        if (str[i] == 'C') found_C = true;

        if (found_A && found_B && found_C){
            cout << i+1;
            return 0;
        }
    }
}