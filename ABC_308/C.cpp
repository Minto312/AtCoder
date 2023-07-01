#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(obj) obj.begin(), obj.end()
#define vv vector<vector<


int main(){
    ll N;
    cin >> N;

    vector<pair<ll,long double>> A(N);
    for (ll i=0;i<N;i++){
        A[i].first = i+1;
        long double success, fail;
        cin >> success >> fail;
        // cout << success / (success + fail) << endl; //debug
        A[i].second = success / (success + fail);
    }

    sort(all(A),[](auto &x, auto &y){if (x.second != y.second)return x.second > y.second;
    else return x.first < y.first;});

    for (pair<ll,long double> x : A){
        cout << x.first << " ";
    }
    return 0;
}