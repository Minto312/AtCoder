#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vv vector<vector<

int main(){
    int N,limit_weight;
    cin >> N >> limit_weight;

    vv<ll> items(N,vector<ll>(2));
    for (int i=0;i<N;i++){
        cin >> items[i][0] >> items[i][1]; // weight, value
    }

    vector<ll> dp(limit_weight+1,0);
    for (int i=0;i<N;i++){
        for (int j=limit_weight;j>0;j--){
            if (j-items[i][0] < 0) break;
            dp[j] = max(dp[j],dp[j-items[i][0]] + items[i][1]);
        }
    }
    for (auto& x : dp){
        if (x > max) max = x;
    }
    cout << x;
    return 0;
}