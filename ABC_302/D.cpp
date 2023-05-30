#include <bits/stdc++.h>
using namespace std;
#define rep(i,s,e) for(int i = s;i < e;i++)
#define all(obj) obj.begin(),obj.end()

int main(){
    cin.tie(0)->sync_with_stdio(0);

    long long A_N,B_N,dist;
    cin >> A_N >> B_N >> dist;

    vector<long long> A(A_N),B(B_N);
    rep(i,0,A_N) cin >> A[i];
    rep(i,0,B_N) cin >> B[i];

    sort(all(A));
    sort(all(B));

    long long cur_max = -1,a_idx = A_N-1,b_idx = B_N-1;
    while(true){
        if (abs(A[a_idx] - B[b_idx]) <= dist){
            if (A[a_idx] + B[b_idx] > cur_max){
                cur_max = A[a_idx] + B[b_idx];
            // cout << A[a_idx] + B[b_idx] << endl;
            // return 0; 
            }
        }

        if (a_idx == 0 && b_idx == 0) break;

        if (a_idx == 0){
            b_idx--;
            continue;
        }else if (b_idx == 0){
            a_idx--;
            continue;
        }
        if (A[a_idx] > B[b_idx]){
            a_idx--;
        }else{
            b_idx--;
        }
    }
    cout << cur_max << endl;
    return 0;
}