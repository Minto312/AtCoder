#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vv vector<vector


int main(){
    int N,max_weight;
    cin >> N >> max_weight;

    vv<ll>> items(N,vector<ll>(2)); // 0: wheight  1:value
    for (int i=0;i<N;i++){
        cin >> items[i][0] >> items[i][1];
    }

    vector<ll> dp(max_weight+1,0);
    for (int i=0;i<N;i++){
        for (int j=max_weight;j>0;j--){
            if (j-items[i][0] < 0) continue;
            dp[j] = max(dp[j],dp[j-items[i][0]] + items[i][1]);
            // cout <<i << "   "<<j<<"    "<< max(dp[j+items[i][0]],dp[j] + items[i][1]) << endl; //debug
        }
    }

    ll max = 0;
    for (auto& x : dp){
        if (x > max) max = x;
    }
    cout << max;
    return 0;
}