#include <bits/stdc++.h>
using namespace std;
#define loop(n) for(int i = 0;i < n;i++)
#define rep(i,n) for(int i = 0;i < n;i++)

int main(){
    long long hp,attack,count;
    cin >> hp >> attack;

    count = hp / attack;
    if (hp % attack != 0) count++;
    cout << count;
    // cin >> hp;
}