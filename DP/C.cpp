#include <bits/stdc++.h>
using namespace std;
 
bool chmax(int& bef,int aft){
    if (aft > bef){
        bef = aft;
        return true;
    }
    return false;
}
 
int main(){
    int N;
    cin >> N;
 
    vector<int> a(N);
    vector<int> b(N);
    vector<int> c(N);
 
    for (int i=0;i<N;i++){
        cin >> a[i] >> b[i] >> c[i];
    }
 
    vector<int> dp(3,0);
    char prev_char;
    char temp_char;
    for (int i=0;i<N;i++){
        chmax(dp[0],dp[0] + b[i]); //直前がa
        chmax(dp[0],dp[0] + c[i]);

        chmax(dp[1],dp[1] + a[i]); //直前がb
        chmax(dp[1],dp[1] + c[i]);

        chmax(dp[2],dp[2] + a[i]); //直前がc
        chmax(dp[2],dp[2] + b[i]);
    }
    cout << max(dp[0],dp[1],dp[2]);
    return 0;
}