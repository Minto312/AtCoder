#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int search_min_idx(ll (&num)[3]){
    int min_idx = 0;
    for (int i=1; i<3; i++){
        if (num[i] < num[min_idx]){
            min_idx = i;
        }
    }
    return min_idx;
}

void increment(ll (&num)[3]){
    int idx = search_min_idx(num);
    if (num[0] == num[1] && num[1] == num[2]){
        num[1] = 1;
        num[2] = 1;
    }else if (num[1] == num[2]){
        num[2] = 1;
    }
    num[idx] = num[idx] * 10 + 1;
}

int main(){
    int N;
    cin >> N;

    ll num[3] = {1, 1, 1};
    for (int i=1; i<N; i++){
        increment(num);
        ll sum = 0;
        cout << num[0] << " " << num[1] << " " << num[2] << endl;
        for (int i=0; i<3; i++){
            sum += num[i];
        }
        cout << i << "  " << sum << endl;
    }
    
    ll sum = 0;
    for (int i=0; i<3; i++){
        sum += num[i];
    }
    cout << sum << endl;
    return 0;
}