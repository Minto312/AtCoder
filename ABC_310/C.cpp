#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) (x).begin(), (x).end()

int main(){
    int N;
    cin >> N;

    set<string> unique_str;
    for (int i=0;i<N;i++){
        string s;
        cin >> s;
        if (s[0] > s[s.size()-1]){
            reverse(all(s));
        }
        unique_str.insert(s);
    }

    
}