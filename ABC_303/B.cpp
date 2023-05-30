#include <bits/stdc++.h>
using namespace std;
#define vv vector<vector
#define rep(i,s,e) for(int i = s;i < e;i++)
#define all(obj) obj.begin(),obj.end()


int main(){
    int N,M;
    cin >> N >> M;

    vv<bool>> is_discord(N+1,vector<bool>(N+1,true));
    vector<int> t(N+1);
    rep(i,0,M){
        cin >> t[0];
        rep(j,1,N){
            cin >> t[j];

            if (t[j-1] < t[j]){
                is_discord[t[j-1]][t[j]] = false;
            }else{
                is_discord[t[j]][t[j-1]] = false;
            }
        }
        t.clear();
    }

    int count = 0;
    rep(i,1,N+1){
        for (int j = N+1;j > i;j--){
            if (is_discord[i][j]) count++;
        }
    }
    cout << count << endl;
}