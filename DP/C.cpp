#include <bits/stdc++.h>
using namespace std;
#define vv vector<vector
 
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
 
    vv<int>> dp(N,vector<int>(3,0));
    dp[0][0] = a[0];
    dp[0][1] = b[0];
    dp[0][2] = c[0];
    char prev_char;
    char temp_char;
    for (int i=1;i<N;i++){
        chmax(dp[i][0],max(dp[i-1][1] + a[i],dp[i-1][2] + a[i])); //a

        chmax(dp[i][1],max(dp[i-1][0] + b[i],dp[i-1][2] + b[i])); //b

        chmax(dp[i][2],max(dp[i-1][0] + c[i],dp[i-1][1] + c[i])); //c
    }
    cout << max({dp[N-1][0],dp[N-1][1],dp[N-1][2]});
    return 0;
}