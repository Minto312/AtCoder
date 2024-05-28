#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) (x).begin(), (x).end()

int main(){
    int N,M;
    cin >> N >> M;

    vector<bool> is_winner(N+1,true);
    set<int> looser;
    vector<pair<int,int>> vec(M);

    for (int i=0;i<M;i++){
        int a,b;
        cin >> a >> b;
        vec[i] = make_pair(a,b);
        is_winner[b] = false;
        looser.insert(b);
    }

    bool is_changed = true;
    while (is_changed){
        is_changed = false;
        for (auto& x : vec){
            if (looser.find(x.first) != looser.end()){
                is_winner[x.first] = false;
                if (looser.find(x.first) == looser.end()){
                    looser.insert(x.first);
                    is_changed = true;
                }
            }
        }
    }

    int winner = 0;
    for (int i=1;i<=N;i++){
        if (winner != 0 && is_winner[i]){
            cout << -1 << endl;
            return 0;
        }
        if (is_winner[i]) winner = i;
    }
    cout << winner << endl;
    return 0;
}