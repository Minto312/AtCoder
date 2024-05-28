#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) (x).begin(), (x).end()
void test(){
    ll N;
    cin >> N;

    vector<ll> A(N);
    for(ll i = 0; i < N; i++){
        cin >> A[i];
    }
    ll ans = 0;
    for (auto x : A){
        ans += x;
    }
    cout << ans << endl;
    ll avg = ans / N;

    for (auto& x : A){
        cout << endl << endl << x << endl;
        x = x - avg;
        cout << x << endl;
    }
    ll hi_sum = 0,lo_sum = 0;
    for (auto x : A){
        if (x > 0){
            hi_sum += x;
        }else{
            lo_sum += x;
        }
    }
    cout << hi_sum << endl << lo_sum << endl;
}
int main(){
    int N;
    cin >> N;

    vector<ll> A(N);
    for (int i=0;i<N;i++){
        cin >> A[i];
    }

    ll sum = 0;
    for (auto x : A){
        sum += x;
    }
    double avg = sum / N;
    // avg = round(avg);

    for (auto& x : A){
        x = x - avg;
    }

    ll hi_sum = 0,lo_sum = 0;
    for (auto x : A){
        if (x > 0){
            hi_sum += x+1;
        }else{
            lo_sum += x;
        }
    }
cout << hi_sum << endl << lo_sum << endl;
    if (hi_sum < abs(lo_sum)){
        cout << hi_sum << endl;
    }else{
        cout << abs(lo_sum) << endl;
    }
    return 0;
}