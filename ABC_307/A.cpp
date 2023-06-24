#include <bits/stdc++.h>
using namespace std;
#define vv vector<vector

int main(){
    int N;
    cin >> N;

    for (int i=0;i<N;i++){
        int sum = 0;
        for (int j=0;j<7;j++){
            int val;
            cin >> val;
            sum += val;
        }
        cout << sum << " ";
    }
    return 0;
}